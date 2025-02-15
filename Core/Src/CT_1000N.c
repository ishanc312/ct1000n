/*
 * modbus.c
 *
 *  Created on: Feb 14, 2025
 *      Author: ishanchitale
 */


#include <CT_1000N.h>

void MODBUS_MASTER_TRANSMIT(uint8_t slaveAddr, uint8_t functionCode, uint16_t registerAddr, uint16_t numRegisters, uint8_t* txData) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
	txData[0] = slaveAddr;
	txData[1] = functionCode;
	txData[2] = (registerAddr >> 8) & 0xFF;
	txData[3] = registerAddr & 0xFF;
	txData[4] = (numRegisters >> 8) & 0xFF;
	txData[5] = (numRegisters & 0xFF);

	uint16_t crc = CRC16(txData, 6);
	txData[6] = (crc & 0xFF);
	txData[7] = (crc >> 8) & 0xFF;

	HAL_UART_Transmit(&huart1, txData, sizeof(txData), HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
}

void MODBUS_MASTER_RECEIVE(uint8_t* rxData) {
	HAL_UARTEx_ReceiveToIdle_IT(&huart1, rxData, sizeof(rxData));
}

// Need a function to compute the idle timing; this is how frames are differentiated!


