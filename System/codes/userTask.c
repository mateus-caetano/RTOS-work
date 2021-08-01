#include <System.h>

void userTask(void * data){
    struct systemData * userData = (struct systemData *) data;

    // Pegando o estado do led:
	struct ledState led;
	xQueuePeek(userData->mb_led,&led,0);

    // Pegando o valor do teclado:
    struct keyPressed key;
    xQueuePeek(userData->mb_key,&key,0);

    // Escrevendo no LCD:
    struct LCDData LCD;
    xQueuePeek(userData->mb_lcd,&LCD,0);
    
    if(led.led_color == 1 && key.key == '1'){
        LCD.n = 20;
        LCD.data = "Testando a entrada";
        printf("%s\n", LCD.data);
    }else{
        LCD.n = 20;
        LCD.data = "Testando o LCD";
        printf("%s\n", LCD.data);
    }

    xQueueOverwrite(userData->mb_lcd, &LCD);


	

}