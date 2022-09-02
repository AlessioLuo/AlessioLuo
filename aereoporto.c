/*Costruire una struttura dati chiamato rotta con dentro codice di partenza e codice di destinazione dell`aereoporto (3 caratteri) e la distanza in miglia 
chiedi di inserire da tastiera la partenza e restituirera` la destinazione con distanza minore, se no stampa non trovato*/

#include <stdio.h>
#include <string.h>


#define N 100

typedef struct
{
    char codPart[4];
    char codDest[4];
    int  distanza;

}rotta;

int main()
{
    rotta array[N];
    char partenza[4];
    int i,imin;
    
    for(i=0;i<N;i++)
    {
        
        scanf("%s%*c",array[i].codPart);
        scanf("%s%*c",array[i].codDest);
        scanf("%d%*c",&array[i].distanza);
    }
    
    printf("Inserisci codPart voluto:\n");
    scanf("%s",partenza);
    
    imin = -1;
    for(i=0;i<N;i++)
    {
       if(strcmp(array[i].codPart,partenza)==0 && (imin == -1 || array[i].distanza < array[imin].distanza))
       {
           imin = i;
       }
       if(imin == -1)
       {
           printf("Aereoporto di partenza non trovato\n");
       }
       else
       {
           printf("Aereoporto piu` vicino: %s \n",array[imin].codDestdest)
       }
       
       return 0;
       
       
    }
    
