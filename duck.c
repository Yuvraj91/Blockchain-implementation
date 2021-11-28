#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    FILE *duck = fopen("Duck.txt","a");
    time_t T = time(NULL);
    char cmd[13] = "code Duck.txt";
    fprintf(duck, "\nMe to Duck %02d/%02d/%d", localtime(&T)->tm_mday, localtime(&T)->tm_mon+1, localtime(&T)->tm_year+1900);
    fprintf(duck, " %02d:%02d\n",localtime(&T)->tm_hour, localtime(&T)->tm_min);
    system(cmd);
    fclose(duck);
}