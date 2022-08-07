int sensor_status = 0;
int random_val;
int led = 13;
String response;
String data;
bool system_status = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.readStringUntil('\r');
    if (data == "ONLINE") {
      system_status = true;
    }

    else if (data == "OFFLINE") {
      system_status = false;
    }
  }

  if (system_status) {
    start();
    delay(1000);
  }
  else {
    alert();
  }

  //Serial.println(random_val);

}
void alert(){
  digitalWrite(led,HIGH);
  delay(50);
  digitalWrite(led,LOW);
  delay(50);
}
void start() {
  random_val = random(0, 10);

  if (random_val > 8) {
    sensor_status = 1;
    stopConveyor();
    Serial.print(sensor_status);
    digitalWrite(led, HIGH);
  }
  else {
    moveConveyor();
    digitalWrite(led, LOW);
  }
}

void moveConveyor() {

}

void stopConveyor() {

}
