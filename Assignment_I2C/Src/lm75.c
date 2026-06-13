#include "lm75.h"
#include "stm32f446xx_i2c_driver.h"
#include <stdint.h>

extern I2C_Handle_t I2C1Handle;

#define LM75_ADDR 0x48
#define TEMP_REG  0x00

float LM75_ReadTemperature(void)
{
    uint8_t reg = TEMP_REG;
    uint8_t temp_data[2];

    I2C_MasterSendData(
            &I2C1Handle,
            &reg,
            1,
            LM75_ADDR,
            I2C_ENABLE_SR);

    I2C_MasterReceiveData(
            &I2C1Handle,
            temp_data,
            2,
            LM75_ADDR,
            I2C_DISABLE_SR);

    int16_t raw;

    raw = (temp_data[0] << 8) | temp_data[1];
    raw >>= 7;

    return raw * 0.5f;
}
