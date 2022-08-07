int my_led = 13;
String data;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() == 0){
  }

  data = Serial.readStringUntil('\r');
  if ((data) == "ON"){
    digitalWrite(my_led, HIGH);
    Serial.println("1");
  }
  else if ((data) == "OFF"){
    digitalWrite(my_led, LOW);
    Serial.println("0");
  }
  else {
    Serial.write("X");
    alert();
  }
}
void startConveyor(){
  
}

void stopConveyor(){
  
}
void alert() {
  digitalWrite(my_led, 1);
  delay(25);
  digitalWrite(my_led, 0);
  delay(25);
  digitalWrite(my_led, 1);
  delay(25);
  digitalWrite(my_led, 0);
  delay(25);
  digitalWrite(my_led, 1);
  delay(25);
  digitalWrite(my_led, 0);
  delay(25);
}
