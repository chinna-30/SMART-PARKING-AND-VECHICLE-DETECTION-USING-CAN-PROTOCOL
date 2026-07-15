# 🚗 Smart Parking Slot Monitoring and Vehicle Detection Using CAN Protocol

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

- Monitor parking slot availability.
- Display parking status in real time.
- Record vehicle entry and exit times.
- Automatically control the parking gate.
- Reduce human intervention.

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

## 🏗️ System Architecture

```text
                    Vehicle
                       │
                       ▼
                Entry IR Sensor
                       │
                       ▼
        +-----------------------------+
        |           NODE 2            |
        | LPC2129 + DS1307 RTC        |
        | Vehicle Detection & Slots   |
        +-------------+---------------+
                      |
                 ===== CAN BUS =====
                  /               \
                 /                 \
      +----------------+    +----------------+
      |     NODE 1     |    |     NODE 3     |
      |  LCD Display   |    | Servo Control  |
      +-------+--------+    +-------+--------+
              |                     |
              ▼                     ▼
          20×4 LCD            Parking Gate
                                     |
                                     ▼
                              Exit IR Sensor
```

---

## 📡 CAN Network Architecture

```text
+--------------------+
|      NODE 1        |
| LCD Display Module |
+---------+----------+
          |
========== CAN BUS ==========
          |
+---------+----------+
|      NODE 2        |
| RTC + IR Sensors   |
+---------+----------+
          |
========== CAN BUS ==========
          |
+---------+----------+
|      NODE 3        |
| Servo Gate Control |
+--------------------+
```

---

## ⚙ Hardware Components

| Component | Description |
|-----------|-------------|
| LPC2129 ARM7 | Main Controller |
| CAN Transceiver | CAN Communication |
| DS1307 RTC | Time Logging |
| SG90 Servo Motor | Gate Control |
| IR Sensor (Entry) | Vehicle Detection |
| IR Sensor (Exit) | Vehicle Detection |
| 20×4 LCD | Status Display |

---

## 💻 Software Used

- Embedded C
- Keil μVision
- Proteus Design Suite
- Flash Magic

---

## 👨‍💻 Author

**Chinnadurai V**

Embedded Systems Engineer

📧 chinnaduraivajjiram@gmail.com

GitHub: https://github.com/chinna-30/SMART-PARKING-AND-VECHICLE-DETECTION-USING-CAN-PROTOCOL

LinkedIn: https://www.linkedin.com/in/chinnadurai-v-9918783b7/

---

⭐ If you found this project useful, please give it a star on GitHub.
