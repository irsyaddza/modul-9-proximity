# 📡 IMPLEMENTASI SENSOR PROXIMITY PADA ARDUINO UNO
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![Sensors](https://img.shields.io/badge/Sensor-Proximity-orange?style=for-the-badge)
![Versi](https://img.shields.io/badge/Versi-1.0-green?style=for-the-badge)

## 📋 Gambaran Proyek
Sistem berbasis Arduino yang memanfaatkan sensor proximity untuk mendeteksi objek di sekitar. Memberikan umpan balik visual, audio, dan pemantauan serial. Memiliki beragam mode operasi yang dikendalikan melalui satu tombol tekan.

### 🔧 Komponen yang Digunakan
- Board Arduino
- Sensor Proximity (Analog)
- Layar LCD (I2C)
- Push button
- LED
- Buzzer

## 🎯 Mode Operasi

### Mode 1: Pemantauan Proximity 📊
```plaintext
[Tekan Tombol #1]
```
- Mengaktifkan sensor proximity
- Menampilkan jarak di LCD
- Mengeluarkan data sensor ke serial monitor
- Format: "Proximity: XXX cm"

### Mode 2: Peringatan Jarak 🚨
```plaintext
[Tekan Tombol #2]
```
- Memantau proximity dengan ambang batas
- Mengaktifkan buzzer saat melewati ambang
- Menampilkan peringatan di LCD dan serial
- Cocok untuk keamanan/otomatisasi

### Mode 3: Visualisasi LED 💡
```plaintext
[Tekan Tombol #3]
```
- LED redup berdasarkan proximity
- Intensitas sesuai keluaran sensor
- Pemantauan LCD dan serial aktif
- Representasi visual proximity

### Mode 4: Reset Sistem 🔄
```plaintext
[Tekan Tombol #4]
```
- Kembali ke Mode 1
- Mereset semua keluaran
- Siap untuk siklus baru

## 🔌 Konfigurasi Pin

| Komponen | Pin |
| --- | --- |
| LCD I2C (SDA) | A4 |
| LCD I2C (SCL) | A5 |
| Buzzer | 8 |
| LED | 7 |
| Sensor Proximity | A0 |
| Push button | 2 |

### Software
1. **Library yang Diperlukan**
   ```cpp
   #include <Wire.h>
   #include <LiquidCrystal_I2C.h>
   ```

## 📊 Detail Mode

### Mode 1: Pemantauan
- Pengukuran proximity kontinu
- Refresh rate: 500ms
- Format LCD: "Proximity: XXX cm"
- Output serial: "Proximity: XXX cm"

### Mode 2: Peringatan
- Ambang batas default: 20cm
- Pola buzzer: Terus-menerus
- Pesan peringatan di LCD
- Log kejadian di serial

### Mode 3: Visualisasi LED
- Pemetaan PWM: 0-255
- Hubungan terbalik dengan proximity
- Efek redup halus
- Tampilan jarak real-time
