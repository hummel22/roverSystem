##List of Commands
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
