#include <Arduino.h>
#include <FlexCAN.h>

FlexCAN can(50000);
static CAN_message_t msg;


void setup() {
can.begin();
pinMode(13, OUTPUT);
delay(1000);
}

void loop() {
  msg.buf[0]= 2;
  msg.len = 1;
  msg.timeout=100;
  msg.id = 1;
  can.write(msg);

  if(can.write(msg))
  digitalWrite(13, HIGH);

  delay(500);
}
