#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for random seed lul
#include <string.h>

#define NUM_MODIFIERS 6
#define LABEL_OFFSET 8 //standard label length in the stats file

int main(){

    srand((unsigned int)time(NULL)); //set random seed

    int numDice = 0, dice = 0;
    int result[1000];

    int att[NUM_MODIFIERS * 2]; //set attributes (multiplied by 2 to hold both true values and modifier values)
    att[0] = 69;

    FILE *stats;
    stats = fopen("stats.txt", "r"); //open file

    if(stats == NULL){
        printf("Failed to access stats file!\n"); //sad trombone
        return 0;
    }else{
        printf("Successfully accessed stats file.\n");

        // char buffer[7];

        // fscanf(stats, "%s", buffer);

        // printf("%s", buffer);

        for (size_t i = 0; i < NUM_MODIFIERS * 2; i++)
        {
            fseek(stats, LABEL_OFFSET * (i+1), 0); //move to the correct value
            fscanf(stats, "%s", att); 
            rewind(stats);
            printf("%s\n", att);
        }
        fclose(stats);

        // for (size_t i = 0; i < NUM_MODIFIERS * 2; i++)
        // {
        //     printf("%d = %d\n", i, att[i]);
        // }
    }

    printf(" str = %d", att[5]);

    // while(1){
    //     printf("enter a dice size (xdx): ");
    //     scanf("%dd%d", &numDice, &dice);
    //     if(numDice > 1000 || dice > 1000){printf("cannot handle dice larger than 1000");}

    //     //roll the die
    //     for(int i = 0; i < numDice; i++){
    //         result[i] = rand() % (dice+1);
    //         printf(" [%d]", result[i]);
    //     }

    // }

    return 0;
}