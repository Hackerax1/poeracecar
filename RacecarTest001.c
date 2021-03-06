#pragma config(Sensor, in1,    lineFollower1,  sensorLineFollower)
#pragma config(Sensor, dgtl1,  startBump,      sensorTouch)
#pragma config(Sensor, dgtl9,  sonarInput1,    sensorSONAR_cm)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393_HBridge, openLoop, reversed, driveRight)
#pragma config(Motor,  port9,           lightServo,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393_HBridge, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task forward1(){
	startMotor(leftMotor, 60);
	startMotor(rightMotor, 60);}

task servoline (){
	setServo(lightServo, -35);
  wait(0.5);
	setServo(lightServo, -110);
	wait(0.5);
	setServo(lightServo, -35);
	wait(0.5);
	setServo(lightServo, 75);
	wait(0.5);}

task main()
{
  	setServo(lightServo, -35);
  	untilBump(startBump, 50);
  	startTask(forward1);
  	untilDark(2950, lineFollower1);
    stopMotor(leftMotor);
    stopMotor(rightMotor);
  	startTask(servoline);
  	untilLight(2750, lineFollower1);
  	stopMotor(lightServo);
  	getMotorEncoder(lightServo);
    radiansToDegrees(nMotorEncoder[lightServo]);
    if
  	untilSonarLessThan(15, sonarInput1);

  	wait(20);
  	stop();}
