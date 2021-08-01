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

    printf("%s\n", lcd.data);
    printf("key pressed: %c\n", key.key);
    printf("led %s\n", led.led_color == verde ? "verde\0" : "vermelho\0");
    printf("sensor 1 data: %f\n", sensorsData.sensor1);
    printf("sensor 2 data: %f\n", sensorsData.sensor2);
    printf("CPU use: %.2f\n", systemUse);

    lcd.data = "";
    key.key = "";
    led.led_color = 0;
    sensorsData.sensor1 = 0;
    sensorsData.sensor1 = 0;
    systemUse = 0;

    xQueueOverwrite(mb->mb_lcd, &lcd);
}