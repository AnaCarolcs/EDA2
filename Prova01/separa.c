#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b) {item t = a; a = b; b = t;}
#define cmpexch(a,b) {if (less(b,a)) exch(a,b);}

//void quick_sort (item *v, int l, int r);
//int separa (item *v, int l, int r);

int sep( int *a, int p, int r) {
    
    int i, j, x, y;

    i = p;
    j = r;

    x = a[(p + r) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < r) {
            i++;
        }
        while(a[j] > x && j > p) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > p) {
        sep(a, p, j);
    }
    if(i < r) { 
        sep(a, i, r);
    }
}

int main (){

    int tam;

    scanf ("%d", &tam);

    int *v = malloc (tam * sizeof (int));
    int num;

    for (int i = 0; i < tam; i++){
        scanf ("%d", &num);
        v[i] = num;
    }

    sep(v, 0, tam-1);

    for (int j = 0; j < tam; j++){
        if (j != tam-1)
            printf ("%d ", v[j]);
        else
            printf ("%d\n", v[j]);
    }

    return 0;
}
