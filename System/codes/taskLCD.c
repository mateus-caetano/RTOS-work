#include <System.h>

void taskLCD(void *data)
{
    struct systemData *mb = (struct systemData *)data;
    struct LCDData lcd;
    
    xQueuePeek(mb->mb_lcd, &lcd, pdMS_TO_TICKS(1));
    printf("%s",lcd.data);

    lcd.data = "";

    xQueueOverwrite(mb->mb_lcd, &lcd);
;
}
