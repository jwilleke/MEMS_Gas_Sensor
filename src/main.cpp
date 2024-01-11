#include <Arduino.h>

#include "DFRobot_MICS.h"
#include <config.h>
#include <ArduinoJson.h>

/**
 * select i2c device address
 * MICS_ADDRESS_0               0x75
 * MICS_ADDRESS_1               0x76
 * MICS_ADDRESS_2               0x77
 * MICS_ADDRESS_3               0x78
 */
#define MICS_I2C_ADDRESS MICS_ADDRESS_0
#define CALIBRATION_TIME 3 // Default calibration time is three minutes
#define I2C_COMMUNICATION  // I2C communication. Comment out this line of code if you want to use SPI communication.

#ifdef I2C_COMMUNICATION
DFRobot_MICS_I2C MICS(&Wire, MICS_I2C_ADDRESS);
#else
/**
 * Set up digital pin according to the on-board pin connected with SPI chip-select pin
 * csPin Available Pins. For example: ESP32&ESP8266(D3), m0(6)
 */
uint8_t csPin = D3;
DFRobot_ENS160_SPI ENS160(&SPI, csPin);
#endif

void dumpData(uint8_t hexCode)
{
  float co_gasdata = float(MICS.getGasData(hexCode));
  if (co_gasdata == EXIST)
  {
    Serial.print("  YES ");
  }
  else
  {
    Serial.println(" NO ");
  }
  int8_t gasFlag = MICS.getGasExist(hexCode);
  if (gasFlag == EXIST)
  {
    Serial.print("  YES ");
  }
  else
  {
    Serial.println(" NO ");
  }
}

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ; // Wait for serial to be ready
  while (!MICS.begin())
  {
    Serial.println("Communication with MICS device failed, please check connection");
    delay(1000);
  }
  Serial.println("Communication with MICS device connected successful!");
  /**!
  Gets the power mode of the sensor
  The sensor is in sleep mode when power is on,so it needs to wake up the sensor.
  The data obtained in sleep mode is wrong
 */
  uint8_t mode = MICS.getPowerState();

  if (mode == SLEEP_MODE)
  {
    MICS.wakeUpMode();
    Serial.println("wake up sensor success!");
  }
  else
  {
    Serial.println("The sensor is wake up mode");
  }

  /**!
     Do not touch the sensor probe when preheating the sensor.
     Place the sensor in clean air.
     The default calibration time is 3 minutes.
  */
  while (!MICS.warmUpTime(CALIBRATION_TIME))
  {
    Serial.println("Waiting until the warm-up time is over!");
    delay(3000);
  }
}

void loop()
{
  /**
   * Gas type:
   * MICS-4514 You can get all gas concentration
   *   CO       = 0x01  (Carbon Monoxide)  (1    - 1000)PPM
   *   CH4      = 0x02  (Methane)          (1000 - 25000)PPM
   *   C2H5OH   = 0x03  (Ethanol)          (10   - 500)PPM
   *   C3H8     = 0x04  (Propane) - Apparently not defined in DEFROBIT Sensroe
   *   C4H10    = 0x05  (Iso Butane) - Apparently not defined in DEFROBIT Sensroe
   *   H2       = 0x06  (Hydrogen)         (1    - 1000)PPM
   *   H2S      = 0x07  (Hydrothion) - Apparently not defined in DEFROBIT Sensroe
   *   NH3      = 0x08  (Ammonia)          (1    - 500)PPM
   *   NO       = 0x09  (Nitric Oxide) - Apparently not defined in DEFROBIT Sensroe
   *   NO2      = 0x0A  (Nitrogen Dioxide) (0.1  - 10)PPM
   */
  float co_gasdata = float(MICS.getGasData(CO));
  Serial.print("Carbon Monoxide: ");
  Serial.print(co_gasdata, 1);
  Serial.print(" PPM  ");
  float ch4_gasdata = MICS.getGasData(CH4);
  Serial.print("Methane: ");
  Serial.print(ch4_gasdata, 1);
  Serial.print(" PPM  ");
  Serial.print("Ethanol: ");
  Serial.print(float(MICS.getGasData(C2H5OH)));
  Serial.print(" PPM  ");
  Serial.print("Propane: Present?");
  int8_t gasFlag = MICS.getGasExist(C3H8);
  if (gasFlag == EXIST)
  {
    Serial.print("  YES ");
  }
  else
  {
    Serial.println(" NO ");
  }
  Serial.print(" Level ");
  Serial.print(float(MICS.getGasData(C3H8)));
  Serial.print(" PPM  ");
  Serial.print("Iso Butane: ");
  Serial.print(float(MICS.getGasData(C4H10)));
  Serial.print(" PPM  ");
  float h2_gasdata = MICS.getGasData(H2);
  Serial.print("Hydrogen: ");
  Serial.print(h2_gasdata, 1);
  Serial.print(" PPM  ");
  float nh3_gasdata = MICS.getGasData(NH3);
  Serial.print("Ammonia: ");
  Serial.print(nh3_gasdata, 1);
  Serial.print(" PPM  ");
  Serial.print("Nitric Oxide: ");
  Serial.print(float(MICS.getGasData(NO)));
  Serial.print(" PPM  ");
  float no2_gasdata = MICS.getGasData(NO2);
  Serial.print("Nitrogen Dioxide: ");
  Serial.print(no2_gasdata, 1);
  Serial.println(" PPM");
  Serial.println(DBAR);
  delay(10000);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}