# 🚗 Smart Parking Slot Monitoring and Vehicle Detection Using CAN Protocol

![Embedded C](https://img.shields.io/badge/Language-Embedded%20C-blue?style=for-the-badge)
![LPC2129](https://img.shields.io/badge/Microcontroller-LPC2129-green?style=for-the-badge)
![CAN Protocol](https://img.shields.io/badge/Communication-CAN-orange?style=for-the-badge)
![Keil](https://img.shields.io/badge/IDE-Keil%20uVision-red?style=for-the-badge)
![Proteus](https://img.shields.io/badge/Simulation-Proteus-purple?style=for-the-badge)
![Status](https://img.shields.io/badge/Project-Completed-success?style=for-the-badge)

---

## 📖 Project Overview

**Smart Parking Slot Monitoring and Vehicle Detection Using CAN Protocol** is an embedded systems project designed to automate vehicle entry, exit, parking slot monitoring, and access control.

The system reduces manual intervention by using **distributed CAN nodes** that communicate in real time to monitor parking slot availability and control the parking gate.

The project is developed using the **LPC2129 ARM7 Microcontroller** and the **Controller Area Network (CAN) Protocol**, enabling reliable and efficient communication between multiple embedded nodes.

---

## ❗ Problem Statement

In conventional parking systems, identifying vacant parking slots and maintaining parking records require significant human effort.

During peak hours, especially in crowded places such as:

- 🛕 Temples
- 🛍 Shopping Malls
- 🏥 Hospitals
- ✈ Airports
- 🏢 Office Complexes

vehicles often create congestion due to the absence of an intelligent parking management system.

### Challenges

- Difficulty in identifying available parking spaces.
- Increased traffic congestion inside parking areas.
- Delays during vehicle entry and exit.
- No automatic record of entry and exit times.
- Increased manpower requirements.

---

## 🎯 Need for the Project

Large public places experience heavy vehicle traffic every day. Without proper parking management:

- Drivers spend considerable time searching for vacant parking spaces.
- Vehicles create unnecessary congestion.
- Parking staff face difficulties in monitoring parking occupancy.
- Manual record maintenance is time-consuming and error-prone.

This project provides an automated solution that:

- Monitors parking slot availability.
- Displays parking status in real time.
- Records vehicle entry and exit times.
- Automatically controls the parking gate.
- Reduces human intervention.

---

## 🎯 Project Objectives

- Automate vehicle entry and exit.
- Monitor available parking slots in real time.
- Display parking information on a 20×4 LCD.
- Record entry and exit time using the DS1307 RTC.
- Automatically control the parking gate using an SG90 Servo Motor.
- Enable communication between distributed nodes using CAN.
- Reduce traffic congestion and manual effort.

---

# 🏗 System Architecture

## Block Diagram
## Block Diagram

┌──────────────────────────────────────────────────────────────────────────────┐
│          SMART PARKING SLOT MONITORING AND VEHICLE DETECTION                 │
│                      USING CAN PROTOCOL (LPC2129)                            │
└──────────────────────────────────────────────────────────────────────────────┘

                             Vehicle Arrives
                                    │
                                    ▼
                         ┌────────────────────┐
                         │  Entry IR Sensor   │
                         └─────────┬──────────┘
                                   │
                                   ▼
                 ┌─────────────────────────────────┐
                 │            NODE 2               │
                 │         LPC2129 ARM7            │
                 │                                 │
                 │ • Vehicle Detection             │
                 │ • Entry/Exit Monitoring         │
                 │ • Slot Count Management         │
                 │ • DS1307 RTC Interface          │
                 └──────────────┬──────────────────┘
                                │
                    CAN BUS Communication
          ┌─────────────────────┴─────────────────────┐
          │                                           │
          ▼                                           ▼
┌───────────────────────────┐              ┌─────────────────────────┐
│          NODE 1           │              │         NODE 3          │
│       LPC2129 ARM7        │              │      LPC2129 ARM7       │
│                           │              │                         │
│ • Receives CAN Messages   │              │ • Receives CAN Data     │
│ • Displays Slot Status    │              │ • Controls SG90 Servo   │
│ • Shows Entry/Exit Time   │              │ • Opens/Closes Gate     │
│ • Parking Full Alert      │              │                         │
└──────────────┬────────────┘              └──────────┬──────────────┘
               │                                      │
               ▼                                      ▼
      ┌─────────────────┐                    ┌─────────────────┐
      │   20×4 LCD      │                    │  SG90 Servo     │
      │ Parking Status  │                    │ Parking Gate    │
      └─────────────────┘                    └────────┬────────┘
                                                      │
                                                      ▼
                                             ┌────────────────┐
                                             │ Exit IR Sensor │
                                             └────────────────┘

```
---

# 📡 CAN Network Architecture

```
          +--------------------+
          |      NODE 1        |
          | LCD Display Module |
          +---------+----------+
                    |
                    |
==================== CAN BUS ====================
                    |
                    |
          +---------+----------+
          |      NODE 2        |
          | RTC + IR Sensors   |
          +---------+----------+
                    |
                    |
==================== CAN BUS ====================
                    |
                    |
          +---------+----------+
          |      NODE 3        |
          | Servo Gate Control |
          +--------------------+
```

---

# 🔄 Project Workflow

```
Power ON
    │
    ▼
Initialize LPC2129
    │
    ▼
Initialize CAN
    │
    ▼
Initialize RTC
    │
    ▼
Initialize LCD
    │
    ▼
Display Available Slots
    │
    ▼
Vehicle Arrives
    │
    ▼
Entry IR Detects Vehicle
    │
    ▼
Record Entry Time
    │
    ▼
Send CAN Message
    │
    ▼
Servo Opens Gate
    │
    ▼
Vehicle Enters
    │
    ▼
Decrease Slot Count
    │
    ▼
Update LCD
    │
    ▼
Parking Full?
 ┌──────┴───────┐
 │              │
Yes             No
 │              │
 ▼              │
Display         │
PARKING FULL    │
 │              │
 ▼              │
Wait for Exit ◄─┘
 │
 ▼
Exit IR Detects Vehicle
 │
 ▼
Record Exit Time
 │
 ▼
Increase Slot Count
 │
 ▼
Update LCD
 │
 ▼
Close Gate
```

---

# ⚙ Hardware Components

| Component | Description |
|-----------|-------------|
| LPC2129 ARM7 Microcontroller | Main controller |
| CAN Transceiver | CAN communication |
| DS1307 RTC | Entry & Exit Time |
| SG90 Servo Motor | Automatic Gate |
| IR Sensor (Entry) | Vehicle Detection |
| IR Sensor (Exit) | Vehicle Detection |
| 20×4 LCD | Status Display |

---

# 💻 Software Used

- Embedded C
- Keil μVision
- Proteus Design Suite
- Flash Magic

---

# ⚙ Node Description

## 🖥 Node 1 – Display Node

- Receives CAN messages.
- Displays parking slot information.
- Displays entry and exit status.
- Shows parking full indication.

---

## 🚗 Node 2 – Detection Node

- Detects vehicle entry.
- Detects vehicle exit.
- Reads DS1307 RTC.
- Updates parking slot count.
- Sends CAN messages.

---

## 🚪 Node 3 – Gate Controller

- Receives CAN messages.
- Controls SG90 Servo Motor.
- Opens parking gate.
- Closes parking gate.
- Prevents entry when parking is full.

---

# 🔄 Working Principle

### Step 1

System initialization.

LCD displays:

- Total Slots
- Available Slots
- Parking Status

---

### Step 2

Vehicle reaches entry.

- Entry IR detects vehicle.
- RTC records entry time.
- Node 2 sends CAN message.

---

### Step 3

Node 3 receives CAN data.

- Opens Servo Gate.
- Vehicle enters.

---

### Step 4

Gate closes.

Parking slot count decreases.

LCD updates.

---

### Step 5

Node 1 displays:

- Remaining Slots
- Parking Status
- Entry Confirmation

---

### Step 6

When all slots are occupied:

```
PARKING FULL
```

is displayed.

The gate remains closed.

---

### Step 7

Vehicle exits.

- Exit IR detects vehicle.
- RTC records exit time.
- Slot count increases.
- LCD updates.

---

# 📡 CAN Communication

This project uses the **Controller Area Network (CAN)** protocol for communication between distributed embedded nodes.

### Advantages

- High-speed communication
- Reliable data transfer
- Error detection
- Multi-node communication
- Reduced wiring complexity
- Industrial-grade reliability

---

# ✨ Features

- Automatic Vehicle Detection
- Automatic Gate Control
- Parking Slot Monitoring
- RTC-based Entry & Exit Logging
- LCD Status Display
- CAN-Based Communication
- Parking Full Alert
- Distributed Embedded Architecture

---

# ✅ Advantages

- Reduces manual work.
- Prevents parking congestion.
- Saves driver's time.
- Accurate parking records.
- Reliable CAN communication.
- Modular system architecture.
- Easily expandable.

---

# 🏢 Applications

- Shopping Malls
- Temples
- Airports
- Railway Stations
- Hospitals
- Office Campuses
- Educational Institutions
- Smart Parking Systems

---

# 🚀 Future Enhancements

- RFID-based Vehicle Authentication
- GSM/Wi-Fi Notifications
- Mobile Application
- Cloud Database
- Automatic Billing
- ANPR (Automatic Number Plate Recognition)
- Online Parking Reservation

---


---

# 👨‍💻 Author

**Chinnadurai V**

**Embedded Systems Engineer**

📧 Email: *chinnaduraivajjiram@gmail.com*

🔗 GitHub: https://github.com/chinna-30/SMART-PARKING-AND-VECHICLE-DETECTION-USING-CAN-PROTOCOL

🔗 LinkedIn: *https://www.linkedin.com/in/chinnadurai-v-9918783b7/*

---



If you found this project useful, please consider giving it a **⭐ Star** on GitHub.
