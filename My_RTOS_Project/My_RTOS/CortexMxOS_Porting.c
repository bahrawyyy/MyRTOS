/*
 * CortexMxOS_Porting.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Abdallah
 */

#include "CortexMxOS_Porting.h"
#include "Schedular.h"
#include "Schedular_Private.h"




/**
 *
 * 	// These functions are fault handlers for various types of faults that can occur in the system.
	// They are designed to handle and indicate that a fault has occurred by entering an infinite loop.
 *
 *
 *
 */



/**
 * @Fn       				- HardFault_Handler
 * @brief    				- Handles hard faults, typically resulting from serious system errors.
 *           				- If a hard fault occurs, this function enters an infinite loop to indicate a fault.
 * @param [in] 				- None
 * @retval   				- None
 * @note     				- None
 */



void HardFault_Handler()
{
	while(1);
}


/**
 * @Fn       				- MemManage_Handler
 * @brief    				- Handles memory management faults, which occur when accessing invalid memory regions.
 *           				If a memory management fault occurs, this function enters an infinite loop to indicate a fault.
 * @param [in] 				- None
 * @retval   				- None
 * @note     				- None
 */

void MemManage_Handler()
{
	while(1);
}

/**
 * @Fn       				- BusFault_Handler
 * @brief    				Handles bus faults, which occur when there are issues with memory accesses or bus errors.
 *           				If a bus fault occurs, this function enters an infinite loop to indicate a fault.
 * @param [in] 				- None
 * @retval   				- None
 * @note     				- None
 */




void BusFault_Handler()
{
	while(1);
}


/**
 * @Fn       				- UsageFault_Handler
 * @brief    				Handles usage faults, which occur when there are issues with instruction execution.
 *          			    If a usage fault occurs, this function enters an infinite loop to indicate a fault.
 * @param [in] 				- None
 * @retval   				- None
 * @note     				- None
 */


void UsageFault_Handler()
{
	while(1);
}



/**
 * @Fn       			- SVC_Handler
 * @brief    			- A naked assembly function that handles Supervisor Call (SVC) exceptions.
 *           			This function checks the EXC_RETURN value to determine if the function was called from
 *           			the Main Stack Pointer (MSP) or the Process Stack Pointer (PSP). It then branches to
 *           			the OS_SVC_Services function accordingly.
 * @param [in] 			- None
 * @retval   			- None
 * @note     			- None
 */


// Consider it as C function, but don't push anything in stack, it is assembly, force the compiler to not add anything
__attribute ((naked))  void SVC_Handler()
{
	// Check EXC_Return to see if you were MSP or PSP
	__asm("tst lr,#4 \n\t"
			"ITE EQ \n\t"
			"mrseq r0,MSP \n\t"
			"mrsne r0,PSP \n\t"
			"B OS_SVC_Services");
}


/**
 * @Fn       			- Trigger_OS_PendSV
 * @brief    			- Triggers a PendSV exception request, which is used for context switching in an OS.
 *           			This function sets the PENDSVSET bit in the Interrupt Control and State Register (ICSR) to
 *           			request a PendSV exception.
 * @param [in] 			- None
 * @retval     			- None
 * @note       			- None
 */

void Trigger_OS_PendSV()
{
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}


/**================================================================
 * @Fn					- HW_Init
 * @brief 				- This function sets up the clock tree for an 8 MHz system clock (by default) and
 * 							adjusts NVIC priorities, specifically lowering the priority of the PendSV interrupt
 * 							to be less than or equal to the SysTick timer (priority 14).
 * @param [in] 			- None
 * @retval 				- None
 * Note					- None
 *
 */



void HW_Init()
{
	// Initialize clock tree (RCC --> SysTick Timer & CPU) 8MHz
	// 8 MHz (By default)
	// 1 count = 0.125 us
	// X count -> 1ms
	// X = 8000 counts

	// Decrease priority of pendSV to be less than or equal systick timer
	// systick = 14

	__NVIC_SetPriority(PendSV_IRQn,15);
}



/**================================================================
 * @Fn					- Start_Ticker
 * @brief 				- Initializes the SysTick timer to generate periodic interrupts at a 1ms interval.
 * 						 his function configures the SysTick timer to generate an interrupt every 1ms.
 * @param [in] 			- None
 * @retval 				- None
 * Note					- It assumes an 8 MHz system clock, where 1 count of SysTick corresponds to 0.125 microseconds.
 *						 The SysTick_Config function sets the reload value to 8000 counts, resulting in a 1ms period.
 */


void Start_Ticker()
{
	// 8 MHz (By default)
	// 1 count = 0.125 us
	// X count -> 1ms
	// X = 8000 counts

	SysTick_Config(8000);

}


uint8_t SystTickIndication;


/**
 * @Fn       			- SysTick_Handler
 * @brief    			- Handles the SysTick interrupt, indicating system time, updating task waiting times,
 *           			deciding the next task to run, and triggering a PendSV exception to switch context and restore.
 * @param [in] 			- None
 * @retval   			- None
 * @note     			- None
 */

void SysTick_Handler(void)
{
	SystTickIndication ^= 1;
	MYRTOS_Update_Tasks_WaitingTime();
	// Decide what Next (To determine Pcurrent, Pnext)
	Decide_WhatNextTask();
	// Trigger PendSv(Switch Context & Restore)
	Trigger_OS_PendSV();
}
