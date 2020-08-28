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

	char aux, **texto;
	int n, linha, coluna, it=0;
  
  	scanf("%d", &n);
  
  	texto = malloc(n * sizeof(char *));
  
  	while(it<n){ //alocando espaço
    	texto[it] = malloc(1000 * sizeof(char));
    	it++;
  	}

  	/*it = 0;
  	while(it<n){ 
    	scanf("%[^\n]", texto[it]);
    	it++;
  	}*/

  	for(int j=0; j<n; j++){
    	scanf(" %[^\n]", texto[j]);
  	}
  
  	scanf("%d %d", &linha, &coluna);
  	
  	int nl = linha - 1;
  	int cl = coluna - 1;
  
  while(scanf("%c",&aux)==1){
    if(aux=='j'){
      if(nl+1<n)
        nl++;
      if(cl>=strlen(texto[nl])){
      	long int res1 = strlen(texto[nl]);
    	char res2 = texto[nl][strlen(texto[nl])-1];
    	printf("%d %ld %c\n", nl+1, res1, res2);
      } else if(strlen(texto[nl])==0)
      	printf("%d %d\n", nl+1, cl+1);
      else
        printf("%d %d %c\n", nl+1, cl+1, texto[nl][cl]);
    }
   		//quandoJ();
    else if(aux=='k'){
      if(nl-1>=0)
        nl--;
      if(cl>=strlen(texto[nl])){
      	long int res3 = strlen(texto[nl]);
    	char res4 = texto[nl][strlen(texto[nl])-1];
        printf("%d %ld %c\n", nl+1, res3, res4);
    	}
      else if(strlen(texto[nl])==0)
        printf("%d %d\n", nl +1, cl+1);
      else
        printf("%d %d %c\n", nl+1, cl+1, texto[nl][cl]);
    } 
    //quandoK();
  }

  free(texto);
  return 0;
}