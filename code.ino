#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <KiwisIoT.h>

// WiFi Credentials
const char* ssid = "Robots";
const char* pass = "12345678";

// KiwisIoT Panel Topic ID
const char* topic = "dash_1795435699573";

// RFID Pins
#define SS_PIN D2
#define RST_PIN D1

// Output Pins
#define BUZZER_PIN D0
#define LED_PIN D8

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

KiwisIoT kiwisiot(ssid, pass, topic);

// Registered student UIDs
String student1UID = "9C 92 12 07";
String student2UID = "8E 22 14 07";

// Attendance state (false = ABSENT, true = PRESENT)
bool student1Present = false;
bool student2Present = false;

unsigned long lastScan = 0;
bool scannedBefore = false;

// Read RFID UID
String readCardUID() {
  String uid = "";

  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      uid += "0";
    }

    uid += String(rfid.uid.uidByte[i], HEX);

    if (i < rfid.uid.size - 1) {
      uid += " ";
    }
  }

  uid.toUpperCase();
  return uid;
}

// Send attendance to KiwisIoT
void sendAttendance(String uid, String name, String status) {

  kiwisiot.send("0", uid);
  kiwisiot.send("1", name);
  kiwisiot.send("2", status);

  Serial.println("KiwisIoT Data Sent");
}

// Valid attendance (toggle PRESENT / ABSENT)
void validAttendance(String name, String uid, bool &present) {

  present = !present;
  String status = present ? "PRESENT" : "ABSENT";

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(name);
  lcd.setCursor(0, 1);
  lcd.print(status);

  if (present) {
    // PRESENT: LED on + single short beep
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(150);
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    // ABSENT: double beep, LED off
    for (int i = 0; i < 2; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
      delay(100);
    }
  }

  sendAttendance(uid, name, status);

  delay(400);
  digitalWrite(LED_PIN, LOW);
}

// Invalid card
void invalidAttendance(String uid) {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Invalid Card");
  lcd.setCursor(0, 1);
  lcd.print("Access Denied");

  digitalWrite(BUZZER_PIN, HIGH);
  delay(600);
  digitalWrite(BUZZER_PIN, LOW);

  sendAttendance(uid, "UNKNOWN", "INVALID");
}

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  // LCD
  Wire.begin(D3, D4);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Attendance");
  lcd.setCursor(0, 1);
  lcd.print("Connecting...");

  // RFID
  SPI.begin();
  rfid.PCD_Init();

  // KiwisIoT
  kiwisiot.begin();

  lcd.clear();
  lcd.print("Scan Your Card");

  Serial.println("Smart Attendance Started");
}

void loop() {

  kiwisiot.run();

  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  String uid = readCardUID();

  Serial.print("RFID UID: ");
  Serial.println(uid);

  if (scannedBefore && millis() - lastScan < 3000) {
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
    return;
  }

  lastScan = millis();
  scannedBefore = true;

  if (uid == student1UID) {

    validAttendance("Rahul", uid, student1Present);

  }
  else if (uid == student2UID) {

    validAttendance("Arun", uid, student2Present);

  }
  else {

    invalidAttendance(uid);

  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  lcd.clear();
  lcd.print("Scan Your Card");
}
