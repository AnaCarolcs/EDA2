#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n;
    scanf("%d",&n);

    int nota, mNota, qmNota, ana = 0;
    int v[1001] = {0};

    //for(int i = 0; i < n; i++){}

    mNota = - 1;
    qmNota = 0;
    while(ana < n){
        scanf("%d",&nota);
        v[nota]++;

        if(((v[nota] == qmNota) && (nota > mNota)) || v[nota] > qmNota){
            qmNota = v[nota];
            mNota = nota;
        }
    ana++;
    }

    printf("%d\n",mNota);

    return 0;
}

