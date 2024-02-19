#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    srand((unsigned int)time(NULL));
    int numDice = 0, dice = 0;
    int result[1000];

    while(1){
        printf("enter a dice size (xdx): ");
        scanf("%dd%d", &numDice, &dice);
        if(numDice > 1000 || dice > 1000){printf("cannot handle dice larger than 1000");}

        //roll the die
        for(int i = 0; i < numDice; i++){
            result[i] = rand() % (dice+1);
            printf(" [%d]", result[i]);
        }

    }

    return 0;
}