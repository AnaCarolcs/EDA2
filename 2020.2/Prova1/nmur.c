#include <stdio.h>
#include <stdlib.h>

int separa(int *v, int l, int r){
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

void quicksort(int *v,int l, int r){
  
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

    j = separa(v,l,r);
  
  	quicksort(v,l,j-1);
  	quicksort(v,j+1,r);
}

int duplicados(int arr[], int n){

	if (n==0 || n==1)
	return n;

	int temp[n];

	int j = 0;
	int i;
	for (i=0; i<n-1; i++)
	if (arr[i] != arr[i+1])
	temp[j++] = arr[i];
	temp[j++] = arr[n-1];

	for (i=0; i<j; i++)
	arr[i] = temp[i];

	return j;
}

int * somaDupla(int *v, int n){
	int *novoV; 
	novoV = malloc(sizeof(int) * n/2);
	int soma = 0, aux = 0;
	for (int i = 0; i < n; i+=2){
		soma = v[i] + v[i+1];
		novoV[aux] = soma;
		aux++;
	}
	return novoV;
}

int main(){
	
	int n, i = 0, j = 0, *w;
	int *v;

	scanf("%d", &n);


	v = malloc(sizeof(int) * n);
	w = malloc(sizeof(int) * n/2);

	for (i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}

	quicksort(v, 0, n-1);

	n = duplicados(v, n);

	if(n % 2 == 1){
		v[n] = 1000000000;
		n++;
	}

	w = somaDupla(v, n);

	int antigoN = n;

	n = n + n/2;

	v = realloc(v, sizeof(int) * n);

	for (int s = antigoN, ana = 0; s < n; s++, ana++){
		v[s] = w[ana];
	}

	/*for(int sa = 0; sa < n; sa++){
		printf("%d ", v[sa]);
	}*/

	quicksort(v, 0, n-1);

	n = duplicados(v, n);

	for(int s = 0; s <= n; s=s+4){
		printf("%d\n", v[s]);
	}

	//printf("\n");

	printf("Elementos: %d\n", n);
	
	return 0;
}