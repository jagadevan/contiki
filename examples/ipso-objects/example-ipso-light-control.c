/*
 * Copyright (c) 2015, Yanzi Networks AB.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *    3. Neither the name of the copyright holder nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/**
 * \file
 *         An dummy illumination driver as example
 * \author
 *         Joakim Eriksson <joakime@sics.se>
 *         Niclas Finne <nfi@sics.se>
 *         Lovelesh Patel <lovelesh.patel@thingtronics.com>
 */
 /**
 			Pin Details
 			/contiki-subghz/platform/zoul/dev/relay.h
 			P
 			PORT C
 */
 
#include "ipso-objects.h"
//#include "dev/relay.h"
//#include "lib/sensors.h"
#include <stdio.h>
#include "dev/leds.h"
/********************************Led configration for testing ****************************************/
#if LEDS_ALL & LEDS_BLUE || LEDS_ALL & LEDS_RED || LEDS_ALL & LEDS_BLUE
#define LEDS_CONTROL_NUMBER (((LEDS_ALL & LEDS_BLUE) ? 1 : 0) + ((LEDS_ALL & LEDS_RED) ? 1 : 0) + ((LEDS_ALL & LEDS_GREEN) ? 1 : 0))
#else
#define LEDS_CONTROL_NUMBER 1
#endif

struct led_state {
	unsigned long last_on_time;
	uint32_t total_on_time;
	uint8_t is_on;
	uint8_t led_value;
};
static struct led_state states[LEDS_CONTROL_NUMBER];

static value1 = 0;
static value2 = 0;
/***********************************************************************/
/*---------------------------------------------------------------------------*/
static int
is_on_0()
{
 	int status;
//	status=relay.status(SENSORS_ACTIVE);
	//Add Driver For Fan 1
	printf("Enter into the is_on_0\n");
	return status;
}
static int
is_on_1()
{
 	int status;
	//Add Driver For Fan 2
//	status=relay.status(SENSORS_ACTIVE);
	printf("Enter into the is_on_1\n");
	return status;
}
static int
is_on_2()
{
 	int status;
	//Add Driver For Light 2
//	status=relay.status(SENSORS_ACTIVE);
	status=value1;
	printf("Enter into the is_on_2\n");
	return status;
}
static int
is_on_3()
{
 	int status;
	//Add Driver For Light 3
//	status=relay.status(SENSORS_ACTIVE);
	status=value2;
	printf("Enter into the is_on_3\n");
	return status;
}
static int
is_on_4()
{
 	int status;
	//Add Driver For Light 4
//	status=relay.status(SENSORS_ACTIVE);
	printf("Enter into the is_on_4\n");
	return status;
}
static int
is_on_5()
{
 	int status;
	//Add Driver For light 5
//	status=relay.status(SENSORS_ACTIVE);
	return status;
}
static int
is_on_6()
{
 	int status;
	//Add Driver for Light 6
//	status=relay.status(SENSORS_ACTIVE);
	return status;
}
static int
is_on_7()
{
 	int status;
	//Add Driver for Light 7
//	status=relay.status(SENSORS_ACTIVE);
	return status;
}
static int
is_on_8()
{
 	int status;
	//Add Driver For Light 8
//	status=relay.status(SENSORS_ACTIVE);
	return status;
}
static int
is_on_9()
{
 	int status;
	//Add Driver Here For Light 9
//	status=relay.status(SENSORS_ACTIVE);
	return status;
}
static int
is_on_10()
{
	int status;
	///Add driver code For Light 10
	return status;
}

static int
is_on_11()
{
        int status;
        ///Add driver code For socket 1
        return status;
}
static int
is_on_12()
{
        int status;
        ///Add driver code For socket 2
        return status;
}

/*--------------------------------------------------------------------------------*/
static int set_on_0(int status)
{
	uint32_t res;
		if(status)
		{
			//Add Driver Here
		}
		else
		{
		//Add Driver Here
		}
return res;
}
static int set_on_1(int status)
{
	uint32_t res;
		if(status)
		{
			//Add Driver Here
		}
		else
		{
		//Add Driver Here
		}
return res;
}
static int set_on_2(int status)
{
	uint32_t res;
		if(status)
		{
			//leds_toggle(LEDS_GREEN);
			leds_on(1);
			value1 = 1;
		}
		else
		{
			//leds_toggle(LEDS_GREEN);
			leds_off(1);
			value1 = 0;
		}
return res;
}
static int set_on_3(int status)
{
	uint32_t res;
		if(status)
		{
			//Add Driver Here
			leds_on(4);
			value2 = 1;
		}
		else
		{
		//Add Driver Here
			leds_off(4);
			value2 = 0;
		}
return res;
}
static int set_on_4(int status)
{
	uint32_t res;
		if(status)
		{
			//Add Driver Here
		}
		else
		{
		//Add Driver Here
		}
return res;
}
static int set_on_5(int status)
{
	uint32_t res;
		if(status)
		{
			//Add Driver Here
		}
		else
		{
		//Add Driver Here
		}
return res;
}
static int set_on_6(int status)
{
	uint32_t res;
		if(status)
		{
			//Add Driver Here
		}
		else
		{
		//Add Driver Here
		}
return res;
}
static int set_on_7(int status)
{
	uint32_t res;
		if(status)
		{
			//Add Driver Here
		}
		else
		{
		//Add Driver Here
		}
return res;
}
static int set_on_8(int status)
{
	uint32_t res;
		if(status)
		{
			//Add Driver Here
		}
		else
		{
		//Add Driver Here
		}
return res;
}
static int set_on_9(int status)
{
	uint32_t res;
		if(status)
		{
			//Add Driver Here
		}
		else
		{
		//Add Driver Here
		}
return res;
}
static int set_on_10(int status)
{
	uint32_t res;
		if(status)
		{
			//Add Driver Here
		}
		else
		{
		//Add Driver Here
		}
return res;
}
static int set_on_11(int status)
{
        uint32_t res;
                if(status)
                {
                        //Add Driver Here
                }
                else
                {
                //Add Driver Here
                }
return res;
}
static int set_on_12(int status)
{
        uint32_t res;
                if(status)
                {
                        //Add Driver Here
                }
                else
                {
                //Add Driver Here
                }
return res;
}



static int get_dim_level_0()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;


return level;
}
static int get_dim_level_1()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;
	level=10;
return level;
}
static int get_dim_level_2()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;

	level=20;

return level;
}
static int get_dim_level_3()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;


	level=30;
return level;
}
static int get_dim_level_4()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;


	level=40;
return level;
}
static int get_dim_level_5()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;


	level=50;
return level;
}
static int get_dim_level_6()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;

	level=60;
return level;
}
static int get_dim_level_7()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;
	level=70;

return level;
}
static int get_dim_level_8()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;
	level=80;

return level;
}
static int get_dim_level_9()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;
	level=90;

return level;
}
static int get_dim_level_10()
{
//write Api for get dim level..
//return dim level b/w 0 to 100%
int level;
	level=100;

return level;
}

static int set_dim_level_0(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
static int set_dim_level_1(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
static int set_dim_level_2(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
static int set_dim_level_3(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
static int set_dim_level_4(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
static int set_dim_level_5(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
static int set_dim_level_6(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
static int set_dim_level_7(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
static int set_dim_level_8(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
static int set_dim_level_9(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
static int set_dim_level_10(int level)
{
	 /**
   * \brief       Set the dim level of the actuator.
   *
   * \param level The dim level between 0% and 100%.
   * \return      Zero if ok and a non-zero error code otherwise.
   */
//Add Driver Here
	return 1;//if error
return 0; //if ok
}
/*---------------------------------------------------------------------------*/
const struct ipso_objects_actuator example_ipso_light_control = {
  .is_on_0 = is_on_0,
  .is_on_1 = is_on_1,
  .is_on_2 = is_on_2,
  .is_on_3 = is_on_3,
  .is_on_4 = is_on_4,
  .is_on_5 = is_on_5,
  .is_on_6 = is_on_6,
  .is_on_7 = is_on_7,
  .is_on_8 = is_on_8,
  .is_on_9 = is_on_9,
  .is_on_10= is_on_10,
  .is_on_11= is_on_11,
  .is_on_12= is_on_12,
 

  .set_on_0 = set_on_0,	
  .set_on_1 = set_on_1,
  .set_on_2 = set_on_2,
  .set_on_3 = set_on_3,
  .set_on_4 = set_on_4,
  .set_on_5 = set_on_5,
  .set_on_6 = set_on_6,
  .set_on_7 = set_on_7,
  .set_on_8 = set_on_8,
  .set_on_9 = set_on_9,
  .set_on_10= set_on_10,
  .set_on_11= set_on_11,
  .set_on_12= set_on_12,


  .get_dim_level_0=get_dim_level_0,
  .get_dim_level_1=get_dim_level_1,
  .get_dim_level_2=get_dim_level_2,
  .get_dim_level_3=get_dim_level_3,
  .get_dim_level_4=get_dim_level_4,
  .get_dim_level_5=get_dim_level_5,
  .get_dim_level_6=get_dim_level_6,
  .get_dim_level_7=get_dim_level_7,
  .get_dim_level_8=get_dim_level_8,
  .get_dim_level_9=get_dim_level_9,
  .get_dim_level_10=get_dim_level_10,
 

  .set_dim_level_0=set_dim_level_0,
  .set_dim_level_1=set_dim_level_1,
  .set_dim_level_2=set_dim_level_2,
  .set_dim_level_3=set_dim_level_3,
  .set_dim_level_4=set_dim_level_4,
  .set_dim_level_5=set_dim_level_5,
  .set_dim_level_6=set_dim_level_6,
  .set_dim_level_7=set_dim_level_7,
  .set_dim_level_8=set_dim_level_8,
  .set_dim_level_9=set_dim_level_9,
  .set_dim_level_10=set_dim_level_10
};
/*---------------------------------------------------------------------------*/
