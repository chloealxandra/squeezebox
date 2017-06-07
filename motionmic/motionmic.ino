#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <NXPMotionSense.h>
#include <EEPROM.h>

AudioInputAnalog         audioInput(A0);           //xy=150,176
AudioAnalyzeRMS          rms1;           //xy=320,167
AudioConnection          patchCord1(audioInput, rms1);
NXPMotionSense imu;
NXPSensorFusion filter;

float n;
int midival;
int midipitch;
int midiheading;
int midiroll;
float sample; //the variable that will hold the value read from the microphone each time


void setup() {
  // put your setup code here, to run once:
   AudioMemory(20);
   Serial.begin(9600);
   imu.begin();
   filter.begin(100);
}

void loop() {
  float ax, ay, az;
  float gx, gy, gz;
  float mx, my, mz;
  float roll, pitch, heading;

 //the arduino takes continuous readings from the microphone
  if (rms1.available()){
    sample = rms1.read();
    sample = sample*100;
    sample = constrain(sample, 0, 100);
    midival = map(sample, 0, 99, 0, 127);
    usbMIDI.sendControlChange(1, midival, 1);
    Serial.println(sample);
    Serial.println(midival);
  }
  if (imu.available()) {
    // Read the motion sensors
    imu.readMotionSensor(ax, ay, az, gx, gy, gz, mx, my, mz);

    // Update the SensorFusion filter
    filter.update(gx, gy, gz, ax, ay, az, mx, my, mz);

    // print the heading, pitch and roll
    roll = filter.getRoll();
    pitch = filter.getPitch();
    heading = filter.getYaw();
    Serial.print("Orientation: ");
    midiheading = map(heading, 0, 400, 0, 127);
    usbMIDI.sendControlChange(2, midiheading, 1);
    midipitch = map(pitch, 0, 400, 0, 127);
    usbMIDI.sendControlChange(3, midipitch, 1);
    midiroll = map(roll, 0, 400, 0, 127);
    usbMIDI.sendControlChange(4, midiroll,1);
    Serial.print(heading);
    Serial.print(" ");
    Serial.print(pitch);
    Serial.print(" ");
    Serial.println(roll);
  }
  delay(100);
}
