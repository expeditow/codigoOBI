#include <stdio.h>
    int LOL = 0;
int casasDec(int x);
int* transfVetor(int x, int y);
void comparador(int* vetor1, int* vetor2, int tamanho);

int main()
{
    int entradaA, entradaB, casasA, casasB;
    scanf("%d", &entradaA);
    scanf("%d", &entradaB);

    casasA = casasDec(entradaA);
    casasB = casasDec(entradaB);

   if(casasA >= casasB)
    {
        int interm = casasA - casasB;
        casasB = casasB + interm;
    }
    else
    {
        int interm = casasA - casasB;
        casasB = casasB + interm;
    }

    int* vetorA = (int *)malloc(casasA * sizeof(int)) ;
    int* vetorB = (int *) malloc(casasB * sizeof(int)) ;
    vetorA = transfVetor(entradaA, casasA);
    vetorB = transfVetor(entradaB, casasB);

    comparador(vetorA, vetorB, casasA);


    free(vetorA);
    free(vetorB);
    return 0;
}

int casasDec(int x)
{
    int i = 0;
    while(x > 10)
    {
        x = x/10;
        i++;
    }
    return i+1;
}
int* transfVetor(int x, int y)
{
    int *vetorGenerio = (int *)malloc( y * sizeof(int)) ;

    for(int i = (y - 1); i >= 0; i--)
    {
        //printf("-%d \n", x%10);
        //printf("-%d \n", x/10);
        if(x < 1)
        {
        //printf("VETOR %d \n", x);
            vetorGenerio[i] = 0;
        }
        else
        {
        //printf("VETOR %d \n", x);
        vetorGenerio[i] = x%10;
        x = x/10;
        }
    }
    /*if(LOL == 0)
    {
        printf("Primeiro vetor:");
        for(int i = 0; i < y; i++)
        {
            printf("%d", *(vetorGenerio+i));
        }
        printf("\n");
    }
    else
    {
        printf("Segundo vetor:");
        for(int i = 0; i < y; i++)
        {
            printf("%d", *(vetorGenerio+i));
        }
    }
    printf("\n");
    LOL++;
    */
    return vetorGenerio;
    free(vetorGenerio);
}

void comparador(int* vetor1, int* vetor2, int tamanho)
{
    int *x = (int*)malloc(tamanho*sizeof(int));
    int *y = (int*)malloc(tamanho*sizeof(int));
    int contadorA = 0;
    int contadorB = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(*(vetor1+i) > *(vetor2+i))
        {
            x[i] = *(vetor1+i);
            
            contadorA++;
        }
        else if(*(vetor1+i) == *(vetor2+i))
        {
            x[i] = *(vetor1+i);
            y[i] = *(vetor2+i);
            contadorA++;
            contadorB++;
        }
        else
        {
            y[i] = *(vetor2+i);
            contadorB++;
        }
    }

    if(contadorA == 0)
    {
        printf("-1");
    }
    else
    {
        for(int i = 0; i < contadorA; i++)
        {
            printf("%d", *(x+i));
        }
    }
    printf(" ");
    if(contadorB == 0)
    {
        printf("-1");
    }
    else
    {
        for(int i = 0; i < contadorB; i++)
        {
            printf("%d", *(y+i));
        }
    }
    printf("\n");
    free(x);
    free(y);
}
