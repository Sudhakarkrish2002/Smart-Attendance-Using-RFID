# IoT-Based Smart Attendance System Using RFID with NodeMCU ESP8266 and KiwisIoT

## 📌 Project Overview

The Smart Attendance System is an IoT-based project designed to automate student attendance using RFID technology.

The system uses an RFID RC522 reader to identify students through their unique RFID card IDs. The NodeMCU ESP8266 acts as the main controller, processes the card information and transmits attendance data to the KiwisIoT platform through Wi-Fi.

A green LED and buzzer provide visual and audio confirmation when an RFID card is scanned.

## ✨ Features

- Automated attendance recording using RFID.
- Unique student identification through RFID cards.
- Wi-Fi connectivity using NodeMCU ESP8266.
- Real-time attendance monitoring through KiwisIoT.
- Green LED indication for valid RFID cards.
- Buzzer notification for valid and invalid cards.
- Online IoT-based attendance monitoring.

## 🛠️ Hardware Requirements

| S.No | Component | Quantity |
|---|---|---|
| 1 | NodeMCU ESP8266 | 1 |
| 2 | RFID RC522 Reader | 1 |
| 3 | RFID Cards / Tags | 2 or more |
| 4 | Buzzer | 1 |
| 5 | Green LED | 1 |
| 6 | 220Ω Resistor | 1 |
| 7 | Breadboard | 1 |
| 8 | Jumper Wires | As required |
| 9 | USB Cable | 1 |

## 💻 Software Requirements

- Arduino IDE
- ESP8266 Board Package
- MFRC522 Library
- KiwisIoT Library
- KiwisIoT Platform
- Wi-Fi Network

## 🔌 Circuit Connections

### RFID RC522 to NodeMCU ESP8266

| RFID RC522 Pin | NodeMCU Pin |
|---|---|
| SDA / SS | D2 |
| SCK | D5 |
| MOSI | D7 |
| MISO | D6 |
| RST | D1 |
| 3.3V | 3V3 |
| GND | GND |

### Other Connections

| Component | NodeMCU Pin |
|---|---|
| Buzzer Positive | D0 (through suitable driver) |
| Buzzer Negative | GND |
| Green LED Positive | D8 through 220Ω resistor |
| Green LED Negative | GND |

**Note:** The RFID RC522 operates at 3.3V. Never connect its VCC to 5V.

## ⚙️ Working Principle

1. A student scans their RFID card using the RC522 reader.
2. The RFID reader retrieves the unique card identification number (UID).
3. NodeMCU ESP8266 checks the UID against registered student details.
4. If the card is valid, the green LED turns ON and the buzzer provides confirmation.
5. If the card is invalid, the buzzer provides a warning sound.
6. The NodeMCU sends attendance information to the KiwisIoT platform through Wi-Fi.
7. Attendance information is displayed on the KiwisIoT dashboard.

## 🌐 KiwisIoT Platform Integration

The KiwisIoT platform provides an online interface for monitoring student attendance.

The NodeMCU ESP8266 communicates with the configured KiwisIoT device and transmits attendance telemetry through Wi-Fi.

### Dashboard Parameters

- Student Name
- Student ID
- RFID UID
- Attendance Status
- Date and Time
- Total Attendance Count

## 🚀 Installation and Setup

### Step 1: Install Arduino IDE

Download and install Arduino IDE.

### Step 2: Configure ESP8266

Install the ESP8266 board package through the Arduino IDE Boards Manager.

### Step 3: Install Required Libraries

Install the MFRC522 and KiwisIoT libraries.

### Step 4: Connect Hardware

Connect the RFID reader, buzzer and LED to NodeMCU according to the circuit connection table.

### Step 5: Configure Wi-Fi

Enter your Wi-Fi SSID and password in the Arduino program.

### Step 6: Configure KiwisIoT

Configure your KiwisIoT device and telemetry settings.

### Step 7: Upload the Program

Select **NodeMCU 1.0 (ESP-12E Module)** in Arduino IDE and upload the program.

### Step 8: Test the Project

Scan registered RFID cards and verify the attendance information on the KiwisIoT dashboard.

## 🎯 Applications

- Schools and Colleges
- Educational Institutions
- Training Centers
- Employee Attendance Monitoring
- Laboratories and Libraries
- Smart Campus Management

## ✅ Advantages

- Reduces manual attendance recording.
- Provides quick student identification.
- Simplifies attendance management.
- Enables online attendance monitoring.
- Cost-effective and easy to implement.
- Supports IoT-based data communication.

## 🔮 Future Enhancements

- Student database integration.
- Daily attendance report generation.
- Duplicate attendance prevention.
- Attendance percentage calculation.
- Cloud-based attendance history.
- Admin dashboard for attendance management.

## 📊 Technologies Used

| Technology | Purpose |
|---|---|
| NodeMCU ESP8266 | Main Controller |
| RFID RC522 | Student Identification |
| Embedded C / C++ | Programming |
| Arduino IDE | Development Environment |
| Wi-Fi | Wireless Communication |
| KiwisIoT | IoT Monitoring Platform |

## 📝 Conclusion

The IoT-Based Smart Attendance System using RFID, NodeMCU ESP8266 and KiwisIoT provides an automated solution for student attendance management.

By combining RFID identification, Wi-Fi connectivity and IoT monitoring, the project simplifies attendance recording and enables online attendance monitoring.

This project demonstrates the practical application of IoT technology in educational institutions and smart campus environments.
