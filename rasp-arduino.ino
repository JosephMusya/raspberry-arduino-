int my_led = 13;
String data;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}



void led() {
  delay(500);
  digitalWrite(my_led, 1);
  delay(250);
  digitalWrite(my_led, 0);
  delay(125);
}

void loop() {
  if (Serial.available()>0){
    data = Serial.readStringUntil('\n');
    if (data == "ON") {
      pinMode(my_led,1);
      Serial.write("Led Turned ON");
    }
    if (data == "OFF") {
      pinMode(my_led,0);
      Serial.write("Led Turned OFF");
    }

    else {
      Serial.write("Invalid Data");
      led();
    }    
  }
}
