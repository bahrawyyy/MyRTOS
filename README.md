# MyRTOS

## Table of Contents

1. [Description](#description)
2. [Features](#features)
3. [Tools needed](#tools-needed)
4. [Usage](#usage)
5. [Tasks in action](#tasks-in-action)


---------------------------------------------------------------------------------------------------
### Description
This project is a basic implementation of a Real-Time Operating System (RTOS) from scratch. It provides a foundation for creating embedded systems that require task scheduling and real-time processing. This RTOS implements scheduling algorithms such as Round-Robin, Priority, and Priority-based Round-Robin. It also features mutex support and resolves the priority inversion problem through inheritance. Additionally, the RTOS employs a straightforward solution to prevent deadlock by not allowing tasks to acquire more than one mutex simultaneously.

---------------------------------------------------------------------------------------------------
### Features
- Scheduling Algorithms: Supports Round-Robin, Priority, and Priority-based Round-Robin scheduling.
- Mutex Support: Implements mutexes for synchronization and resource access control.
- Priority Inversion Resolution: Utilizes an inheritance mechanism to address priority inversion problems.
- Deadlock Prevention: Simple solution to prevent deadlocks by disallowing tasks from acquiring more than one mutex.

---------------------------------------------------------------------------------------------------
### Tools needed
- STM32CubeIDE for developing
- Keil uVision for simulation


---------------------------------------------------------------------------------------------------
### Usage
- Define your tasks in the main.c file or create separate task files.
- Configure the RTOS and task priorities.
- Build and load the project onto your target platform.


---------------------------------------------------------------------------------------------------
### Tasks in action
- Priority based round-robin
  - When tasks have the same priority, they run based on round-robin scheduling.
  - Until, another task with higher priority is activated, then the scheduler will choose to run this task till termination or suspending.

![Round-Robin_Priority](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/f3dfce2a-f743-4fc3-bb03-a881eff9ef2c)

- Priority inheritance
  - Priority inheritance is a real-time scheduling technique that temporarily boosts the priority of a task to prevent priority inversion and ensure timely execution of high-priority tasks.
  - Lower priority task inherit the priority from the higher priority task which wants to acquire the mutex, and when releasing the lower priority task restore its original priority.     

![PriorityInversion2](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/dcdd1470-e96a-4427-8054-7b5cd26a2165)



For more details, please refer to this folder 😊💻:  
https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/tree/main/Unit15_CreateYourOwnRTOS

