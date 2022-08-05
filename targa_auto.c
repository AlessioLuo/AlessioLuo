/*Scrivere un programma per la gestione di un autosalone che memorizzi per ogni auto modello, targa, colore, prezzo. 
Definire le strutture dati necessarie a memorizzare una automobile e dichiarare una variabile per memorizzare al massimo 100 auto. 
Chiedere all'utente di inserire i dati di n auto (con n definito dall'utente e minore di 100).
Dopo l'inserimento permettere all'utente di cercare un'auto tramite la targa.
*/
#include <stdio.h>
#define MAX 100
#include <string.h>

typedef char stringa[30];


typedef struct
{
    stringa modello;
    char targa[8];
    stringa colore;
    float prezzo;
} automobile;


automobile leggiAuto();
void stampaAuto(automobile a);







int main()
{
    automobile collezioni[100];
    int dim,i;
    char targa[8];
    int trovata=0;
    
    printf("Quante automobili vuoi inserire?\n");
    scanf("%d",&dim);
    
    for(i=0;i<dim;i++)
    {
        printf("Inserire i dati del %d-esima automobile\n",i+1);
        collezioni[i]= leggiAuto();
        printf("%d automobile inserita:\n",i+1);
        stampaAuto(collezioni[i]);
    }
    
    printf("Inserisci la targa da cercare:\n");
    scanf("%s",targa);
    
    for(i=0;i<dim && trovata ==0;i++)
    {
        if(strcmp(collezioni[i].targa,targa)==0)
        {
            trovata = 1;
        }
    }
    
    if (trovata==1)
    {
        printf("L`auto cercata e`:\n");
        stampaAuto(collezioni[i-1]);
    }
    else
    {
        printf("\nNon ho trovato l`auto!");
    }
    
    

    return 0;
}



automobile leggiAuto()
{
    automobile au;
    
    printf("Modello:\n");
    scanf("%s",au.modello);
    printf("Targa:\n");
    scanf("%s",au.targa);
    printf("Colore:\n");
    scanf("%s",au.colore);
    printf("Prezzo:\n");
    scanf("%f%*c",&au.prezzo);
    return au;
}

void stampaAuto(automobile a)
{
    printf("Modello:%s\nTarga:%s\nColore:%s\nPrezzo:%.2f\n",a.modello,a.targa,a.colore,a.prezzo);
    
}
