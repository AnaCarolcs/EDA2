## Resposta prova de EDA2

#### T1: Estabilidade de um algoritmo de ordenação

Um algoritmo de ordenação é estável se garante que itens iguais permaneçam na mesmo posição relativa no vetor. Ou seja, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial. 
O Insertion Sort é um exemplo de algoritmo estável. É possível provar isso com a seguinte abstração: 


			|  0 |  1 |  2 |  3 |  4 | -> Ordem do vetor
			   /    /    /    /    / 
			| 10 | 20 | 25 | 30 | 20 | -> Quando vamos ordenar esse vetor usando o insertion sort, pegamos o último elemento, o 20 da posição 4, ele é comparado com o 30, na posição 3 e como é menor muda de posição;
  			| 10 | 20 | 25 | 20 | 30 | -> O mesmo elemento, o 20 agora está na posição 3 do vetor e como é menor que o 25 na posição 2, vai mudar de novo de posição agora com o 25;
			| 10 | 20 | 20 | 25 | 30 | -> Observe que o 20 agora está na posição correta, já havia um outro elemento 20 no vetor e eles não trocam de posição, respeitando a definição de algoritmo estável.

####  T2: Separa

A implementação da questão não dá certo para vetores com valores aleatórios, sendo assim, para resolver essa questão, implementei uma versão recursiva do separa, bem diferente da que foi apresentada.


```c
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
```
