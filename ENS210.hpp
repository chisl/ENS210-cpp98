/*
 * name:        ENS210
 * description: The ENS210 integrates one relative humidity sensor and one high-accuracy temperature sensor.
 * manuf:       AMS
 * version:     0.1
 * url:         http://ams.com/eng/content/download/950231/2267959/483138
 * date:        2017-09-03
 * author       https://chisl.io/
 * file:        ENS210.hpp
 */

#include <cinttypes>

/* Derive from class ENS210_Base and implement the read and write functions! */

/* ENS210: The ENS210 integrates one relative humidity sensor and one high-accuracy temperature sensor. */
class ENS210_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	virtual uint16_t read16(uint16_t address, uint16_t n=16) = 0;  // 16 bit read
	virtual void write(uint16_t address, uint16_t value, uint16_t n=16) = 0;  // 16 bit write
	virtual uint32_t read32(uint16_t address, uint16_t n=32) = 0;  // 32 bit read
	virtual void write(uint16_t address, uint32_t value, uint16_t n=32) = 0;  // 32 bit write
	virtual uint64_t read64(uint16_t address, uint16_t n=64) = 0;  // 64 bit read
	virtual void write(uint16_t address, uint64_t value, uint16_t n=64) = 0;  // 64 bit write
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG PART_ID                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG PART_ID:
	 * Identifies the part as ENS210
	 */
	struct PART_ID
	{
		static const uint16_t __address = 0;
		
		/* Bits PART_ID: */
		struct PART_ID_
		{
			/* Mode:r */
			static const uint16_t dflt = 0b0000001000010000; // 16'h210
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register PART_ID */
	void setPART_ID(uint16_t value)
	{
		write(PART_ID::__address, value, 16);
	}
	
	/* Get register PART_ID */
	uint16_t getPART_ID()
	{
		return read16(PART_ID::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                             REG UID                                              *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG UID:
	 * This 8 byte register uniquely identifies a single device among all ENS210 devices.
	 */
	struct UID
	{
		static const uint16_t __address = 4;
		
		/* Bits UID: */
		struct UID_
		{
			/* Mode:r */
			static const uint64_t mask = 0b1111111111111111111111111111111111111111111111111111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63]
		};
	};
	
	/* Set register UID */
	void setUID(uint64_t value)
	{
		write(UID::__address, value, 64);
	}
	
	/* Get register UID */
	uint64_t getUID()
	{
		return read64(UID::__address, 64);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG SYS_CTRL                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG SYS_CTRL:
	 * System configuration
	 */
	struct SYS_CTRL
	{
		static const uint16_t __address = 16;
		
		/* Bits RESET: */
		/* Write 1 to reset the device  */
		struct RESET
		{
			/* Mode:wt */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b01111110; // [1,2,3,4,5,6]
		};
		/* Bits LOW_POWER: */
		/* Controls the automatic low power.  */
		struct LOW_POWER
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t Disabled = 0b0; // Disabled (device stays in active)
			static const uint8_t Enabled = 0b1; // Enabled (device goes to standby when measurement complete)
		};
	};
	
	/* Set register SYS_CTRL */
	void setSYS_CTRL(uint8_t value)
	{
		write(SYS_CTRL::__address, value, 8);
	}
	
	/* Get register SYS_CTRL */
	uint8_t getSYS_CTRL()
	{
		return read8(SYS_CTRL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG SYS_STAT                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG SYS_STAT:
	 * System status
	 */
	struct SYS_STAT
	{
		static const uint16_t __address = 17;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits SYS_ACTIVE: */
		/* The system power state  */
		struct SYS_ACTIVE
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t Standby = 0b0; // System is in standby or booting state
			static const uint8_t Active = 0b1; // System is in active state
		};
	};
	
	/* Set register SYS_STAT */
	void setSYS_STAT(uint8_t value)
	{
		write(SYS_STAT::__address, value, 8);
	}
	
	/* Get register SYS_STAT */
	uint8_t getSYS_STAT()
	{
		return read8(SYS_STAT::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG SENS_RUN                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG SENS_RUN:
	 * The run mode (single shot or continuous)
	 */
	struct SENS_RUN
	{
		static const uint16_t __address = 33;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b11111100; // [2,3,4,5,6,7]
		};
		/* Bits H_RUN: */
		/* The run mode of the relative humidity sensor  */
		struct H_RUN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t SingleShot = 0b0; // Relative humidity sensor operates in single shot mode
			static const uint8_t Continuous = 0b1; // Relative humidity sensor operates in continuous mode
		};
		/* Bits T_RUN: */
		/* The run mode of the temperature sensor  */
		struct T_RUN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t SingleShot = 0b0; // Temperature sensor operates in single shot mode
			static const uint8_t Continuous = 0b1; // Temperature sensor operates in continuous mode
		};
	};
	
	/* Set register SENS_RUN */
	void setSENS_RUN(uint8_t value)
	{
		write(SENS_RUN::__address, value, 8);
	}
	
	/* Get register SENS_RUN */
	uint8_t getSENS_RUN()
	{
		return read8(SENS_RUN::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG SENS_START                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG SENS_START:
	 * Start measurement
	 */
	struct SENS_START
	{
		static const uint16_t __address = 34;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b11111100; // [2,3,4,5,6,7]
		};
		/* Bits H_START: */
		/* Write a 1 to start a relative humidity sensor measurement.  */
		struct H_START
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits T_START: */
		/* Write a 1 to start a temperature sensor measurement.  */
		struct T_START
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register SENS_START */
	void setSENS_START(uint8_t value)
	{
		write(SENS_START::__address, value, 8);
	}
	
	/* Get register SENS_START */
	uint8_t getSENS_START()
	{
		return read8(SENS_START::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG SENS_STOP                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG SENS_STOP:
	 * Stop continuous measurement
	 */
	struct SENS_STOP
	{
		static const uint16_t __address = 35;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b11111100; // [2,3,4,5,6,7]
		};
		/* Bits H_STOP: */
		/* Write a 1 to stop a continuous relative humidity sensor measurement.  */
		struct H_STOP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits T_STOP: */
		/* Write a 1 to stop a continuous temperature sensor measurement.  */
		struct T_STOP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register SENS_STOP */
	void setSENS_STOP(uint8_t value)
	{
		write(SENS_STOP::__address, value, 8);
	}
	
	/* Get register SENS_STOP */
	uint8_t getSENS_STOP()
	{
		return read8(SENS_STOP::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG SENS_STAT                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG SENS_STAT:
	 * Sensor status (idle or measuring)
	 */
	struct SENS_STAT
	{
		static const uint16_t __address = 36;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b11111100; // [2,3,4,5,6,7]
		};
		/* Bits H_STAT: */
		/*
		 * Indicates the measuring status of the relative humidity sensor
		 * Write a 1 to stop a continuous relative humidity sensor measurement.
		 */
		struct H_STAT
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t Idle = 0b0; // 
			static const uint8_t Active = 0b1; // 
		};
		/* Bits T_STAT: */
		/*
		 * The run mode of the temperature sensor.
		 * Write a 1 to stop a continuous temperature sensor measurement.
		 */
		struct T_STAT
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t Idle = 0b0; // 
			static const uint8_t Active = 0b1; // 
		};
	};
	
	/* Set register SENS_STAT */
	void setSENS_STAT(uint8_t value)
	{
		write(SENS_STAT::__address, value, 8);
	}
	
	/* Get register SENS_STAT */
	uint8_t getSENS_STAT()
	{
		return read8(SENS_STAT::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG T_VAL                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG T_VAL:
	 * This 3 byte register contains the last measured temperature data. Furthermore it has a
	 * data valid flag and a CRC over the former two. Note that these bytes are double buffered;
	 * they are latched in by accessing the first byte, see The Sensor Readout Registers for
	 * details.
	 */
	struct T_VAL
	{
		static const uint16_t __address = 48;
		
		/* Bits T_CRC: */
		/* CRC over T_DATA and T_VALID § */
		struct T_CRC
		{
			static const uint32_t mask = 0b111111100000000000000000; // [17,18,19,20,21,22,23]
		};
		/* Bits T_VALID: */
		/* Data valid indication (1 means T_DATA is valid) § */
		struct T_VALID
		{
			static const uint32_t mask = 0b000000010000000000000000; // [16]
		};
		/* Bits T_DATA: */
		/* Last measured temperature, stored as a little endian 16 bits unsigned value in 1/64 Kelvin § */
		struct T_DATA
		{
			static const uint32_t mask = 0b000000001111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register T_VAL */
	void setT_VAL(uint32_t value)
	{
		write(T_VAL::__address, value, 24);
	}
	
	/* Get register T_VAL */
	uint32_t getT_VAL()
	{
		return read32(T_VAL::__address, 24);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG H_VAL                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG H_VAL:
	 * This 3 byte register contains the last measured relative humidity data. Furthermore it
	 * has a data valid flag and a CRC over the former two. Note that these bytes are double
	 * buffered; they are latched in by accessing the first byte, see The Sensor Readout Registers
	 * for details.
	 */
	struct H_VAL
	{
		static const uint16_t __address = 51;
		
		/* Bits H_CRC: */
		/* CRC over H_DATA and H_VALID */
		struct H_CRC
		{
			static const uint32_t mask = 0b111111100000000000000000; // [17,18,19,20,21,22,23]
		};
		/* Bits H_VALID: */
		/* Data valid indication (1 means H_DATA is valid) */
		struct H_VALID
		{
			static const uint32_t mask = 0b000000010000000000000000; // [16]
		};
		/* Bits H_DATA: */
		/* Last measured relative humidity, stored as a little endian 16 bits unsigned value in 1/512%RH */
		struct H_DATA
		{
			static const uint32_t mask = 0b000000001111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register H_VAL */
	void setH_VAL(uint32_t value)
	{
		write(H_VAL::__address, value, 24);
	}
	
	/* Get register H_VAL */
	uint32_t getH_VAL()
	{
		return read32(H_VAL::__address, 24);
	}
	
};
