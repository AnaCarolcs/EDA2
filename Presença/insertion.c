#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define less(a, b) (a<b)
#define exch(a, b) {int t = a; a = b; b = t;}
#define cmpexch(a, b) {if(less(b,a)) exch(a, b);}

void insertionSort(int *v, int l, int r) {
    for(int i=r; i>l; i--)
        cmpexch(v[i-1], v[i]);

    for(int i=l+2; i<=r; i++) {
        int j = i;
        int tmp = v[j];
        while (less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}

int main() {

    int *vetor;
    int i=0, j;
    
    vetor = malloc(sizeof(int));
    
    while (scanf("%d", &vetor[i])==1) {
        i++;
        vetor = realloc(vetor, (i+1)*sizeof(int));
    }
    
    insertionSort(vetor, 0, i-1);

    for(j=0; j<i-1; j++){
        printf("%d ", vetor[j]);
    }
    
    printf("%d\n", vetor[j]);
    
    free(vetor);
    return 0;
}