/*
 * modbus_crc.c
 *
 *  Created on: Feb 15, 2025
 *      Author: ishanchitale
 */

#include <stdint.h>
#include "modbus_crc.h"

uint16_t CRC16(uint8_t *buffer, uint16_t buffer_length) {
	uint8_t crc_hi = 0xFF; /* high byte of CRC initialized */
	uint8_t crc_lo = 0xFF; /* low byte of CRC initialized */
	unsigned int i; /* will index into CRC lookup table */

	while (buffer_length > 0) {
		buffer_length--;
		i = crc_lo ^ *buffer++; /* calculate the CRC */
		crc_lo = crc_hi ^ table_crc_hi[i];
		crc_hi = table_crc_lo[i];
	}
	return (crc_hi << 8 | crc_lo);
}
