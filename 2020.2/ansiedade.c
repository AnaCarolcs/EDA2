#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

    int sim = 0, nao = 0, final = 0, ana = 0;
    char resp[10];

    while(1){
        if(scanf("%s",resp) != EOF){
            ana++;

            if(resp[0] == 'n'){
                nao++;
            } else if(resp[0] == 's') {
                sim++;
            }

            if(ana >= 10){
                ana = 0;
                
                if(sim >= 2){
                    final++;
                }
                sim = 0;
                nao = 0;
            }
        } else {
            printf("%d\n",final);
            return 0;
        }
    }
}
