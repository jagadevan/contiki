/*
 * Copyright (c) 2010, Swedish Institute of Computer Science.
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
 *
 * -----------------------------------------------------------------
 *
 * \file
 *         Device simple pwm driver for openmote
 * \author
 *         Manoj Sony, <manojsony@gmail.com>
 *
 */

#include "contiki.h"
#include "pwm.h"

/*---------------------------------------------------------------------------
Function Name : pwm_init    : Initilaise PWM driver.
INPUT Parmaters : port_address  Possible values :  { GPIO_A_BASE , GPIO_B_BASE ,GPIO_C_BASE, GPIO_D_BASE }
	          pin      	Possible values :  { Pin 0: 0, Pin 1: 1, Pin 2: 2... Pin 7: 7 }
		  TimerBase     Possible values :  { GPTIMER0_BASE, GPTIMER1_BASE, GPTIMER2_BASE and GPTIMER3_BASE }
		  TimerName     Possible values :  { GPTIMER_A, GPTIMER_B }	  	  
OUTPUT Paramaters : None
---------------------------------------------------------------------------*/

void pwm_init(unsigned long port_addr, unsigned char pin, uint32_t TimerBase, uint32_t TimerName)
{
    /* Selects the pin to be configure as the pwm pin of the module */
   
    printf("PWM PIN INITIALIZED SUCCESSFULLY FOR PORTBASE_ADDR : 0x%x , PIN : %d  \r\n",port_addr,pin );


}

/*---------------------------------------------------------------------------
Function Name : pwm_on
INPUT Parmaters : port_address  Possible values :  { GPIO_A_BASE , GPIO_B_BASE ,GPIO_C_BASE, GPIO_D_BASE }
	          pin      	Possible values :  { Pin 0: 0, Pin 1: 1, Pin 2: 2... Pin 7: 7 }
		  TimerBase     Possible values :  { GPTIMER0_BASE, GPTIMER1_BASE, GPTIMER2_BASE and GPTIMER3_BASE }
		  TimerName     Possible values :  { GPTIMER_A, GPTIMER_B }
		  stepsize   	Possible values :  { PWM_STEP_UNINIT,PWM_STEP_0,PWM_STEP_1,PWM_STEP_2,PWM_STEP_3,PWM_STEP_4,PWM_STEP_5 }
OUTPUT Paramaters : None
---------------------------------------------------------------------------*/
void pwm_on(unsigned long port_addr, unsigned char pin, uint32_t TimerBase, uint32_t TimerName , unsigned char stepsize )
{
   
    	printf("pwm_on() value for PORTBASE_ADDR : 0x%x , PIN : %d  \r\n",port_addr,pin );
 
}

/*---------------------------------------------------------------------------
Function Name : pwm_off     
IINPUT Parmaters : port_address  Possible values :  { GPIO_A_BASE , GPIO_B_BASE ,GPIO_C_BASE, GPIO_D_BASE }
	          pin      	Possible values :  { Pin 0: 0, Pin 1: 1, Pin 2: 2... Pin 7: 7 }
		  TimerBase     Possible values :  { GPTIMER0_BASE, GPTIMER1_BASE, GPTIMER2_BASE and GPTIMER3_BASE }
		  TimerName     Possible values :  { GPTIMER_A, GPTIMER_B }
OUTPUT Paramaters : None
---------------------------------------------------------------------------*/
void pwm_off(unsigned long port_addr, unsigned char pin, uint32_t TimerBase, uint32_t TimerName)
{

 
     	printf("pwm_off() value for PORTBASE_ADDR : 0x%x , PIN : %d \r\n",port_addr,pin );
     

  
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Function Name : pwm_status     
INPUT Parmaters : port_address  Possible values :  { GPIO_A_BASE , GPIO_B_BASE ,GPIO_C_BASE, GPIO_D_BASE }
	          pin      	Possible values :  { Pin 0: 0, Pin 1: 1, Pin 2: 2... Pin 7: 7 }
		  TimerBase     Possible values :  { GPTIMER0_BASE, GPTIMER1_BASE, GPTIMER2_BASE and GPTIMER3_BASE }
		  TimerName     Possible values :  { GPTIMER_A, GPTIMER_B }
OUTPUT Paramaters : int  < value on pin read >
---------------------------------------------------------------------------*/
int pwm_status(unsigned long port_addr, unsigned char pin, uint32_t TimerBase, uint32_t TimerName)
{
 
    
     	printf("pwm_status()  read value for PORTBASE_ADDR : 0x%x , PIN : %d  is OFF\r\n",port_addr,pin );
        return 0; 

  
}
/*---------------------------------------------------------------------------*/

