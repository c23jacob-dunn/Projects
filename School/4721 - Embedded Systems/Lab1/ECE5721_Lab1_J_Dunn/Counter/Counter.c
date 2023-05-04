#include <MKL25Z4.h>
unsigned int counter = 0;
/*---------------------------------------------
 MAIN function
*---------------------------------------------*/
int main (void) {
	SystemCoreClockUpdate();
	while(1) {  
		counter++;
		if (counter > 0x0F) counter = 0; //Counts up to 15
	}
}