#***Before using this example the motor/controller combination must be
#***tuned and the settings saved to the Roboclaw using IonMotion.
#***The Min and Max Positions must be at least 0 and 50000

import time
from roboclaw import Roboclaw

#Linux comport name
rc = Roboclaw("/dev/ttyS0",38400)

def displayspeed():
	enc1 = rc.ReadEncM1(frontMotorAddress)
	enc2 = rc.ReadEncM2(frontMotorAddress)
	enc3 = rc.ReadEncM1(backMotorAddress)
	enc4 = rc.ReadEncM2(backMotorAddress)

	speed1 = rc.ReadSpeedM1(frontMotorAddress)
	speed2 = rc.ReadSpeedM2(frontMotorAddress)
	speed3 = rc.ReadSpeedM1(backMotorAddress)
	speed4 = rc.ReadSpeedM2(backMotorAddress)


	print("Encoder1:"),
	if(enc1[0]==1):
		print enc1[1],
		print format(enc1[2],'02x'),
	else:
		print "failed",
	print "Encoder2:",
	if(enc2[0]==1):
		print enc2[1],
		print format(enc2[2],'02x'),
	else:
		print "failed " ,
        print("Encoder3:"),
	if(enc3[0]==1):
		print enc3[1],
		print format(enc3[2],'02x'),
	else:
		print "failed",
	print "Encoder4:",
	if(enc4[0]==1):
		print enc4[1],
		print format(enc4[2],'02x'),
	else:
		print "failed " ,
	print "Speed1:",
	if(speed1[0]):
		print speed1[1],
	else:
		print "failed",
	print("Speed2:"),
	if(speed2[0]):
		print speed2[1]
	else:
		print "failed " ,
        print "Speed3:",
	if(speed3[0]):
		print speed3[1],
	else:
		print "failed",
	print("Speed4:"),
	if(speed4[0]):
		print speed4[1]
	else:
		print "failed "

rc.Open()
frontMotorAddress = 0x80
backMotorAddress = 0x81
speed = 1250

version = rc.ReadVersion(frontMotorAddress)
version = rc.ReadVersion(backMotorAddress)

if version[0]==False:
	print "GETVERSION Failed"
else:
	print repr(version[1])

while(1):

        command = raw_input("Enter Command: ")
        forward = "w"
        backward = "s"
        slideLeft = "a"
        slideRight = "d" 
        quit = "q" 
        increaseSpeed = "r"
	decreaseSpeed = "f"
	speedDisplay = "p"

	if(command == increaseSpeed):
	 speed += (speed * .25)
	 speed = int(speed)
	 print(speed)
	 if(speed > 6000):
          speed = 6000

	if(command == decreaseSpeed):
	 speed -= (speed * .25)
	 speed = int(speed)
	 print(speed)
	 if(speed = 0):
          speed = 50

	if(command == speedDisplay):
	 for i in range(0,200):
	  displayspeed()
	  time.sleep(0.01)

	if(command == forward):
	 rc.SpeedAccelM1(frontMotorAddress,speed,speed)
	 rc.SpeedAccelM2(frontMotorAddress, speed ,speed)
	 rc.SpeedAccelM1(backMotorAddress, speed ,speed)
	 rc.SpeedAccelM2(backMotorAddress, speed ,speed)
	 time.sleep(0.01)

	if(command == backward):
	 rc.SpeedAccelM1(frontMotorAddress,speed,-speed)
	 rc.SpeedAccelM2(frontMotorAddress, speed ,-speed)
	 rc.SpeedAccelM1(backMotorAddress, speed ,-speed)
	 rc.SpeedAccelM2(backMotorAddress, speed ,-speed)
	 time.sleep(0.01)

	if(command == slideLeft):
	 rc.SpeedAccelM1(frontMotorAddress, speed, speed)
	 rc.SpeedAccelM2(frontMotorAddress, speed, -speed)
	 rc.SpeedAccelM1(backMotorAddress, speed, speed)
	 rc.SpeedAccelM2(backMotorAddress, speed,-speed)
	 time.sleep(0.01)

	if(command == slideRight):
	 rc.SpeedAccelM1(frontMotorAddress, speed, -speed)
	 rc.SpeedAccelM2(frontMotorAddress, speed, speed)
	 rc.SpeedAccelM1(backMotorAddress, speed, -speed)
	 rc.SpeedAccelM2(backMotorAddress, speed,speed)
	 time.sleep(0.01)

	if(command == quit):
	 rc.SpeedAccelM1(frontMotorAddress, speed, 0)
	 rc.SpeedAccelM2(frontMotorAddress, speed, 0)
	 rc.SpeedAccelM1(backMotorAddress, speed, 0)
	 rc.SpeedAccelM2(backMotorAddress, speed, 0)
	 time.sleep(0.01)


  
  
