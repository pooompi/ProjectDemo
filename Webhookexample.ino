void setup() {
    
}

void loop() {
  String temp = String(random(40, 60));
  Particle.publish("temp", temp, PRIVATE);
  delay(5000);
}
