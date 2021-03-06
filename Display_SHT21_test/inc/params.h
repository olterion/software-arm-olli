/*
 *  Copyright (c) 2016 Oliver Stefan <os252@gmx.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 */

#ifndef params_h
#define params_h



// quantity of switches
#define NUM_CHANNELS 2

// Eeprom address: Start of Function parameters
#define EE_FUNCTIONS_PARAMS_BASE         0x01f6	//D:502

// Eeprom address: start of timing parameters
#define EE_TIMING_PARAMS_BASE  0x01f7 //D503




#define TEMPERATURE_FUNCTION_ACTIVE	0x01
#define AIR_VALUES_ACTIVE			0x02
#define DISPLAY_WINDOW_OPEN			0x04
#define DISPLAY_AIR_VENTILATION		0x08
#define	EXTERN_TEMP_SENSOR			0x10

// Eeprom address: Send  actual temperature cyclically (not send = 0 or value: 1,2,3,4,5,10,15,20,30,40,50,60 min)
// size: 8 bit
#define EE_ACTUAL_TEMP_SEND_CYCLIC 361

// Eeprom address: Send actual temperature value after change of (not send = 0, steps 0,1K, range: 0,1K - 2.0K)
#define EE_ACTUAL_TEMP_SEND_CHANGE 363

// Eeprom address: Send setpoint at change (no = 0, yes = 1)
#define EE_SETPOINT_TEMP_SEND 407

enum timed_values {
	TEMPERATURES,
	AIR_VALUES,
	NUM_TIMED_VALUES
};

// Enumeration of all COM Objects
enum comObjects {
	SEND_INTERN_TEMP,
	SEND_SET_TEMP,
	REC_EXT_SET_TEMP,
	SEND_AIR_QUALITY,
	SEND_AIR_HUMIDITY,
	REC_WINDOW_STATE,
	REC_VENTILATION_STATE,
	SEND_EXT_TEMP
};

extern Timeout timeout[NUM_TIMED_VALUES];

#endif
