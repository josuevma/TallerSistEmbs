/*
===============================================================================
 Name        : Project_LPCOpen.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

// TODO: insert other include files here


#include "sapi_gpio.h"
#include "sapi_dac.h"
#include "sapi_systick.h"
#include <cr_section_macros.h>

// TODO: insert other definitions and declarations here


//    O N D A    D I E N T E    D E    S I E R R A
//           1 0  K H z   Y    3 , 3 V

/*
uint32_t  j = 0;


int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here

    Init_Tick(TICK_10US);

    dacInit(DAC_ENABLE);
    // Force the counter to be placed into memory

    // Enter an infinite loop, just incrementing a counter
    while(1) {
        		if(j < 1023){
        			dacWrite(DAC,j);
        			}
        		else{
        			dacWrite(DAC,1023);
        			}
        // "Dummy" NOP to allow source level single
        // stepping of tight while() loop
        __asm volatile ("nop");
    }
    return 0 ;
}

void SysTick_Handler(void){
	if(j<1023){
		j=j+114;
		}
	else{
		j=0;
		}
	}

*/




//      O N D A  S E N O I D A L
//      1 0  K H z    y    3 , 3 V

/*
uint16_t  señal_seno[]={511,716,921,1023,818,613,408,203,0,255};


uint32_t  j = 0;

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif





    // TODO: insert code here

    Init_Tick(TICK_10US);

    dacInit(DAC_ENABLE);
    // Force the counter to be placed into memory

    // Enter an infinite loop, just incrementing a counter
    while(1) {

        // "Dummy" NOP to allow source level single
        // stepping of tight while() loop
        __asm volatile ("nop");
    }
    return 0 ;

}


void SysTick_Handler(void){
    	if(j<9){
    		dacWrite(DAC,señal_seno[j]);
    		j++;
    		}
    	else{
    		dacWrite(DAC,señal_seno[j]);
    		j=0;
    		}
}

*/






// 			    P U L S A D O R E S    C O N
//           S  E  Ñ  A  L E  S    D I E N T E   D E   S I E R R A


uint32_t  j = 0;
uint32_t  señal = 0;
uint32_t valor1=0;
uint32_t valor2=0;
uint32_t valor3=0;
uint32_t valor4=0;
uint32_t A = 0;

int main(void) {



#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here
    Init_Tick(TICK_10US);

    dacInit(DAC_ENABLE);

    // TECLA 1
    gpioInit(0,21,GPIO_INPUT_PULLUP);
    // TECLA 2
    gpioInit(0,22,GPIO_INPUT_PULLUP);
    // TECLA 3
    gpioInit(0,27,GPIO_INPUT_PULLUP);
    // TECLA 4
    gpioInit(0,28,GPIO_INPUT_PULLUP);



    // Force the counter to be placed into memory

    // Enter an infinite loop, just incrementing a counter
    while(1) {
    	switch(señal){
	case 1:					// S E Ñ A L  1 0  K H z  Y  3 , 3 V
		if(j<A){
			dacWrite(DAC,j);
			j=j+114;
			}
		else{
			dacWrite(DAC,1023);
			j=0;
			}
		break;


	case 2:					// S E Ñ A L  1 K H z  Y  3 , 3 V
		if(j<A){
			dacWrite(DAC,j);
			j=j+10;
			}
		else{
			dacWrite(DAC,1023);
			j=0;
			}
		break;

	case 3:						// S E Ñ A L  1  K H z  Y  1 , 6 5 V
		if(j<A){
			dacWrite(DAC,j);
			j=j+5;
			}
		else{
			dacWrite(DAC,512);
			j=0;
			}
		break;

	case 4:						// S E Ñ A L  1 0 K H z  Y  1 , 6 5 V
		if(j<A){
			dacWrite(DAC,j);
			j=j+57;
			}
		else{
			dacWrite(DAC,512);
			j=0;
			}
		break;
    	}
        // "Dummy" NOP to allow source level single
        // stepping of tight while() loop
        __asm volatile ("nop");
    }
    return 0 ;
}

void SysTick_Handler(void){

			valor1  =! gpioRead(0,21); // Testea Tecla 1
		    	if (valor1==1){
		    		señal = 1;
		    		A = 1023;
		    		}



		    	valor2  =! gpioRead(0,22); // Testea Tecla 2
		    	if (valor2==1){
		    		señal = 2;
		    		A = 990;
		    		}



			valor3  =! gpioRead(0,27); // Testea Tecla 3
		    	if (valor3==1){
		    		señal = 3;
		    		A = 495;
		    		}



		 	 valor4  =! gpioRead(0,28); // Testea Tecla 4
		    	if (valor4==1){
		    		señal = 4;
		    		A = 512;
		    	 	}


	}
