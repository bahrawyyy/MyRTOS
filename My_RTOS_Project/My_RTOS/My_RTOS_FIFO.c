/*
 * My_RTOS_FIFO.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Abdallah
 */


#include "My_RTOS_FIFO.h"



/**================================================================
 * @Fn                - FIFO_Init
 * @brief             - Initializes a FIFO (First-In-First-Out) buffer
 * @param [in]        - fifo: Pointer to the FIFO buffer structure
 * @param [in]        - Buffer: Pointer to the data buffer
 * @param [in]        - length: Maximum number of elements the FIFO can hold
 * @retval            - FIFO_Status: Status code indicating the result of initialization
 * Note              - Call this function to initialize a FIFO buffer for data storage.
 */

FIFO_Status FIFO_Init(FIFO_Buffer_t *fifo, Element_Type* Buffer, uint32_t length)
{
	if(!Buffer)
		return FIFO_Null;


	fifo->base = Buffer;
	fifo->head = fifo->base;
	fifo->tail = fifo->base;
	fifo->length = length;
	fifo->counter = 0;

	return FIFO_No_Error;


}



/**================================================================
 * @Fn                - FIFO_Enqueue
 * @brief             - Enqueues an item into the FIFO buffer
 * @param [in]        - fifo: Pointer to the FIFO buffer structure
 * @param [in]        - Item: Element to be enqueued
 * @retval            - FIFO_Status: Status code indicating the result of the enqueue operation
 * Note              - Call this function to add an element to the FIFO buffer.
 */



FIFO_Status FIFO_Enqeue(FIFO_Buffer_t *fifo, Element_Type Item)
{
	// Check if the FIFO is valid
	if(!fifo->base || !fifo->length)
		return FIFO_Null;

	// Full FIFO
	if((fifo->head == fifo->tail) && (fifo->counter == fifo->length))
		return FIFO_Full;


	*(fifo->tail) = Item;
	fifo->counter++;


	// Handle Circular Queue
	if((uint32_t)fifo->tail == (((uint32_t)fifo->base + (4*fifo->length)) - 4))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_No_Error;
}



/**================================================================
 * @Fn                - FIFO_Dequeue
 * @brief             - Dequeues an item from the FIFO buffer
 * @param [in]        - fifo: Pointer to the FIFO buffer structure
 * @param [out]       - Item: Pointer to store the dequeued element
 * @retval            - FIFO_Status: Status code indicating the result of the dequeue operation
 * Note              - Call this function to remove an element from the FIFO buffer.
 */




FIFO_Status FIFO_Deqeue(FIFO_Buffer_t *fifo, Element_Type* Item)
{
	// Check if the FIFO is valid
	if(!fifo->base || !fifo->length)
		return FIFO_Null;

	// Empty FIFO(Nothing to deqeue)
	if(fifo->head == fifo->tail)
		return FIFO_Empty;

	*Item = *(fifo->head);
	fifo->counter--;


	// Circular deqeue
	if((uint32_t)(fifo->head) == (((uint32_t)fifo->base + (4*fifo->length)) - 4))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_No_Error;

}


/**================================================================
 * @Fn                - FIFO_Is_Full
 * @brief             - Checks if the FIFO buffer is full
 * @param [in]        - fifo: Pointer to the FIFO buffer structure
 * @retval            - FIFO_Status: Status code indicating the buffer's fullness
 * Note              - Call this function to check if the FIFO buffer is full.
 */

FIFO_Status FIFO_Is_Full(FIFO_Buffer_t *fifo)
{

	if(!fifo->head || !fifo->base || !fifo->tail)
		return FIFO_Null;

	if(fifo->counter == fifo->length)
		return FIFO_Full;

	return FIFO_No_Error;
}
