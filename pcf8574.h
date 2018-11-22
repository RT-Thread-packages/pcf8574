/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-21     SummerGift   change to new framework
 * 2018-11-22     flybreak     Make the first version of pcf8574's package
 */

#ifndef __PCF8574_H
#define __PCF8574_H

#include <rtthread.h>
#include <rtdevice.h>

#define PCF8574_ADDR_DEFAULT    0x20

/* pcf8574 device structure */
struct pcf8574_device
{
    struct rt_i2c_bus_device *bus;
    rt_uint8_t i2c_addr;
};
typedef struct pcf8574_device *pcf8574_device_t;

/**
 * This function initialize the pcf8574 device.
 *
 * @param dev_name the name of i2c bus device
 * @param i2c_addr the i2c device address for i2c communication,RT_NULL use default address
 *
 * @return the pointer of device driver structure, RT_NULL reprensents  initialization failed.
 */
pcf8574_device_t pcf8574_init(const char *dev_name, rt_uint8_t i2c_addr);

/**
 * This function releases memory
 *
 * @param dev the pointer of device driver structure
 */
void pcf8574_deinit(struct pcf8574_device *dev);

/**
 * This function read a byte data from the pcf8574.
 *
 * @param dev the pointer of device driver structure
 *
 * @return the pointer of device driver structure, RT_NULL reprensents  initialization failed.
 */
uint8_t pcf8574_read_byte(pcf8574_device_t dev);

/**
 * This function write a byte data from the pcf8574.
 *
 * @param dev the pointer of device driver structure
 * @param param the i2c device address for i2c communication, RT_NULL for spi
 *
 * @return the pointer of device driver structure, RT_NULL reprensents  initialization failed.
 */
void pcf8574_write_byte(pcf8574_device_t dev, uint8_t value);

/**
 * This function read a bit data from the pcf8574.
 *
 * @param dev the pointer of device driver structure
 * @param param the i2c device address for i2c communication, RT_NULL for spi
 *
 * @return the pointer of device driver structure, RT_NULL reprensents  initialization failed.
 */
uint8_t pcf8574_read_bit(pcf8574_device_t dev, uint8_t bit);

/**
 * This function write a bit data from the pcf8574.
 *
 * @param dev the pointer of device driver structure
 * @param param the i2c device address for i2c communication, RT_NULL for spi
 *
 * @return the pointer of device driver structure, RT_NULL reprensents  initialization failed.
 */
void pcf8574_write_bit(pcf8574_device_t dev, uint8_t bit, uint8_t value);

#endif

