/*
 * Copyright (c) 2006, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

/**
 * \file
 *         A very simple Contiki application showing how relay works
 * \author
 *         Manoj Sony <manojsony@gmail.com>
 */

#include "contiki.h"
#include "lib/sensors.h"
#include "dev/adc.h"
#include "dev/cc2538-sensors.h"
#include <stdio.h> /* For printf() */

#define LED_RELAY_PIN 2     /* Relay Pin */
#define PORT_D GPIO_D_BASE


#define I2C_SCL_PORT             GPIO_B_NUM
#define I2C_SCL_PIN              2
#define I2C_SDA_PORT             GPIO_B_NUM
#define I2C_SDA_PIN              3

#define I2C_SCL_NORMAL_BUS_SPEED  100000  /* 100KHz I2C */
#define I2C_SCL_FAST_BUS_SPEED    400000  /* 400KHz I2C */

/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process, ev, data)
{
  
  static struct etimer timer;
  static int count;
  PROCESS_BEGIN();
/*  i2c_init(I2C_SCL_PORT, I2C_SCL_PIN, I2C_SDA_PORT, I2C_SDA_PIN, 
             I2C_SCL_NORMAL_BUS_SPEED);*/

  etimer_set(&timer, CLOCK_CONF_SECOND * 1);
  count = 0;
  relay_enable(PORT_D,LED_RELAY_PIN);
 
   while(1) {

    PROCESS_WAIT_EVENT();

    if(ev == PROCESS_EVENT_TIMER) {
        
      if(count %2 == 0){
		//relay_on(PORT_D,LED_RELAY_PIN);
	int delayIndex;

  	unsigned int pwmDutyCycle = 0x0000;

 

    //

    // Initialize the interrupt counter.

    //

    int g_ui32Counter = 0;

 

   

    //

    // Set the clocking to run directly from the external crystal/oscillator.

    // (no ext 32k osc, no internal osc)

    //

    SysCtrlClockSet(false, false, 32000000);

 

    //

    // Set IO clock to the same as system clock

    //

    SysCtrlIOClockSet(32000000);   

   

    //

    // The Timer0 peripheral must be enabled for use.

    //

    SysCtrlPeripheralEnable(SYS_CTRL_PERIPH_GPT0);   

 

    //

    // Set up the serial console to use for displaying messages.  This is

    // just for this example program and is not needed for Timer operation.

    //

    //InitConsole();  

 

    //

    // Display the example setup on the console.

    //

    UARTprintf("16-Bit Timer PWM ->");

    UARTprintf("\n   Timer = Timer0B");

    UARTprintf("\n   Mode = PWM with variable duty cycle");

 

    //

    // Configure GPTimer0A as a 16-bit PWM Timer.

    //

    TimerConfigure(GPTIMER0_BASE, GPTIMER_CFG_SPLIT_PAIR |

                   GPTIMER_CFG_A_PWM | GPTIMER_CFG_B_PWM);

 

    //

    // Set the GPTimer0B load value to 1sec by setting the timer load value

    // to SYSCLOCK / 255. This is determined by:

    //      Prescaled clock = 16Mhz / 255

    //      Cycles to wait = 1sec * Prescaled clock

    TimerLoadSet(GPTIMER0_BASE, GPTIMER_A, SysCtrlClockGet() / 4000);       

 

    TimerControlLevel(GPTIMER0_BASE, GPTIMER_A, false);

   

    // Configure GPIOPortA.0 as the Timer0_InputCapturePin.1

    IOCPinConfigPeriphOutput(GPIO_A_BASE, GPIO_PIN_0, IOC_MUX_OUT_SEL_GPT0_ICP1);

       

    // Tell timer to use GPIOPortA.0

    // Does Direction Selection and PAD Selection

    GPIOPinTypeTimer(GPIO_A_BASE, GPIO_PIN_0);

    

    //

    // Enable processor interrupts.

    //

    IntMasterEnable();    

 

    //

    // Enable GPTimer0B.

    //

    TimerEnable(GPTIMER0_BASE, GPTIMER_A);   

 

    UARTprintf("\n");

    //

    // Loop forever while the Timer0B runs.

    //

    while(1)

    {

      for (delayIndex = 0; delayIndex < 100000; delayIndex++);

     

      pwmDutyCycle += 0x0F;

      pwmDutyCycle &= 0xFFFF;

     

      TimerMatchSet(GPTIMER0_BASE, GPTIMER_A, pwmDutyCycle);

     

      UARTprintf("PWM DC Value: %04X -- %04X -- %04X\r",

                      pwmDutyCycle,

                      TimerValueGet(GPTIMER0_BASE, GPTIMER_A),

                      TimerMatchGet(GPTIMER0_BASE, GPTIMER_A) );

     

    	}

	



		
		  //SENSORS_ACTIVATE(cc2538_temp_sensor);
                  // printf( "%d is temp\n",cc2538_temp_sensor.value); 
		

      	}
      	else {  
       		//relay_off(PORT_D,LED_RELAY_PIN);
      	} 
/*	if(count %2 == 0)
	{	
		relay_toggle(PORT_D,LED_RELAY_PIN);
		relay_status(PORT_D,LED_RELAY_PIN);
	}
*/
	count ++;
	etimer_reset(&timer);
    }
  }
  
  
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
