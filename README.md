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
|Command |Items|
|---------|:---------:|

###### 


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
* 6 AcceleramotorOne inputs
* 1 GPS
* 1 Current Sensor
* 1 Voltage Sensor


#### Pin Setup
| Pin | Item |
|:----:|:----------:|
|2| Base Servo |
|3| Shoulder |
|4| Elbow |
|5| Wrist |
|6| Wrist Rotate |
|7| Claw |
|8| Pan |
|9| Tilt |
|10| FL - Servo |
|11| FR - Servo |
|12| BL - Servo |
|13| BR - Servo |
|22| FL Speed |
|23| FR Speed |
|24| ML Speed
|25| MR Speed|
|26| BL Speed|
|27| BR Speed|
|28| FL Direction|
|29| FR Direction|
|30| ML Direction|
|31| MR Direction|
|32| BL Direction|
|33| BR Direction|
|34| Motor Break|




s
####ChangeLog
Next
* Communication Commands to README

V1.1.2
* Changes Angles to microseconds to GUI

V1.1.1
* Changed from angles to micro second in arduino
* * Need to do same to GUI

