# pcf8574 package

[中文页](README_ZH.md) | English

## Introduction

The `pcf8574` software package is a software package developed by RT-Thread for the I2C parallel port expansion circuit PCF8574T, compatible with PCF8574A. Using this software package, you can use the device on RT-Thread very conveniently, and support multiple PCF8574Ts mounted on an I2C bus.

This article mainly introduces the use of the package, API, and `MSH` test commands.

### Directory Structure

```
pcf8574
│ README.md // package description
│ pcf8574.c // source file
│ pcf8574.h // header file
│ pcf8574_sample.c // Sample code for software package
│ SConscript // RT-Thread default build script
│ LICENSE // License file
```

### License

pcf8574 complies with the Apache-2.0 license, see the `LICENSE` file for details.

### Dependence

- RT_Thread 3.0+
- i2c device driver

## method of obtaining

To use `pcf8574 package`, you need to select it in the package management of RT-Thread. The specific path is as follows:

```
RT-Thread online packages
    peripheral libraries and drivers --->
        pcf8574: Remote 8-bit I/O expander for I2C-bus --->
```

Enter the configuration menu of the pcf8574 software package for specific configuration according to your needs

```
    --- pcf8574: Remote 8-bit I/O expander for I2C-bus
        [*] Enable pcf8574 sample
           Version (latest) --->
```

**Enable pcf8574 sample**: Enable pcf8574 sample

After the configuration is complete, let the RT-Thread package manager automatically update, or use the pkgs --update command to update the package to the BSP.

## Instructions

The use process of pcf8574 software package is generally as follows:

1. Initialize pcf8574 device `pcf8574_init`
2. Perform IO operations
   - Use API `pcf8574_port_read/pcf8574_port_write` to operate 8 channels of IO at the same time
   - Use API `pcf8574_pin_read/pcf8574_pin_write` to operate one of the IOs separately

For detailed usage, please refer to [pcf8574 sample program](pcf8574_sample.c).

## MSH Test Command

If the sample program of the pcf8574 software package is enabled, the command `pcf8574_sample` will be exported to the console. After the call, it will detect the PCF8574 device with the address of `0x20` on the `i2c1` bus by default, and will operate the port 0 of the expansion port for testing. The results are as follows:

```
msh >pcf8574_sample
[D/pcf8574] pcf8574 init done
The value of pcf8574.P0 is 0
The value of pcf8574.P0 is 1
msh>
```

## Precautions

Nothing.

## Contact information

- Maintenance: [guozhanxin](https://github.com/Guozhanxin)
- Homepage: <https://github.com/RT-Thread-packages/pcf8574>
