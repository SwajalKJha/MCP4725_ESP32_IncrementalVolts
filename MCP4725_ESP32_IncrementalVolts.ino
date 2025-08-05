#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

const float vcc = 3.3;                // DAC Vcc
const int maxVoltage_mV = 50;         // Max output voltage in mV
const int steps = 10;                 // Number of steps to reach 50 mV
const int delayTime = 2000;           // 2 seconds

void setup() {
  Serial.begin(115200);
  dac.begin(0x60);  // MCP4725 default I2C address
  Serial.println("MCP4725 DAC Started");
}

void loop() {
  for (int i = 0; i <= steps; i++) {
    float voltage = (maxVoltage_mV / 1000.0) * (i / float(steps));
    uint16_t dac_value = (voltage / vcc) * 4095;

    dac.setVoltage(dac_value, false);
    Serial.printf("Sending %.2f mV to custom board\n", voltage * 1000);
    delay(delayTime);
  }
}
