#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*void pArr(int arr[], int n) {  
    for(inti=0; i<n; i++) 
        printf("%d ", arr[i]); 
}*/

//#define tam 100;

int main() {

    int tam, aux = 0;
    int lDir[100], lEsq[100];
    char l;

    for (int i = 0; i < 100; ++i){
        lDir[i] = 0;
    }
    for (int j = 0; j < 100; ++j){
        lEsq[j] = 0;
    }

    while(1){

        //scanf("%d %c ", &tam, &l);

        if(scanf("%d %c ", &tam, &l) != EOF){
            if (l == 'D'){
                lDir[tam] = lDir[tam] + 1;
            } else if (l == 'E'){
                lEsq[tam] = lEsq[tam] + 1;
            }
            if(lDir[tam] != 0 && lEsq[tam] != 0){
                aux++;
                lEsq[tam] = lEsq[tam] - 1;
                lDir[tam] = lDir[tam] - 1;
            }
        }else{
            printf("%d\n", aux);
            return 0;
        }
    }
    return 0;
}


