/*
 * modbus.h
 *
 *  Created on: Feb 14, 2025
 *      Author: ishanchitale
 */

#ifndef INC_CT_1000N_H_
#define INC_CT_1000N_H_

#include "usart.h"
#include "gpio.h"
#include "modbus_crc.h"
#include <stdint.h>

void MODBUS_MASTER_TRANSMIT(uint8_t slaveAddr, uint8_t functionCode, uint16_t registerAddr, uint16_t numRegisters, uint8_t* txData);
void MODBUS_MASTER_RECEIVE(uint8_t* rxData);

#endif /* INC_CT_1000N_H_ */
