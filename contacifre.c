/*Scrivere una funzione cifre che riceve un intero positivo n e conta il numero di cifre di n.
Suggerimento:
Caso base: se n < 10  allora cifre(n) = 1
Passo ricorsivo: se n>=10 allora cifre(n) =  1 + cifre(n/10)
*/
#include <stdio.h>

int cifre(int n);

int main()
{
    int n;
    int dim;

    printf("Inserisci un numero intero positivo:\n");
    scanf("%d",&n);
    
    dim = cifre(n);
    printf("%d e` composto da %d cifre\n",n,dim);
    
    return 0;
}

int cifre(int n)
{
    if(n<10)
    {
        return 1;
    }
    else
    {
        return 1+cifre(n/10);
    }
}
