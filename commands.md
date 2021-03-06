##List of Commands
####Operator --> Rover
List of wanted commands
|ID|Sub|Sub|Items|
|:----:|:----:|:----:|:------------------------------:|
|1-20  |      |      |Servo Number|
|---   |Angle |      |Set Given Servo Angle|
|*21   |      |      |Check Arduino Connection|
|*22   |      |      |Answering Ping|
|*23   |      |      |Switch Protocol (UDP/TCP)|
|*24   |      |      |Check Camera Status|
|*25   |      |      ||
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
|---   |---   |U/L #s|Upper Lower filter Center|
|33    |      |      |Request U/L filter Center|
|---   |ID #  |      |Servo to Request|
|34    |      |      |Set Loop Delay|
|---   |0-9999|      |Microseconds|
|35    |      |      |Drive Max|
|---   |0-255 |      |Set Drive Control Max|
|40    |      |      |Arm Control|
|---   |15    |      |Check|
|---   |---   |x/x/x/|All Angles - Arm|
|41    |      |      |Motor Control|
|---   |15    |      |Check - Bug|
|---   |---   |x/x/x/|Turn/Pan/Tilt/Power/|

Acual Commands
|ID|Sub|Sub|Items|
|:----:|:----:|:----:|:------------------------------:|
|1-20  |      |      |Servo Number|
|---   |Angle |      |Set Given Servo Angle|
|*22   |      |      |Answering Ping|
|33    |      |      |Request 
|37    |      |      |Reset Arduino|
|40    |      |      |Arm Control|
|---   |15    |      |Check|
|---   |---   |x/x/x/|All Angles - Arm|
|41    |      |      |Motor Control|
|---   |15    |      |Check - Bug|
|---   |---   |x/x/x/|Turn/Pan/Tilt/Power/|
|50    |      |      |Storage to Ready|
|51    |      |      |Ready to Drive|
|52    |      |      |Drive to Ready|
|53    |      |      |X to Bin to Ready|
|60    |      |      |New Servo Value|
|---   |ID #  |      |Servo ID|
|---   |---   |x/x/x |Center/Radius/|

####Rover --> Operator
|ID|Sub|Sub|Items|
|:----:|:----:|:----:|:------------------------------:|
|4     |      |      |Ping Operator|
|1     |      |      |Send Servo Attributes|
|---   |ID#   |      |Servo Number|
|---   |---   |ULFC  |Upper/Lower/Filter/Center|
|2     |      |      |Motor Attributes|
|---   |/1/2/3|      |FR-FL-MR-ML-BR-ML|
|3     |      |      |Current Servo Values|
|---   |1/2/x |      |Values order by Servo ID|
|33    |      |      |Request U/L filter Center|
|---   |ID #  |      |Servo to Request|
|40    |      |      |Arduino Info|
|50    |      |      |GPS Sensor Info|
|99    |      |      |Misc Messages|



####Software ID #'s
Arduino is 1 Based Arrays
Servo Lists are 0 Based Arrays in GUI
Listing is for Arduino - All commands sent should you this list(Arduino 1 Based)

|ID # | Servo Name |
|:---:|:----------:|
|1    |Base        |
|2    |Shoulder    |
|3    |Elbow       |
|4    |Wrist Bend  |
|5    |Wrist Rotate|
|6    |Claw        |
|7    |Pan         |
|8    |Tilt        |
|9    |FL          |
|10   |FR          |
|11   |BL          |
|12   |BR          |
