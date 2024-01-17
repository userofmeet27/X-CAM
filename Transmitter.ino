// 5 Channel Transmitter 
  #include <SPI.h>
  #include <nRF24L01.h>
  #include <RF24.h>
  const uint64_t pipeOut = 0xE9E8F0F0E1LL;   
  RF24 radio(7, 8); 
  struct Signal {
  byte throttle;
  byte pitch;
  byte roll;
  byte aux1;
  byte aux2;
};
  Signal data;
  void ResetData() 
{
  data.throttle = 12; 
  data.pitch = 127;   
  data.roll = 127;    
  data.aux1 = 127;    
  data.aux2 = 127;    
}
  void setup()
{
  radio.begin();
  radio.stopListening();
  radio.openWritingPipe(pipeOut);
  radio.setAutoAck(false);
  radio.setCRCLength(RF24_CRC_8);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(108);
  ResetData();
  //Serial.begin(250000);
  delay(1000);
}
  
  int mapJoystickValues(int val, int lower, int middle, int upper, bool reverse)
{
  val = constrain(val, lower, upper);
  if ( val < middle )
  val = map(val, lower, middle, 0, 128);
  else
  val = map(val, middle, upper, 128, 255);
  return ( reverse ? 255 - val : val );
}
  void loop()
{
  
  data.throttle = mapJoystickValues( analogRead(A0), 12, 510, 1020, false );  
  data.roll = mapJoystickValues( analogRead(A3), 12, 510, 1020, true );      
  data.pitch = mapJoystickValues( analogRead(A2), 12, 510, 1020, false );    
  data.aux1 = mapJoystickValues( analogRead(A6), 12, 524, 1020, false );     
  data.aux2 = mapJoystickValues( analogRead(A7), 12, 524, 1020, true );    
  radio.write(&data, sizeof(Signal));

  //Serial.print(data.throttle);
  //Serial.print(" ");
  //Serial.print(data.roll);
  //Serial.print(" ");
  //Serial.print(data.pitch);
  //Serial.print(" ");
  
  //Serial.print(data.aux1);
  //Serial.print(" ");
  //Serial.print(data.aux2);
  //Serial.println(" ");
}