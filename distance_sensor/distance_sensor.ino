int transmitter = 3;
float received;
float noise;
float denoised;

void setup() {
  // put your setup code here, to run once:
  pinMode(transmitter, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(transmitter, HIGH);
//  delayMicroseconds(50);
  received = analogRead(A0);
  Serial.println(received);

  //  digitalWrite(transmitter,LOW);
  //noise = 1023.00 - analogRead(A0);
  //Serial.println(noise);

  //  denoised = received - noise;

  //  Serial.println(denoised);
  // put your main code here, to run repeatedly:
}
