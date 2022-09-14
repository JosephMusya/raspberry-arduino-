int sensor_status = 0;
int led = 13;
int transmitter = 12;
int relay = 11;
int motorPin1 = 8;
int motorPin2 = 9;

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
  pinMode(relay,OUTPUT);
  pinMode(transmitter, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(relay,LOW);
  Serial.print("Welcome");


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
  }
  else {
    alert();
  }

  //Serial.println(random_val);

}
void alert() {
  digitalWrite(led, HIGH);
  delay(50);
  digitalWrite(led, LOW);
  delay(50);
}
void start() {
  digitalWrite(transmitter, HIGH);
  delayMicroseconds(2);
  received = 1023.0 - analogRead(A0);

  digitalWrite(transmitter, LOW);
  delayMicroseconds(2);
  noise = 1023.0 - analogRead(A0);

  denoised = received - noise;
  Serial.println(denoised);

  if (denoised > 0) {
    sensor_status = 1;
    stopConveyor();
    if (!sent) {
      Serial.print(sensor_status);
      digitalWrite(led, HIGH);
      sent = true;

      while (true) {
        if (Serial.available() > 0) {
          String progress =  Serial.readStringUntil('\r');
          if ((progress) == "DONE") {
            break;
          }
        }
      }
    }

  }
  else {
    moveConveyor();
    digitalWrite(led, LOW);
    sent = false;
  }
}

void moveConveyor() {
  digitalWrite(relay,HIGH);
//  analogWrite(6,50);
  Serial.println("Conveyor moving");
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void stopConveyor() {
  digitalWrite(relay,LOW);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}
