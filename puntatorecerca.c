/*
Scrivere una funzione che ricevuto in ingresso un array a di interi, ed un valore c da cercare,
ritorna un puntatore alla prima posizione dell’array contenente il valore c, oppure NULL se il valore non è presente.
Si scriva poi un semplice programma per testare la funzione.
*/
#include <stdio.h>
#define MAX 100

int *cerca(int a[],int c,int dim);

int main()
{
    int a[]={0,1,2,3,4,5,6,7,8,9};
    int *pos1,*pos2;
    int c1 = 8, c2 = 12;
    
    pos1 = cerca(a,c1,10);
    pos2 = cerca(a,c2,10);
    
    if(pos1==NULL)
    {
        printf("%d non trovato \n",c1);
    }
    else
    {
        printf("Il numero %d e` stato trovato in posizione %ld \n",c1,pos1-a);
    }
    
    if(pos2==NULL)
    {
        printf("%d non trovato \n",c2);
    }
    else
    {
        printf("Il numero %d e` stato trovato in posizione %ld \n",c2,pos2-a);
    }
    
    
    
    
    return 0;
}

int *cerca(int a[],int c,int dim)
{
    int i;
    for(i=0;i<dim;i++)
    {
    if(a[i]==c)
    {
        return a+i;
    }
    }
    return NULL;
}
