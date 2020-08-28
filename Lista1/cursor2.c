#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void quandoJ(int coluna, int linha){
    if(c>=strlen(texto[linha])){
    	long int res1 = strlen(texto[linha]);
    	char res2 = texto[linha][strlen(texto[linha])-1];
    	printf("%d %ld %c\n", linha+1, res1, res2);
    } else if(strlen(texto[linha])==0){
    	printf("%d %d\n", linha+1, coluna+1);
    }else
       	printf("%d %d %c\n", linha+1, coluna+1, texto[linha][coluna]);
}

void quandoK(int coluna, int linha){
    if(coluna>=strlen(texto[linha])){
        long int res3 = strlen(texto[linha]);
   		char res4 = texto[linha][strlen(texto[linha])-1];
        printf("%d %ld %c\n", linha+1, res3, res4);
    } else if(strlen(texto[linha])==0){
        printf("%d %d\n", linha+1, coluna+1);
    } else
        printf("%d %d %c\n", linha+1, coluna+1, texto[linha][coluna]);
}*/

int main(){

	//char vetor[1000];
	char aux, **texto;
	int n, linha, coluna, it=0;

	scanf("%d", n);
	texto = malloc(n * sizeof(char *));


  
  	while(it<n){ //alocando espaço
    	texto[it] = malloc(1000 * sizeof(char));
    	it++;
  	}

  	while(it>n){ 
    	scanf("%[^\n]", texto[it]);
    	it--;
  	}

	scanf("%d %d", &linha, &coluna);

	while(scanf("%c",&aux)==1){
		if(aux == 'j'){
			if(linha+1<n)
    			linha++;
    		if(coluna>=strlen(texto[linha])){
    			long int res1 = strlen(texto[linha]);
    			char res2 = texto[linha][strlen(texto[linha])-1];
    			printf("%d %ld %c\n", linha+1, res1, res2);
    		} else if(strlen(texto[linha])==0){
    			printf("%d %d\n", linha+1, coluna+1);
    		}else
       			printf("%d %d %c\n", linha+1, coluna+1, texto[linha][coluna]);
			//quandoJ();
    	} else if (aux == 'k'){
    		if(linha-1>=0)
        		linha--;
        	if(coluna>=strlen(texto[linha])){
        		long int res3 = strlen(texto[linha]);
    			char res4 = texto[linha][strlen(texto[linha])-1];
        		printf("%d %ld %c\n", linha+1, res3, res4);
    		} else if(strlen(texto[linha])==0){
        		printf("%d %d\n", linha+1, coluna+1);
    		} else
        		printf("%d %d %c\n", linha+1, coluna+1, texto[linha][coluna]);
        	//quandoK();
    	}
	} 

	//free(texto);
	return 0;
}