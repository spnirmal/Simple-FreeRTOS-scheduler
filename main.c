#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"



void vTask1(void* pvParams) {
    for (;;) {
        printf("Task 1 running\n");
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay 1000 ms
    }
}

void vTask2(void* pvParams) {
    for (;;) {
        printf("Task 2 running\n");
        vTaskDelay(pdMS_TO_TICKS(1500)); // Delay 1500 ms
    }
}

void vApplicationTickHook(void)
{
   
}
void vApplicationDaemonTaskStartupHook(void)
{
    
}


uint64_t ulGetRunTimeCounterValue(void) {
    // Provide your timer logic here
    return 0;
}

int main(void) {
    xTaskCreate(vTask1, "Task1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTask2, "Task2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    vTaskStartScheduler();

    // Should never reach here
    for (;;);
    return 0;
}
