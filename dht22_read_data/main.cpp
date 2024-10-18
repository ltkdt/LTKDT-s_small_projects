#include <Arduino.h>

#define DHT22_PIN 8

// STEP 1: send start signal

void startSignal(uint8_t dht22_pin){
  pinMode(dht22_pin, OUTPUT);
  digitalWrite(dht22_pin, LOW);
  delayMicroseconds(1000); 
  digitalWrite(dht22_pin, HIGH);
  delayMicroseconds(40); 
}

// STEP 2: wait for a response from DHT22

bool waitRepsonse(uint8_t dht22_pin){
  unsigned long time;
  pinMode(dht22_pin, INPUT);
  time = micros();

  while(!digitalRead(dht22_pin));

  if (  micros() - time > 85) return 0; // timeout

  time = micros();
  while(digitalRead(dht22_pin));
  
  if ( micros() - time > 85) return 0; // timeout
  
  return 1;
}

// STEP 3: read raw data

void readRawData(uint8_t dht22_pin){
    unsigned long time;
    uint8_t cur_byte = 0;
    uint8_t bytelist[5];
    uint8_t i = 0;
    while(i < 40)
    {
        // i & 7 == 0 if i is divisible by 8
        if( !(i & 7) ){ 
            bytelist[(i / 8) - 1] = cur_byte;
            cur_byte = 0;
        }

        while(!digitalRead(dht22_pin));      
        //delayMicroseconds(50);
        time = micros();
        //--------------------------------------------------------------------
        while( digitalRead(dht22_pin) ) ;
        // databyte = (micros() - time > 60) ? (databyte<<1)|(0x01) : databyte<<1 ;
        cur_byte = ( micros() - time > 30 ) ? (cur_byte << 1)|(1) : cur_byte << 1;
        i++;
    }
    bytelist[4] = cur_byte;

    uint16_t raw_humidity = ( bytelist[0] << 8) | (bytelist[1]) ;
    uint16_t raw_temperature = ( bytelist[2] << 8) | (bytelist[3]) ;

    // Once we have the raw data we can then process it.
    Serial.print("Relative humidity (%): ");
    Serial.println( float(raw_humidity) / 10.0 );
    Serial.print("Temperature (oC): ");
    Serial.println( float(raw_temperature) / 10.0 );

    if ( ((bytelist[0] + bytelist[1] + bytelist[2] + bytelist[3]) & 255) == bytelist[4]){
        Serial.println("Checksum correct. Data is valid");
    }
    else{
        Serial.println("Checksum error. The numbers are wrong");
    }   
}

void setup(){
  Serial.begin(9600);
}

void loop(){
  // We need to wait for more than 1 second for the sensor to be stable
  delay(1500);
  startSignal(DHT22_PIN);
  if (waitRepsonse(DHT22_PIN) ){
    readRawData(DHT22_PIN);
  }
  else{
    Serial.println("Timeout error occur when waiting for response");
  }
}