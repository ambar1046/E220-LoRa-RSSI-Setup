# EBYTE E220-900T22D RSSI Configuration Guide

This guide explains how to **enable RSSI (Received Signal Strength Indicator)** on the **EBYTE E220-900T22D LoRa module** using **Configuration Mode (Mode 3)** and **SoftwareSerial (pins 8 & 9)**.

> ⚠️ Configuration mode does **not work reliably on hardware RX/TX**, so SoftwareSerial is required.

---

## Hardware Used
- EBYTE **E220-900T22D**
- Arduino (UNO / Nano / compatible)
- External antenna (recommended)

---

## UART Requirement (Important)
- **Baud rate:** 9600  
- **Data bits:** 8  
- **Parity:** None  
- **Stop bit:** 1  

> UART format is **fixed in configuration mode**

---

## Connections (Configuration Mode)

| E220 Pin | Arduino Pin | Description |
|--------|------------|------------|
| VCC | 5V / 3.3V | Power |
| GND | GND | Ground |
| TXD | **D8** | LoRa → Arduino |
| RXD | **D9** | Arduino → LoRa |
| M0 | HIGH | Configuration mode | 
| M1 | HIGH | Configuration mode |
| AUX | Not required | Optional status pin |

## For Arduino Nano Use 3.3V for M0 and M1 
---

## Enter Configuration Mode

1. Set **M0 = HIGH**
2. Set **M1 = HIGH**
3. Power ON or reset the module
4. Wait ~100–200 ms (or AUX = HIGH)

The module is now in **Mode 3 (Configuration Mode)**.

---

## Enable RSSI

Send the following commands via **SoftwareSerial (D8, D9)**.

### Enable RSSI Ambient Noise (REG1 – bit 5)

