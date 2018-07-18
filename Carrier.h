/*
 * Carrier
 * Version 0.04 January, 2015
 * Copyright 2011 Bob Fisch
 *
 * Library to generate IR codes for a Carrier air conditionner.
 *
 * For details, see http://arduino.fisch.lu
 *
 * Depends on IRremote (https://github.com/shirriff/Arduino-IRremote)
 *
 * Version
 * 0.04 > 06.01.2015 - WProgram.h --> Arduino.h (reported by Stanley <stanley@9h1lo.net>)
 * 0.03 > 21.04.2013 - bug report by Darryl Smith
 * 0.02 > 17.10.2011 - added getters
 * 0.01 > 11.10.2011 - initial version
 */

#ifndef Carrier_h
#define Carrier_h

#include <Arduino.h>

// Values for STATE
#define STATE_off 0
#define STATE_on 1

// Values for MODE
#define MODE_auto 1
#define MODE_cold 2
#define MODE_warm 3
#define MODE_wind 4
#define MODE_rain 5

// Values for FAN
#define FAN_1 1
#define FAN_2 2
#define FAN_3 3
#define FAN_4 4

// Values for AIR-FLOW
#define AIRFLOW_dir_1 1
#define AIRFLOW_dir_2 2
#define AIRFLOW_dir_3 3
#define AIRFLOW_dir_4 4
#define AIRFLOW_dir_5 5
#define AIRFLOW_dir_6 6
#define AIRFLOW_change 7
#define AIRFLOW_open 8

// the length of the buffer
#define CARRIER_BUFFER_SIZE 83

// Values for the codes
#define CODE_filler 450
#define CODE_high   1650
#define CODE_low    600
#define CODE_first  8350
#define CODE_second 4300
#define CODE_threshold 700

// main class for manipulating a Carrier buffer
class Carrier
{
	public:
		// fields
		uint16_t codes[CARRIER_BUFFER_SIZE];
		// methods
		// setter
		Carrier(uint8_t _mode,
				uint8_t _fan,
				uint8_t _airFlow,
				uint8_t _temperature,
				uint8_t _state);
		void setTemperature(uint8_t _value);
		void setMode(uint8_t _value);
		void setAirFlow(uint8_t _value);
		void setState(uint8_t _value);
		void setFan(uint8_t _value);
		void restoreFromCodes();
		// getter
		uint8_t getTemperature();
		uint8_t getMode();
		uint8_t getAirFlow();
		uint8_t getState();
		uint8_t getFan();
		// debugging
		void debug();
		void print();
	private:
		// fields
		uint8_t mode;
		uint8_t fan;
		uint8_t airFlow;
		uint8_t temperature;
		uint8_t state;
		uint8_t counter;
		// methods
		void setChecksum();
		void restoreTemperatureFromCodes();
		void restoreFanFromCodes();
		void restoreModeFromCodes();
		void restoreAirFlowFromCodes();
		void restoreStateFromCodes();
};
#endif