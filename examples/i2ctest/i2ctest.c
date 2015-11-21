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
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h> /* For printf() */
#include "hw_ints.h"
#include "hw_memmap.h"
#include "gpio.h"
#include "interrupt.h"
#include "ioc.h"
//#include "hw_ioc.h"
#include "sys-ctrl.h"

#include "gptimer.h"
#include "cpu.h"
//#include "uartstdio.h"

#define LED_RELAY_PIN 2     /* Relay Pin */
#define PORT_D GPIO_D_BASE

// found in #include "sys-ctrl_a.h"
#define SYS_CTRL_PERIPH_GPT0       0x00000000  // General Purpose Timer 0
//

/*
#define GPTIMER0_BASE GPT_0_BASE
#define GPTIMER1_BASE GPT_1_BASE
#define GPTIMER2_BASE GPT_2_BASE
#define GPTIMER3_BASE GPT_3_BASE   */

#define SYS_CTRL_SYSDIV_32MHZ SYS_CTRL_CLOCK_CTRL_SYS_DIV_32MHZ
/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/


/*
// Start
// Configure TimerA as a half-width one-shot timer, and TimerB as a
// half-width edge capture counter.
//
//TimerConfigure(GPTIMER0_BASE, (GPTIMER_CFG_SPLIT_PAIR | GPTIMER_CFG_A_ONE_SHOT | GPTIMER_CFG_B_CAP_COUNT));
TimerConfigure(GPTIMER0_BASE, GPTIMER_CFG_SPLIT_PAIR | GPTIMER_CFG_A_PWM | GPTIMER_CFG_B_PWM);
TimerControlLevel(GPTIMER0_BASE,GPTIMER_BOTH,false);
//
// Set the count time for the the one-shot timer (TimerA).
//
TimerLoadSet(GPTIMER0_BASE, GPTIMER_BOTH, 3000);
//
// Configure the counter (TimerB) to count both edges.
//
TimerControlEvent(GPTIMER0_BASE, GPTIMER_B, GPTIMER_EVENT_BOTH_EDGES);
//
// Enable the timers.
//
TimerEnable(GPTIMER0_BASE, GPTIMER_BOTH); */

//*****************************************************************************
#define EXAMPLE_PIN_UART_RXD            GPIO_PIN_0 
#define EXAMPLE_PIN_UART_TXD            GPIO_PIN_1 
#define EXAMPLE_GPIO_UART_BASE          GPIO_A_BASE

//*****************************************************************************
//
// Number of interrupts before the timer gets turned off.
//
//*****************************************************************************
#define NUMBER_OF_INTS          1000

//*****************************************************************************
//
// Counter to count the number of interrupts that have been called.
//
//*****************************************************************************
static volatile uint32_t g_ui32Counter = 0;

//*****************************************************************************



//*****************************************************************************
//
// The interrupt handler for the Timer0B interrupt.
//
//*****************************************************************************
void
Timer0BIntHandler(void)
{
    //
    // Clear the timer interrupt flag.
    //
    TimerIntClear(GPTIMER0_BASE, GPTIMER_TIMB_TIMEOUT);

    //
    // Update the periodic interrupt counter.
    //
    g_ui32Counter++;

    //
    // Once NUMBER_OF_INTS interrupts have been received, turn off the
    // TIMER0B interrupt.
    //
    if(g_ui32Counter == NUMBER_OF_INTS)
    {
        //
        // Disable the Timer0B interrupt.
        //
        IntDisable(INT_TIMER0B);

        //
        // Turn off Timer0B interrupt.
        //
        TimerIntDisable(GPTIMER0_BASE, GPTIMER_TIMB_TIMEOUT);

        //
        // Clear any pending interrupt flag.
        //
        TimerIntClear(GPTIMER0_BASE, GPTIMER_TIMB_TIMEOUT);
    }
}

PROCESS_THREAD(hello_world_process, ev, data)
{
  
  //static struct etimer timer;
  PROCESS_BEGIN();
  //begintimer();
  //etimer_set(&timer, CLOCK_CONF_SECOND * 1);
   uint32_t ui32PrevCount = 0;

    //
    // Set the clocking to run directly from the external crystal/oscillator.
    // (no ext 32k osc, no internal osc)
    //
   //SysCtrlClockSet(false, false, SYS_CTRL_SYSDIV_32MHZ);

    //
    // Set IO clock to the same as system clock
    //
   //SysCtrlIOClockSet(SYS_CTRL_SYSDIV_32MHZ);    
    
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
    printf(" 16-Bit Timer Interrupt ->\n\r");
    printf(" Timer = Timer0B\n\r");
    printf(" Mode = Periodic\n\r");
    printf(" Number of interrupts = %d \n\r", NUMBER_OF_INTS);
    printf(" Rate = 1ms\n\r");

    //
    // Configure Timer0B as a 16-bit periodic timer.
    //
   TimerConfigure(GPTIMER0_BASE, GPTIMER_CFG_SPLIT_PAIR |
                   GPTIMER_CFG_A_PERIODIC | GPTIMER_CFG_B_PWM);  
/*   TimerConfigure(GPTIMER0_BASE, GPTIMER_CFG_SPLIT_PAIR |
                   GPTIMER_CFG_A_PWM | GPTIMER_CFG_B_PWM);  */

    //
    // Set the Timer0B load value to 1ms.
    //
    TimerLoadSet(GPTIMER0_BASE, GPTIMER_B, sys_ctrl_get_sys_clock() / 100 );
    // TimerLoadSet(GPTIMER0_BASE, GPTIMER_B, SYS_CTRL_32MHZ );
    //
    // The following call will result in a dynamic interrupt table being used.
    // The table resides in RAM.
    // Alternatively SysTickIntHandler can be statically registred in your
    // application.
    // 
    TimerIntRegister(GPTIMER0_BASE, GPTIMER_B, Timer0BIntHandler);      
    
    //
    // Enable processor interrupts.
    //
    //IntMasterEnable();
    INTERRUPTS_ENABLE();
    //
    // Configure the Timer0B interrupt for timer timeout.
    //
    TimerIntEnable(GPTIMER0_BASE, GPTIMER_TIMB_TIMEOUT);

    //
    // Enable the Timer0B interrupt on the processor (NVIC).
    //
    IntEnable(INT_TIMER0B);

    //
    // Initialize the interrupt counter.
    //
    g_ui32Counter = 0;

    //
    // Enable Timer0B.
    //
    TimerEnable(GPTIMER0_BASE, GPTIMER_B);

    //
    // Loop forever while the Timer0B runs.
    //
    while(1)
    {
        //
        // If the interrupt count changed, print the new value
        //
        if(ui32PrevCount != g_ui32Counter)
        {
            //
            // Print the periodic interrupt counter.
            //
            printf("Number of interrupts: %d\r", g_ui32Counter);
            ui32PrevCount = g_ui32Counter;
        }
    }

/*
  while(1) {
    	//PROCESS_YIELD();
 	//if(ev == PROCESS_EVENT_TIMER) {
 

	printf(" Hello Hi \n\r" );
	//etimer_set(&timer, CLOCK_SECOND);
	
    //}
  }
 */ 
  
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
