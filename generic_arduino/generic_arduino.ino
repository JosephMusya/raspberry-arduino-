int sensor_status = 0;
int random_val;
int led = 13;
String response;
String data;
bool system_status = false;
bool sent = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    getData();
  }

  if (system_status) {
    start();
    delay(1000);
  }
  else {
    alert();
  }


}
void getData() {
  data = Serial.readStringUntil('\r');
  if (data == "ONLINE") {
    system_status = true;
  }

  else if (data == "OFFLINE") {
    system_status = false;
  }
}

void alert() {
  digitalWrite(led, HIGH);
  delay(50);
  digitalWrite(led, LOW);
  delay(50);
}
void start() {
  random_val = random(0, 10);
  if (random_val > 1) {
    sensor_status = 1;
    stopConveyor();
    
    if (!sent){
      Serial.print(sensor_status);
      sent = true;
      //Serial.println("Object present...");
    }    
    digitalWrite(led, HIGH);
  }
  else {
    moveConveyor();
    sent = false;
    digitalWrite(led, LOW);
  }
}

void moveConveyor() {

}

void stopConveyor() {

}
