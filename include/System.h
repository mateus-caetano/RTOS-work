#ifndef SYSTEM_H
#define SYSTEM_H

/* Sistemas de tempo Real  2020.1 - Trabalho 1
 *
 * @autor:Francisco Thiago dos Santos Gonçalves
 * @autor:
 * @autor:
 *
 * data:
 */

#include <FreeRTOS.h>

/*------------Definição das tasks------------*/
/* nome: controlTask
 * Função:
 * 	Requisitar os dados dos sensores por meio de uma mail box com um dead line de 10ms
 * 	Verificar comandos enviados pela userTask
 *	Atualizar o estado do LED
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	userComand
 * 	sensorData
 * 	ledState
 * 	cpuUse
 */
static void controlTask(void * controlData);

/* nome: ledToggle
 * Função:
 * 	Atualiza o estado (ligado e desligado) e a cor do LED  
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	ledState
 */
static void ledToggle(void *ledState);

/* nome: userTask
 * Função:
 * 	Espera a entrada do teclado numérico, e atualiza os dados do LCD.
 *	Como não temos um led físico, ele deve mostrar o estado do led
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	ledState
 * 	keyPressed
 * 	LCDData
 */
static void userTask(void * data);

/* nome: taskScanner
 * Função:
 * 	Espera a entrada do teclado numérico e informa
 * 	a userTask
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	keyPressed
 */
static void taskScanner(void * keyPressed);

/* nome: userLCD
 * Função:
 * 	Atualiza o LCD
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	LCDData
 */
static void taskLCD(void * data);

/* nome: taskSensores
 * Função:
 * 	Atualiza os sensores
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	sensorData
 */
static void taskSensores(void * barramento);
static void PDA(void * controlData);

/* nome: taskSensores
 * Função:
 * 	Atualiza o uso da CPU
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	cpuUse
 */
static void monitor(void * data);
#endif
