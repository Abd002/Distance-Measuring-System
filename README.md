## Distance Measurement System

This repository contains the implementation of a distance measurement system using the HC-SR04 ultrasonic sensor with the following specifications:

### System Requirements

1. **Microcontroller:** Utilizes the ATmega32 Microcontroller with a frequency of 8MHz.

2. **Ultrasonic Sensor:** Measures distance using the HC-SR04 ultrasonic sensor. Refer to the "HC-SR04 Ultrasonic MT Student Tutorial" PDF file for interfacing details.

3. **LCD Display:** Displays the measured distance value.

### Project Design

The project is designed and implemented based on the layered architecture model as follows:

### GPIO Driver Requirements

- Utilizes the GPIO driver implemented in the course.

### ICU Driver Requirements

- Utilizes the ICU driver implemented in the course.
- Configures ICU with frequency F_CPU/8 and detects the rising edge as the first edge.
- `ICU_init` and `ICU_setCallBack` functions are called inside the `Ultrasonic_init` function.

### LCD Driver Requirements

- Utilizes a 4x16 LCD.
- Utilizes the LCD driver implemented in the course with 8-bits data mode.
- Connects the LCD control pins and data bus as follows:
  - RS → PB0
  - RW → Ground
  - E → PB1
  - Data Bus → all PORTA pins.

### Ultrasonic Driver Requirements

- Implements a full ultrasonic driver using the ATmega32 ICU driver.
- Functions:
  - `void Ultrasonic_init(void)`: Initializes the ICU driver, sets up the callback function, and configures the trigger pin direction.
  - `void Ultrasonic_Trigger(void)`: Sends the trigger pulse to the ultrasonic sensor.
  - `uint16 Ultrasonic_readDistance(void)`: Sends the trigger pulse and starts measurements using the ICU. Returns the measured distance in centimeters.
  - `void Ultrasonic_edgeProcessing(void)`: Callback function called by the ICU driver to calculate the pulse time generated by the ultrasonic sensor.

### Project Hardware Connections

Please refer to the hardware connections specified in the code documentation.

### Thanks and Good Luck

Eng / Mohamed Tarek
