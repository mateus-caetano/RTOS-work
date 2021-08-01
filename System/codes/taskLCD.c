#include <System.h>

void taskLCD(void *data)
{
    struct systemData *mb = (struct systemData *)data;
    struct LCDData lcd;
    struct ledState led;
    struct sensorData sensorsData;
    struct keyPressed key;
    cpuUse systemUse;

    xQueuePeek(mb->mb_lcd, &lcd, pdMS_TO_TICKS(1));
    xQueuePeek(mb->mb_led, &led, pdMS_TO_TICKS(1));
    xQueuePeek(mb->mb_sensor, &sensorsData, pdMS_TO_TICKS(1));
    xQueuePeek(mb->mb_key, &key, pdMS_TO_TICKS(1));
    xQueuePeek(mb->mb_cpu, &systemUse, pdMS_TO_TICKS(1));

    if (lcd.data != "")
    {
        printf("%s\n", lcd.data);
        printf("key pressed: %c\n", key.key);
        printf("led %s\n", led.led_color == verde ? "verde\0" : "vermelho\0");
        printf("sensor 1 data: %f\n", sensorsData.sensor1);
        printf("sensor 2 data: %f\n", sensorsData.sensor2);
        printf("CPU use: %.2f\n", systemUse);
    }
    lcd.data = "";

    xQueueOverwrite(mb->mb_lcd, &lcd);
    xQueueOverwrite(mb->mb_led, &led);
    xQueueOverwrite(mb->mb_key, &key);
    xQueueOverwrite(mb->mb_sensor, &sensorsData);
}