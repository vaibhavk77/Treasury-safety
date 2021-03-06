//This code controls the various inputs and outputs of Arduino Board like LED, Sensor and Electronic Lock.

int led = 13;                // the pin that the LED is attached to
int sensor = 2;              // the pin that the sensor is attached to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
int pinno = 7;
void setup() {
  pinMode(led, OUTPUT);   
  pinMode(pinno, OUTPUT); // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}
void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
    
  } 
  else if(Serial.available()){
      char inByte = Serial.read();
      
      digitalWrite(pinno , HIGH);
      delay(1000);
      //Serial.println(inByte);
    }
  else {
      digitalWrite(led, LOW);
      digitalWrite(pinno , LOW);// turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW     }}}
