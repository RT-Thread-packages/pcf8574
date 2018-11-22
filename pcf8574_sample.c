/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-22     flybreak     Make the first version of pcf8574's package
 */

#include <rtthread.h>
#include "pcf8574.h"

#define TEST_IO    0 //(0-7)
#define I2C_BUS    "i2c1"

int pcf8574_sample(void)
{
    rt_uint8_t value;
    pcf8574_device_t dev = RT_NULL;
    
    dev = pcf8574_init(I2C_BUS, RT_NULL);

    if (dev == RT_NULL)
        return -1;

    pcf8574_pin_write(dev, TEST_IO, 0);

    value = pcf8574_pin_read(dev, TEST_IO);
    rt_kprintf("The value of pcf8574.P%d is %d\n", TEST_IO, value);

    rt_thread_mdelay(1000);

    pcf8574_pin_write(dev, TEST_IO, 1);

    value = pcf8574_pin_read(dev, TEST_IO);
    rt_kprintf("The value of pcf8574.P%d is %d\n", TEST_IO, value);

    pcf8574_deinit(dev);

    return 0;
}
#ifdef FINSH_USING_MSH
MSH_CMD_EXPORT(pcf8574_sample, a pcf8574 sample);
#endif
