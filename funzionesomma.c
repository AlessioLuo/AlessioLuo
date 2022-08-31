/*Scrivere in C una funzione valori che legge un array di interi (di dimensione variabile) e restituisce la somma dei valori più piccolo e più grande contenuti nell’array. 
Scrivere anche un programma principale d’esempio per l’invocazione della funzione.*/


#include <stdio.h>
int valori(int *a,int dim);

int main()
{
    int a[10];
    int i;
    int somma;
    for(i=0;i<10;i++)
    {
    printf("Inserisci un numero\n");
    scanf("%d",&a[i]);
    }
    
    somma = valori(a,10);
    printf("Somma del piu piccolo e piu grande: %d",somma);
    
    return 0;
}

int valori(int *a,int dim)
{
    int i;
    int min = a[0];
    int max = a[0];
    for(i=1;i<10;i++)
    {
        if(a[i]<min)
        {
            min = a[i];
        }
        
        if(a[i]>max)
        {
            max =a[i];
        }
    }
    
    return min+max;
}
