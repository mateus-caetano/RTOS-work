#include <System.h>

#define ECHO
void controlTask(void * controlData)
{
	struct systemData * data = (struct systemData *) controlData;

	float sensor1;
	float sensor2;

	/*Requisitando os sensores*/
	xQueuePeek(data->mb_sensor,&sensor1,pdMS_TO_TICKS(1));
	xQueuePeek(data->mb_sensor,&sensor2,pdMS_TO_TICKS(1));	

	/*Requisitando uso da CPU*/
	cpuUse use;
	xQueuePeek(data->mb_cpu,&use,pdMS_TO_TICKS(1));

	/*Requisitando estado dos leds*/
	struct ledState led;
	xQueuePeek(data->mb_led,&led,pdMS_TO_TICKS(1));


	/*Atualizando LED*/
	if(use > 0.8)
	{
		led.led_color = vermelho;
	}
	else
	{
		led.led_color = verde;	
	}	
	xQueueOverwrite(data->mb_led,&led);

	#ifdef ECHO
	printf("control task sensor1=%f sensor2=%f cpu=%f  \n",sensor1,sensor2,use);
	#endif
}
