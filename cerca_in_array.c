/*
Scrivere una funzione che ricevuto in ingresso un array a di interi, ed un valore c da cercare, 
restituisce tutte le posizioni in cui il valore c è stato trovato all’interno di a.

Esempio: 
input [8,3,0,3,2,1,3,4] -> output: [1,3,6]*/

#include <stdio.h>

int cerca(int a[],int c,int dim,int pos[]);

int main()
{
   int a[8]={8,3,0,3,2,1,3,4};
   int pos[8];
   int c=3;
   int trovati;
   
   trovati =  cerca(a,c,8,pos);
   
   printf("Ho trovato %d alle posizioni:\n",c);
   for(int i=0;i<trovati;i++)
   {
     printf("%d\n",pos[i]);
   }
    return 0;
}

int cerca(int a[],int c,int dim,int pos[]) // dato un input, numero da cercare, mi restituisce quanti valori corrispondenti ho trovato
{
    int i;
    int trovati = 0;
    for(i=0;i<dim;i++)
    {
        if(a[i]==c)
        {
            pos[trovati] = i;  //la posizione in a del numero cercato lo salvo in p;
            trovati++;
        }
    }
    return trovati;
}

//Devo avere un array a[] in input, un array pos[] dove salvo le posizioni del valore cercato;la funzione mi restituisce quante volte compare il numero cercato
