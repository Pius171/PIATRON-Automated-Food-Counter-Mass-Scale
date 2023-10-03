#ifndef defines_h
#define defines_h

#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 12);  // RX, TX for HC-05 bluetooth

#define DEBUG 0

#if DEBUG == 0
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#define debugln2Param(x, y) Serial.println(x, y)


#else
#define debug(x)
#define debugln(x)
#endif

//pins:
const int HX711_dout = 4;  //mcu > HX711 dout pin
const int HX711_sck = 5;   //mcu > HX711 sck pin

//HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);

const int calVal_eepromAdress = 0;
const int tareOffsetVal_eepromAdress = 4;
unsigned long t = 0;

#endif      //defines_h