#include <System.h>
#include <stdio.h>
void taskScanner(void * keyPressed)
{
	struct systemData * data = (struct systemData *) keyPressed;
	
	struct keyPressed key;
	fgetc(stdin);

	key.key = fgetc(stdin);
	if(key.key == EOF)  
		key.key = '0';
	else
		key.key = '1';
	xQueueOverwrite(data->mb_key,&key);
	
;
}
