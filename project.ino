#define trigPin 12 // define the pins of your sensor
#define echoPin 13 
#define m1_left 8
#define m1_right 7
#define m2_left 9
#define m2_right 10

void setup() {
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  Serial.begin(9600);
}
 
void loop() {
   long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  Serial.println(distance);
  
  if (distance < 20)
  {
    Serial.println("Turning!");
    left();
    
  }
  else {
    Serial.println("All Good, moving Forward!");
    forward();
  }  
}


void forward()
{
  digitalWrite(m1_left,HIGH);
  digitalWrite(m1_right,LOW);
  digitalWrite(m2_left,HIGH);
  digitalWrite(m2_right,LOW);
}

void left()
{
  digitalWrite(m1_left,LOW);
  digitalWrite(m1_right,LOW);
  digitalWrite(m2_left,HIGH);
  digitalWrite(m2_right,LOW);
}

