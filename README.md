# Rover Operating System

### Overview

### 3 systems
* Operator program  - User control software
* Rover system - Mster Rover Program
* Arduino - Arduino Mega

### Communications System

##### Overview
This system is designed to communicate between operator and rover using the UDP protocol. This system was chosen to limit latency.
Reliability of the communication is discussed below

#### Commands Table
Operator to Rover
* Run on Rover - (All others passed to arduino)

|ID|Sub|Sub|Items|
|:----:|:----:|:----:|:------------------------------:|
|1-20  |      |      |Servo Number|
|---   |Angle |      |Set Given Servo Angle|
|*21   |      |      |Check Arduino Connection|
|*22   |      |      |Answering Ping|
|*23   |      |      |Switch Protocol (UDP/TCP)|
|*24   |      |      ||
|*25   |      |      |Reset Arduino|
|*26   |      |      |Set new Header Count|
|---   |0-9999|      |New Head Count|
|*27   |      |      |Set Shutdown Limit|
|---   |0-9999|      |New Shut Down limit|
|*28   |      |      ||
|*29   |      |      ||
|30    |      |      |Force Servo Sync|
|---   |x/x/x/|      |All Servo angles to set|
|31    |      |      |Set Upper/Lower Bounds of Servos|
|---   |ID #  |      |Servo ID number to set|
|---   |---   |U/L #s|Upper and Lower limts|
|32    |      |      |Set Filter|
|---   |ID #  |      |Servo ID number|
|---   |---   |Filter|Set Filter|
|33    |      |      |Request Limits U/L filter|
|34    |      |      |Set Loop Delay|
|---   |0-9999|      |Microseconds|
|35    |      |      |Drive Max|
|---   |0-255 |      |Set Drive Control Max|
|40    |      |      |Arm Control|
|---   |15    |      |Check|
|---   |---   |x/x/x/|All Angles - Arm|
|41    |      |      |Motor Control|
|---   |15    |      |Check - Bug|
|---   |---   |x/x/x/|Speed/Turn/Pan/Tilt|






## Operator Program

The Operator program is built using the Qt developer.

#### Overview
* Send/Recieve to rover
* Update remote location with IP address 
* Show video stream
* Allow user input (Joystick/GUI/keyboard)
* Display rover postion graphically
* Calculate necessary angles



## Rover Program

Rover Program is created using c++ and designed for a unix enviroment. This program is used on the rovers onboard computer

#### Overview
* Establish connection (pull IP address of operator)
* Receive/Send from rover
* Receive/Send from arduino
* Control camera video streams
* Pass parameters from operator to arduino and vice versa
* Monitor systems and reset if needed



## Arduino

The arduino will interact will hardware and motors. It will take commands and control servos as well motors. 
It also receives data from sensors and passes it to the onboard computer.

#### Overview
* Receive/Send data to rover
* Interact with sensors/motors/servos
* PWM signal to control servos
* Varibale 0-4V signal for motor controllers

#### Items to connect
* 6 Robotic Arm Servos
* 4 Drive Servos
* 2 Pand/Tilt Servos
* 6 Motor Control - Speed
* 6 Motor Control - Direction
* 1 Motor Control - Break
* 6 Acceleramotor inputs
* 1 GPS
* 1 Current Sensor
* 1 Voltage Sensor

#### Pin Setup
| Pin | Item || Pin | Item || Pin | Item |
|:----:|:--------------:|:-:|:----:|:--------------:|:-:|:----:|:--------------:|
|2| Base Servo  ||21|  ||40|  |
|3| Shoulder    ||22| FL - Speed    ||41|  |
|4| Elbow       ||23| FR - Speed    ||42|  |
|5| Wrist       ||24| ML - Speed    ||43|  |
|6| Wrist Rotate||25| MR - Speed    ||45|  |
|7| Claw        ||26| BL - Speed    ||A0| X-Axis  |
|8| Pan         ||27| BR - Speed    ||A1| Y-Axis |
|9| Tilt        ||28| FL - Direction||A2| Z-Axis |
|10| FL - Servo ||29| FR - Direction||A3| Current Sensor |
|11| FR - Servo ||30| ML - Direction||A4| Voltage Sensor |
|12| BL - Servo ||31| MR - Direction||A5|  |
|13| BR - Servo ||32| BL  -Direction||A6|  |
|14| ||33| BR - Direction||A7|  |
|15| ||34|  ||A8|  |
|16| ||35|  ||A9|  |
|17| ||36|  ||A10|  |
|18| ||37|  ||A11|  |
|19| ||38|  ||A12|  |
|20| ||39|  ||A13|  |



####ChangeLog
Next
* Communication Commands to README

V1.1.4
* Added Command Table
V1.1.3
* Added Pin Table

V1.1.2
* Changes Angles to microseconds to GUI

V1.1.1
* Changed from angles to micro second in arduino
* * Need to do same to GUI

