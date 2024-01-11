# MEMS Gas Sensor (CO, Alcohol, NO2 & NH3)

A simple tes program to test the [Gravity: MEMS Gas Sensor (CO, Alcohol, NO2 & NH3) - I2C - MiCS-4514](https://www.dfrobot.com/product-2417.html) ($37.91)

## APPLICATIONS

- Gas leak detection
- Gas safety equipment
- Air environment detection

## Gas Sensor Detections

The product page [Gravity: MEMS Gas Sensor (CO, Alcohol, NO2 & NH3) - I2C - MiCS-4514](https://www.dfrobot.com/product-2417.html), specificlly shows as MICS-4514 and on the back of product shows MiCS-4514 V1.0

The MICS-4514 You can get all gas concentrations:

- MICS-4514 You can get all gas state
- MICS-5524 You can get the state of CO, CH4, C2H5OH, C3H8, C4H10, H2, H2S, NH3
- MICS-2714 You can get the state of NO2, H2 ,NO

| Symbol | Address | Name | Concentration Level |
| --- | ---- | ---- | ---- |
| CO | 0x01 | Carbon Monoxide | (1    - 1000)PPM
| CH4 | 0x02 | Methane | (1000 - 25000)PPM
| C2H5OH | 0x03 | Ethanol | (10   - 500)PPM
| C3H8   | 0x04 | Propane | Can only determine if Present not concentration Level
| C4H10  | 0x05 | Iso Butane | Can only determine if Present not concentration Level
| H2 | 0x06 | Hydrogen | (1    - 1000)PPM
| H2S | 0x07 | Hydrothion | Can only determine if Present not concentration Level
| NH3 | 0x08 | Ammonia | (1    - 500)PPM
| NO | 0x09 | Nitric Oxide | Can only determine if Present not concentration Level
| NO2 | 0x0A | Nitrogen Dioxide | (0.1  - 10)PPM

Yet tests show:

``` c++
===============================================================================
Carbon Monoxide: 0.0 PPM  Methane: 0.0 PPM  Ethanol: 0.00 PPM  Propane: -1.00 PPM  Iso Butane: -1.00 PPM  Hydrogen: 0.0 PPM  Ammonia: 0.0 PPM  Nitric Oxide: -1.00 PPM  Nitrogen Dioxide: 0.0 PPM
```

Where we assume -1 implies that the address or reading is not available.

## FEATURES

- Support detection of a variety of harmful gas
- Integrate the calculation formulas of various gas concentration
- Low power consumption
- I2C digital output
- Compatible with the 3.3~5.5V master controller

## SPECIFICATION

- Detection of Physical Quantities: gas concentration of CO，C2H5OH(Alcohol), H2, NO2, NH3, CH4
- Operating Voltage: 3.3～5.5V DC
- Power Dissipation: 0.45W(5V)
- Output Signal: I2C (0~3V)
- Measuring Range:
  - 1 – 1000ppm (Carbon monoxide CO)
  - 0.05 – 10ppm (Nitrogen dioxide NO2)
  - 10 – 500ppm (Ethanol C2H5OH)
  - 1 – 1000ppm (Hydrogen H2)
  - 1 – 500ppm (Ammonia NH3)
  - more than 1000ppm (Methane CH4)
- Working Temperature: -30～85℃
- Working Humidity: 5～95% RH(No condensation)
- Storage Temperature: -40~85℃
- Lifespan: >2 years (in the air)
- Circuit Board Size: 27mm* 37mm
- Mounting Hole Size: inner diameter 3.1mm/ outer diameter 6mm

## I2C Addressing

The I2C address defaults to 0x78, corresponding to the ADDRESS_3 in the code. If you need to modify the I2C address, you can first configure the hardware I2C address via the dial-up switch on the module, and modify the definition ADDRESS_X of the I2C address in the sample code. The correspondence between the dial switch and the I2C address parameter is as follows:

- ADDRESS_0：0x75, A0=0, A1=0（Default Address）
- ADDRESS_1：0x76, A0=1, A1=0
- ADDRESS_2：0x77, A0=0, A1=1
- ADDRESS_3：0x78, A0=1, A1=1

## Documentation

- [Product wiki](https://wiki.dfrobot.com/_SKU_SEN0377_Gravity__MEMS_Gas_Sensor_CO__Alcohol__NO2___NH3___I2C___MiCS_4514)
- [MiCS-4514 Datasheet](https://img.dfrobot.com.cn/wiki/5b973267c87e6f19943ab3ad/b5b08fe2ea631f0becdfa0c15db88c4a.pdf)
- [Schematics Diagram](https://img.dfrobot.com.cn/wiki/5b973267c87e6f19943ab3ad/ec7dd3a55ba1d58fcbd5830ee08c0e7f.pdf)
- [Dimension and Component Layout](https://img.dfrobot.com.cn/wiki/5b973267c87e6f19943ab3ad/7ff4e494a339ab2c96220ad9e41582b1.pdf)
