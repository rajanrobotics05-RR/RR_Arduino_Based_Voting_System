🗳️ Arduino-Based Electronic Voting Machine

An Embedded Systems Project by Rajan Robotics

"Arduino Voting System" (RR_Arduino_Based_Voting_System.png)

📌 Project Overview

This project demonstrates a simple Electronic Voting Machine (EVM) developed using an Arduino Uno, push-button switches and a 0.96-inch OLED display.

The system allows voters to select one of three candidates (A, B or C). Votes are counted by the Arduino and the results are displayed on the OLED screen.

A buzzer provides audio feedback during voting and reset operations.

✨ Features

- Three-candidate voting system (A, B and C)
- Push-button-based vote registration
- OLED display for voting messages
- Buzzer feedback for button operations
- Automatic vote counting
- Winner announcement
- Tie detection
- Reset option to start a new election

🔧 Components Required

S.No.| Component| Quantity
1| Arduino Uno| 1
2| OLED Display (SSD1306, 0.96")| 1
3| Push-button switches| 5
4| 10KΩ resistors| 5
5| Buzzer| 1
6| Breadboard| 1
7| Jumper wires| As required

🔌 Pin Connections

Component| Arduino Pin
Candidate A Button| D6
Candidate B Button| D5
Candidate C Button| D4
Result Button| D7
Reset Button| D3
Buzzer| D8
OLED SDA| A4
OLED SCL| A5
OLED VCC| 5V (if supported)
OLED GND| GND

Button Wiring

Each push button uses an external 10KΩ pull-down resistor.

- One switch terminal connects to 5V.
- The other switch terminal connects to the corresponding Arduino digital input.
- A 10KΩ resistor connects the input pin to GND.

The program uses "INPUT" mode and detects a pressed button as "HIGH".

💻 Software Requirements

- Arduino IDE
- Adafruit GFX Library
- Adafruit SSD1306 Library

Install the required libraries through:

Arduino IDE → Library Manager

Search and install:

1. Adafruit GFX Library
2. Adafruit SSD1306

⚙️ Working Principle

1. Switch on the Arduino-based voting machine.
2. The OLED displays the Rajan Robotics EVM welcome message.
3. The voter presses A, B or C to select a candidate.
4. The Arduino increments the corresponding vote count.
5. The buzzer provides feedback after a vote is registered.
6. Press the RESULT button to display the vote counts and announce the winner.
7. Press RESET to clear the counts and begin a new election.

📊 Result Calculation

The Arduino compares the vote counts of all three candidates.

- Candidate A wins when A has the highest votes.
- Candidate B wins when B has the highest votes.
- Candidate C wins when C has the highest votes.
- A tie is announced when two or more candidates have equal highest votes.

📂 Repository Structure

Arduino-Based-Electronic-Voting-Machine/
│
├── README.md
├── RR_Arduino_Voting_System.ino
│
└── images/
    └── RR_Arduino_Based_Voting_System.png

🎓 Learning Outcomes

This project helps students understand:

- Arduino digital input and output
- Push-button interfacing
- External pull-down resistors
- OLED display interfacing using I2C
- Basic embedded C++ programming
- Conditional statements and logical operations
- Vote counting and result calculation

🚀 Developed By

RAJAN ROBOTICS

Learning by Building. Building for the Future.

Robotics | Embedded Systems | Electronics | IoT | STEM Education

---

Note: This is an educational voting-machine prototype. It is not a certified or secure election system and should not be used for actual elections.
