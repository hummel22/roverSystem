##List of Commands
####Operator --> Rover
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
|---   |---   |x/x/x/|Speed/Turn/Pan/Tilt|



####Rover --> Operator
|ID|Sub|Sub|Items|
|:----:|:----:|:----:|:------------------------------:|
|0     |      |      |Ping Operator|
|1     |      |      |Send Servo Attributes|
|---   |ID#   |      |Servo Number|
|---   |---   |ULFC  |Upper/Lower/Filter/Center|
|2     |      |      |Motor Attributes|
|---   |/1/2/3|      |FR-FL-MR-ML-BR-ML|
|3     |      |      |Current Servo Values|
|---   |1/2/x |      |Values order by Servo ID|
|33    |      |      |Reset Header|
|40    |      |      |Arduino Info|
|50    |      |      |GPS Sensor Info|
|99    |      |      |Misc Messages|
