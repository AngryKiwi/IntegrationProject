import RPi.GPIO as GPIO          
from time import sleep

in1 = 19
in2 = 13
en = 26
en2 = 22 
in3 = 27
in4 = 17 


GPIO.setmode(GPIO.BCM)
GPIO.setup(in1,GPIO.OUT)
GPIO.setup(in2,GPIO.OUT)
GPIO.setup(in3, GPIO.OUT)
GPIO.setup(in4, GPIO.OUT)
GPIO.setup(en,GPIO.OUT)
GPIO.setup(en2, GPIO.OUT)
GPIO.output(in1,GPIO.LOW)
GPIO.output(in2,GPIO.LOW)
GPIO.output(in3, GPIO.LOW)
GPIO.output(in4, GPIO.LOW)
pwm=GPIO.PWM(en,1000)
pwm2=GPIO.PWM(en2,1000)

pwm.start(25)
pwm2.start(25)
print("\n")
print("s-stop f-forward b-backward tlf - turnleftforward trf - turnrightforward l-low m-medium h-high e-exit")
print("\n")    

while(1):

    x=raw_input()
    
    if x=='s':
        print("stop")
        GPIO.output(in1,GPIO.LOW)
	GPIO.output(in2,GPIO.LOW)
        GPIO.output(in3,GPIO.LOW)
	GPIO.output(in4,GPIO.LOW)


    elif x=='f':
        print("forward")
        GPIO.output(in1,GPIO.HIGH)
        GPIO.output(in2,GPIO.LOW)
	GPIO.output(in3,GPIO.HIGH)
	GPIO.output(in4,GPIO.LOW)
       

    elif x=='b':
        print("backward")
        GPIO.output(in1,GPIO.LOW)
        GPIO.output(in2,GPIO.HIGH)
	GPIO.output(in3,GPIO.LOW)
	GPIO.output(in4,GPIO.HIGH)
        
    elif x == 'tlf':
	GPIO.output(in1,GPIO.LOW)
	GPIO.output(in2,GPIO.LOW)
	GPIO.output(in3,GPIO.HIGH)
	GPIO.output(in4,GPIO.LOW) 
    elif x == 'trf':
	GPIO.output(in1, GPIO.HIGH)
	GPIO.output(in2, GPIO.LOW)
	GPIO.output(in3, GPIO.LOW)
	GPIO.output(in4, GPIO.LOW)
    elif x=='l':
        print("low")
        pwm.ChangeDutyCycle(30)
       	pwm2.ChangeDutyCycle(30)

    elif x=='m':
        print("medium")
        pwm.ChangeDutyCycle(50)
        pwm2.ChangeDutyCycle(50)

    elif x=='h':
        print("high")
        pwm.ChangeDutyCycle(80)
       	pwm2.ChangeDutyCycle(80)
     
    
    elif x=='e':
        GPIO.cleanup()
        print("GPIO Clean up")
        break
    
    else:
        print(" wrong input")
        
