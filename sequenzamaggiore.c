/*Scrivere un programma che legga da tastiera una sequenza di interi, lunga al più 100 e terminata da uno zero. 
Dopo, chieda all’utente di inserire un intero N, e stampi a video gli elementi della sequenza precedentemente inserita che sono maggiori di N.
Nota: Risolvere l’esercizio utilizzando le [] solo all’interno delle dichiarazioni.*/
#include <stdio.h>
#define MAX 100

void maggiore(int *p1,int *p2);

int main()
{
    int sequenza[MAX];
    int N;
    int i;
    int length;
    
    printf("Inserisci una sequenza di numero che termini con 0\n");
    
    scanf("%d",sequenza);
    for(i=1;i<MAX && sequenza[i-1] != 0;i++)
    {
        scanf("%d",(sequenza+i));
    }
    
    length = i-1;
    
    printf("Inserisci un numero N\n");
    scanf("%d",&N);
    printf("I numeri maggiori di %d sono:\n",N);
    for(i=0;i<length;i++)
    {
        
     maggiore(&N,(sequenza+i));
     
    }
    
    return 0;
}

void maggiore(int *p1,int *p2)
{
    if(*p2>*p1)
    {
        printf("%d\n",*p2);
    }
}
