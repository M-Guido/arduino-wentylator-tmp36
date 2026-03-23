# Smart Arduino Fan System 🌡️🌬️


An automated cooling system project based on the Arduino Uno.

### 🛠️ Components Used:
* **Microcontroller:** Arduino Uno
* **Temperature Sensor:** TMP36
* **Motor Driver:** L298N
* **Display:** LCD 16x2
* **Motor:** DC Geared Motor (Yellow)

### 🚀 Functionality:
The system measures temperature in real-time. If the temperature exceeds **27°C**, the Arduino automatically triggers the fan. The current temperature and system status are displayed on the LCD screen.

### 🔌 Pin Connections:
* **LCD 16x2:** RS(12), E(11), D4(5), D5(4), D6(3), D7(2)
* **TMP36 Sensor:** Analog Pin A0
* **L298N Driver:** ENA(9), IN1(8), IN2(7)

### 💻 How to use:
1. Connect the components according to the pinout above.
2. Power the L298N driver and Arduino via USB or external power supply.
3. Upload the `.ino` sketch using Arduino IDE.
4. Monitor the temperature on the LCD or through the Serial Monitor.


<img width="972" height="2017" alt="IMG_4926" src="https://github.com/user-attachments/assets/f7d8c014-2a76-4809-b6d7-004aa57563cf" />
