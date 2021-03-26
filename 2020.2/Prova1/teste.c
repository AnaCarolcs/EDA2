#include <stdlib.h>
#include <stdio.h>


int main( void )
{
    /* Vetor com elementos de valor duplicado */
    int vetor[] = { 1, 2, 3, 4, 4, 5, 5, 6, 7, 8, 9, 9, 10, 10 };

    int i, j, k;
    int tam = sizeof(vetor) / sizeof(int);

    /* Exibe Vetor Antes */
    printf("Antes: ");
    for( i = 0; i < tam; i++ )
        printf("%d ", vetor[i] );
    printf("\n");

    /* Remove elementos com valor duplicado */
    for( i = 0; i < tam; i++ )
    {
        for( j = i + 1; j < tam; )
        {
            if( vetor[j] == vetor[i] )
            {
                for( k = j; k < tam; k++ )
                    vetor[k] = vetor[k + 1];

                tam--;
            }
            else
            {
                j++;
            }
        }
    }

    /* Exibe Vetor Depois */
    printf("Depois: ");
    for( i = 0; i < tam; i++ )
        printf("%d ", vetor[i] );
    printf("\n");

    return 0;
}