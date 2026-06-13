

#include "stm32f446xx.h"
#include "lm75.h"
#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_i2c_driver.h"
#include <stdint.h>



I2C_Handle_t I2C1Handle;
void I2C1_GPIOInits(void)
{
    GPIO_Handle_t I2CPins;

    I2CPins.pGPIOx = GPIOB;

    I2CPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    I2CPins.GPIO_PinConfig.GPIO_PinAltFunMode = 4;
    I2CPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
    I2CPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
    I2CPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

    // PB8 -> SCL
    I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
    GPIO_Init(&I2CPins);

    // PB9 -> SDA
    I2CPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_9;
    GPIO_Init(&I2CPins);
}

void I2C1_Inits(void)
{
    I2C1Handle.pI2Cx = I2C1;

    I2C1Handle.I2C_Config.I2C_AckControl = I2C_ACK_ENABLE;
    I2C1Handle.I2C_Config.I2C_DeviceAddress = 0x61;
    I2C1Handle.I2C_Config.I2C_FMDutyCycle = I2C_FM_DUTY_2;
    I2C1Handle.I2C_Config.I2C_SCLSpeed = I2C_SCL_SPEED_SM;

    I2C_Init(&I2C1Handle);

    I2C_PeripheralControl(I2C1, ENABLE);
}

int main(void)
{
    float temperature;

    I2C1_GPIOInits();
    I2C1_Inits();

    while(1)
    {
        temperature = LM75_ReadTemperature();

        // Put breakpoint here
        // Watch variable temperature

        for(uint32_t i=0;i<500000;i++);
    }
}
