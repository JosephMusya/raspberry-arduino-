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
  }
  else if ((data) == "OFF"){
    digitalWrite(my_led, LOW);
  }
  else {
    led();
    led();
    led();
  }
}

void led() {
  digitalWrite(my_led, 1);
  delay(25);
  digitalWrite(my_led, 0);
  delay(25);
}
