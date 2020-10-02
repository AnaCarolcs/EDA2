#include<stdio.h>
#include<stdlib.h>

int sep(int *v, int l, int r){
    int c = v[r];
    int j = l, k, aux;
    k = l;
    while(k<r){
        if(v[k]<c){
            aux=v[k];
            v[k]=v[j];
            v[j]=aux;
            j++;
        }
        k++;
    }
    aux=v[k];
    v[k]=v[j];
    v[j]=aux;

    return j;
}

void quickse(int *v, int l, int r, int k){
    int i;
    if(r<=l){
        return;
    }

    i = sep(v,l,r);
    
    if(i>k){
        quickse(v,l,i-1,k);
    }
    if(i<k){
        quickse(v,i+1,r,k);}
    }

void quickso(int *v, int l, int r){
    int j, aux = 0;

    if(r<=l){
        return;
    }

    if(v[(l+r)/2] < v[r]){
        aux=v[(l+r)/2];
        v[(l+r)/2]=v[r];
        v[r]=aux;
    }
    //aux = 0;
    if(v[l] < v[(l+r)/2]){
        aux=v[l];
        v[l]=v[(l+r)/2];
        v[(l+r)/2]=aux;
    }
    //aux = 0;
    if(v[r] < v[(l+r)/2]){
        aux=v[r];
        v[r]=v[(l+r)/2];
        v[(l+r)/2]=aux;
    }

    j = sep(v,l,r);
    
    quickso(v,l,j-1);
    quickso(v,j+1,r);
}

int main(){
    int n, p, x, d=0, h;
    int *id;

    scanf("%d%d%d",&n,&p,&x);
    
    //id = calloc()
    id = malloc(sizeof(int) * n);

    while(d<n){
        scanf("%d", &id[d]);
        d++;
    }
    //h = x*p;
    h = p*x;

    quickse(id,0,n-1,h);
    quickso(id, h, n-1);

    d = 0;
    while(d<x&&h<n){
        printf("%d\n", id[h++]);
        d++;
    }

    return 0;
}