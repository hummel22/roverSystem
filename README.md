# Rover Operating System

### Overview
This is Project is for the NASA Robo-Ops Competition 2014. This README outlines the 

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
[Documentation](commands.md)



## Operator Program

The Operator program is built using the Qt developer. This mainly a Graphic User interface that will allow
a user to control the rover. 

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

####Pin Table
[Documentation](pintable.md)



####ChangeLog

V1.1.4
* Added Command Table
V1.1.3
* Added Pin Table

V1.1.2
* Changes Angles to microseconds to GUI

V1.1.1
* Changed from angles to micro second in arduino
* * Need to do same to GUI

