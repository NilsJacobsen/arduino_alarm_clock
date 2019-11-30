#include <Keyboard.h>

#define SENSOR_PIN A0

int sensorData;
char *modeArray[] = {"Sleep-Mode activated", "Day-Mode activated", "Weekend-Mode activated"};
int mode;
int lastMode;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  sensorData = analogRead(SENSOR_PIN);
  //Serial.println(sensorData);
  
  if(sensorData < 80){
    mode = 0;
  } else if(sensorData > 600){
    mode = 2;
  } else {
    mode = 1;
  }

  if(lastMode != mode){
    lastMode = mode;
    Serial.println(modeArray[mode]);
    
    switch(mode){
      case 0:
        Keyboard.print("w");
        break;
      case 1:
        Keyboard.print("d");
        break;
      case 2:
        Keyboard.print("e");
        break;
    }
    delay(100);
  }
}
