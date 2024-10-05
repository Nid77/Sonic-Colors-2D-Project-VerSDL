

#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int main(){

    float posy=20;
    float posx=10;
    float diviseury=posy/posx;
    float diviseurx=posx/posy;

    while (posx!=0 && posy!=0){
        posy-=diviseury;
        posx-=diviseurx;
        printf("posx:%f,posy:%f\n", posx,posy);
    }

}
