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
 *         A very simple Contiki application showing how pwm works
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
#include "sys-ctrl.h"
#include "gptimer.h"
#include "cpu.h"


#define LED_RELAY_PIN 2     /* Relay Pin */
#define PORT_D GPIO_D_BASE


// found in #include "sys-ctrl_a.h"
#define SYS_CTRL_PERIPH_GPT2       0x00000002  // GPT2
//

/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/

unsigned int pwmDutyCycle = 100;  // Time for which it shud be on    
unsigned int ulperiod = 1000;    // Period 
int delayIndex = 0;

PROCESS_THREAD(hello_world_process, ev, data)
{
  
  PROCESS_BEGIN();
    printf(" \n16-Bit PWM timer ->\n\r");
    printf(" Mode = PWM\n\r");
     // loadset , match
    checkthiscode(999,50);
 

    while(1)
    {
      	 TimerMatchSet(GPT_2_BASE, GPTIMER_A, pwmDutyCycle++);

         if( pwmDutyCycle >= ulperiod - 1)   {
            pwmDutyCycle = 100;
	   }
        
         if((pwmDutyCycle >= 100) && (pwmDutyCycle <= 600) )  {     // After duty cycle : 975 bulb is off  
          // Adding delay to see the brightness change
           for (delayIndex=0; delayIndex<=100000; delayIndex++);
           for (delayIndex=0; delayIndex<=100000; delayIndex++);
           for (delayIndex=0; delayIndex<=100000; delayIndex++);
           for (delayIndex=0; delayIndex<=100000; delayIndex++);
 	 }
         //printf(" %d is DutyCycle , %d is ulperiod , timerLoadget =%d \n\r ",pwmDutyCycle,ulperiod, TimerLoadGet(GPTIMER2_BASE, GPTIMER_A)); 
         printf(" %d is DutyCycle , %d is ulperiod , timerValueget =%d \n\r ",pwmDutyCycle,ulperiod, TimerValueGet(GPTIMER2_BASE, GPTIMER_A));
	 //SysCtlDelay(50000);

    } // end of while
 
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
