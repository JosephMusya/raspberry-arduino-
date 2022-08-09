int sensor_status = 0;
int random_val;
int led = 13;
int transmitter = 3;

float received;
float noise;
float denoised;

String response;
String data;

bool system_status = false;
bool sent = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(transmitter, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    getData();
  }

  if (system_status) {
    start();
    delay(10);
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
  digitalWrite(transmitter, HIGH);
  delayMicroseconds(10);
  received = analogRead(A0);
  //  Serial.println(received);
  if (received < 600) {
    sensor_status = 1;
    stopConveyor();    

    if (!sent) {
      Serial.print(sensor_status);
      digitalWrite(led, HIGH);
      sent = true;
      while (true){
        String progress = Serial.readStringUntil('\r');        
        if (progress == "DONE"){
          break;
        }
      }
    }    
  }
  else if (received > 600) {
    moveConveyor();
    sent = false;
    digitalWrite(led, LOW);
  }
}

void moveConveyor() {

}

void stopConveyor() {

}
