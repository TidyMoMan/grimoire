#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for random seed lul
#include <direct.h> // _getcwd
#include <string.h> // strlen


FILE *stats;

int main(){
    srand((unsigned int)time(NULL));
    int numDice = 0, dice = 0;
    int result[1000];

    char* path;
   // Get the current working directory:
   if( (path = _getcwd( NULL, 0 )) == NULL ){
      perror( "_getcwd error" );
    }
    
    path = strcpy(path, "\\stats.txt");
    stats = fopen(path, "w");

    if(stats == NULL){
        printf("Failed to access stats file!");
        return 0;
    }else{
        printf("Successfully accessed stats file at %s.", path);
    }

    fprintf(stats, "hello!!!");

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