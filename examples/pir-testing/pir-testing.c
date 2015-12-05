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

#include <stdio.h> /* For printf() */

#define PIR_PIN_USED 2     /* Relay Pin */
#define PORT_D GPIO_D_BASE


/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process, ev, data)
{
  //GPIO_A_BASE , GPIO_B_BASE ,GPIO_C_BASE, GPIO_D_BASE 
  int val =0;
  int pirstate = 0;
  PROCESS_BEGIN();
  printf("PIR testing \n\r" );
  //set port D pin2 as input pin
  GPIO_SET_INPUT(PORT_D, (1 << PIR_PIN_USED));

while(1)
{
	val = GPIO_READ_PIN(PORT_D,(1<<PIR_PIN_USED));

	if (val == (1<<PIR_PIN_USED))
	{
          	if ( pirstate == 0)
                {
		  printf( " Motion detected...\n\r");
		  pirstate = 1;	
  		}
	}
	else
	{  	if ( pirstate == 1)
                {
		  printf( " Motion ended...\n\r");
		  pirstate = 0;	
  		}

	}

}
  
  printf("Hello world \n\r" );
  
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
