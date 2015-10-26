/*
 * Copyright (c) 2013, Institute for Pervasive Computing, ETH Zurich
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
 */

/**
 * \file
 *      Example resource
 * \author
 *      Matthias Kovatsch <kovatsch@inf.ethz.ch>
 */

#include "contiki.h"
#include "dev/relay.h"


#include <string.h>
#include "rest-engine.h"

#define RELAY_PIN 2     /* Relay Pin  DIO1*/ 
#define PORT_D GPIO_D_BASE

#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#define PRINT6ADDR(addr) PRINTF("[%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x]", ((uint8_t *)addr)[0], ((uint8_t *)addr)[1], ((uint8_t *)addr)[2], ((uint8_t *)addr)[3], ((uint8_t *)addr)[4], ((uint8_t *)addr)[5], ((uint8_t *)addr)[6], ((uint8_t *)addr)[7], ((uint8_t *)addr)[8], ((uint8_t *)addr)[9], ((uint8_t *)addr)[10], ((uint8_t *)addr)[11], ((uint8_t *)addr)[12], ((uint8_t *)addr)[13], ((uint8_t *)addr)[14], ((uint8_t *)addr)[15])
#define PRINTLLADDR(lladdr) PRINTF("[%02x:%02x:%02x:%02x:%02x:%02x]", (lladdr)->addr[0], (lladdr)->addr[1], (lladdr)->addr[2], (lladdr)->addr[3], (lladdr)->addr[4], (lladdr)->addr[5])
#else
#define PRINTF(...)
#define PRINT6ADDR(addr)
#define PRINTLLADDR(addr)
#endif

static void res_post_put_handler(void *request, void *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset);
static void res_get_handler(void *request, void *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset);
static void res_periodic_handler(void);
/*A simple actuator example, depending on the color query parameter and post variable mode, corresponding led is activated or deactivated*/
PERIODIC_RESOURCE(res_relay,
         "title=\"Relay: ?mode=on|off\";rt=\"Control\"",
         res_get_handler,
         NULL,
         res_post_put_handler,
         NULL,
         5 * CLOCK_SECOND,
         res_periodic_handler);

static int32_t event_counter = 0;
static void
res_post_put_handler(void *request, void *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
  const char *mode = NULL;
  size_t len = 0;
  relay_enable(PORT_D, RELAY_PIN); // PUT the right relay pin here
 
  //Get mode
  len = REST.get_query_variable(request, "mode", &mode);
  
  if(strncmp(mode, "on", len) == 0)
  {  
  	if(relay_status(PORT_D, RELAY_PIN ))    
        {
		PRINTF("already relay on \n");
		const char *msg = "Light already on";
		REST.set_response_payload(response, msg, strlen(msg));
	}
        else 
        {
		relay_on(PORT_D, RELAY_PIN);
		const char *msg = "Light on";
		REST.set_response_payload(response, msg, strlen(msg));
	}
   }
   else if (strncmp(mode, "off", len) == 0)
   {  
   	if(!(relay_status(PORT_D, RELAY_PIN )))
	{    
        	PRINTF("already relay off \n");
		const char *msg = "Light already off";
		REST.set_response_payload(response, msg, strlen(msg));
	}
        else 
	{
        	relay_off(PORT_D, RELAY_PIN);
		const char *msg = "Light off";
		REST.set_response_payload(response, msg, strlen(msg));
	}
   }
   else
   {
	const char *msg = "Wrong mode mode should be on|off";
	REST.set_response_payload(response, msg, strlen(msg));
   }
}

static void
res_get_handler(void *request, void *response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
	// observerable resources start
        REST.set_header_content_type(response, REST.type.TEXT_PLAIN);
        REST.set_header_max_age(response, res_relay.periodic->period / CLOCK_SECOND);
        REST.set_response_payload(response, buffer, snprintf((char *)buffer, preferred_size, "VERY LONG EVENT %lu", event_counter));
        // observerable resources end
        if(relay_status(PORT_D, RELAY_PIN ))  
	{  
        	PRINTF("relay is on \n"); // put response
        	const char *msg = "Light on";
		REST.set_response_payload(response, msg, strlen(msg));
	//	REST.notify_subscribers(&res_relay);

       	}
       	else
       	{ 
       		PRINTF("relay is off \n"); //put response
           	const char *msg = "Light off";
		REST.set_response_payload(response, msg, strlen(msg));
	//	REST.notify_subscribers(&res_relay);

       	}
}


static void
res_periodic_handler()
{
  /* Do a periodic task here, e.g., sampling a sensor. */
  ++event_counter;

  /* Usually a condition is defined under with subscribers are notified, e.g., large enough delta in sensor reading. */
  if(1) {
    /* Notify the registered observers which will trigger the res_get_handler to create the response. */
    REST.notify_subscribers(&res_relay);
  }
}
