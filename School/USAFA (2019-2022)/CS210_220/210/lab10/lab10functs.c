/** lab10.c
* ===========================================================
* Name: Jacob Dunn / 9 SEP 2020
* Section: M3
* Project: Lab10
* Purpose: Learn Code
* ===========================================================
*/

#include "lab10functs.h"

bool isFirstHalfAlpha(char alpha){
    if((alpha > 64 && alpha < 78) || (alpha > 96 && alpha < 110)){
        return 1;
    }
    else{
        return 0;
    }
}

int typeOfChar(char bravo){
    if ((bravo > 64 && bravo < 91) || (bravo > 96 && bravo < 123)){
        switch(bravo){
            case 65:
            case 69:
            case 73:     
            case 79:
            case 85:
            case 97:
            case 101:
            case 105:       
            case 111: 
            case 117:  
                return 1;
                break;
            default:
                return 0;
                break;
        }  
    }
    else {
        return -1;
    }  
}

bool isMagicChar(char charlie){
    if (charlie == MAGIC_CHAR){
        return true;
    }
    else{
        return false;
    }
}