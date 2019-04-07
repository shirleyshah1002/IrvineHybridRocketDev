/*
Changes made: Added new methods for second linear actuator
Added code for Step 0: Startup
*/

  
const int relay1 = 7;
const int relay2 = 6;
const int vcc = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(vcc, OUTPUT);
}
void extend1(){
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
}

void retract1(){
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
}
void extend2(){
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
}

void retract2(){
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
}

void stopactuator(){
  digitalWrite(vcc, LOW);
  delay(1000);
  digitalWrite(vcc, HIGH);
}

void middle(){
  extend1();
  extend2();
  delay(1000);
}

void loop() {
  //Input is in degrees
  //Convert the degrees to a linear length for actuator
  //Then convert that linear length into time for the delay
  //Determine if the input is regarding an angular change only in the
  //x-axis, y-axis, or z-axis
  //If x-axis then change only one actuator and use its corresponding relays
  //Else use the other relays

  digitalWrite(vcc, HIGH);
  extend();
  delay(2000);
  stopactuator();
  retract();
  delay(2000);
  stopactuator();
  middle();
  stopactuator();
  
  //Step 1: Startup
  //Linear actuators will be powered on, retract for a full 2 seconds (max retraction)
  //extend for 1 second (middle position). This will be considered the “zero” state
  retract1(); 
  retract2();
  delay(2000); 
  middle();


}
