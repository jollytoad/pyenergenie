/* gpio_arduino.c  D.J.Whale  04/04/2016
 * 
 * A very simple interface to the GPIO port on the Arduino.
 *
 * Arduino internally uses the 'wiring' library, but experiments have shown
 * that it is really slow.
 *
 * See 'Faster IO on the Arduino' on the SKPang blog:
 * http://skpang.co.uk/blog/archives/323
 *
 * So this module uses direct register writes, and provides a placeholder for
 * compile-time selection of bitmasks and bitpatterns to support more Arduino
 * boards in the future.
 */

//TODO: there might be platform specific macros here to
//extract register address and bitmask
//really, what we want is to be able to pass in a uint8_t which is a GPIO number
//and this get converted (at compile time preferably) into the register access code
//required to read/write and configure that bit. The actual mapping shoudl probably
//be in the C code for gpio_arduino

//something a bit like this, but this is not correct yet
//#define GPIO_0   PORTB,0x01
//#define GPIO_1   PORTB,0x02
//#define GPIO_2   PORTB,0x04
//#define GPIO_3   PORTB,0x08
//#define GPIO_4   PORTB,0x10
//#define GPIO_5   PORTB,0x20
//#define GPIO_6   PORTB,0x40
//#define GPIO_7   PORTB,0x90
//#define GPIO_8   PORTC,0x01
//#define GPIO_9   PORTC,0x02
//#define GPIO_10  PORTC,0x04
//#define GPIO_14  PORTC,0x08
//#define GPIO_15  PORTC,0x10
//#define GPIO_16  PORTC,0x20


/***** INCLUDES *****/

#include "gpio.h"
#include <arduino.h>

/***** CONFIGURATION *****/


/***** CONSTANTS *****/


/***** VARIABLES *****/

/****** MACROS *****/

//#define INP_GPIO(g)
//#define OUT_GPIO(g)

//#define GPIO_SET
//#define GPIO_CLR

//#define GPIO_READ(g)

//#define GPIO_HIGH(g)
//#define GPIO_LOW(g)


void gpio_init()
{
  //TODO
}


void gpio_setin(uint8_t g)
{
  //TODO this is a temporary hack. Need to use PORT registers
  pinMode(g, INPUT);
}


void gpio_setout(uint8_t g)
{
  //TODO this is a temporary hack. Need to use PORT registers
  pinMode(g, OUTPUT);
}


void gpio_high(uint8_t g)
{
  //TODO this is a temporary hack. Need to use PORT registers
  digitalWrite(g, 1);
}


void gpio_low(uint8_t g)
{
  //TODO this is a temporary hack. Need to use PORT registers
  digitalWrite(g, 0);
}


void gpio_write(uint8_t g, uint8_t v)
{
  //TODO this is a temporary hack. Need to use PORT registers
  digitalWrite(g, v);
}


uint8_t gpio_read(uint8_t g)
{
  //TODO this is a temporary hack. Need to use PORT registers
  return digitalRead(g);
}


/***** END OF FILE *****/