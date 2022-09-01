/*Data la seguente struttura dati,			
struct nodo{
int el;
struct nodo *next;
};			
typedef struct nodo *lista;
		
Implementare la funzione void shift(lista *l), che riceve in ingresso la testa di una lista l. La funzione deve modificare la lista l, 
spostando tutti i nodi in avanti di una posizione (il primo nodo diventa il secondo, il secondo diventa il terzo e così via),
mentre fa diventare l’ultimo nodo della lista il primo nodo. Nel caso la lista sia vuota o contenga un solo elemento, la funzione non farà niente.
Esempio: se la funzione riceve in ingresso la lista 3 -> 5 -> 8 -> 9 -> 12, modificherà la lista così: 12 -> 3 -> 5 -> 8 -> 
9 (cioè 12 diventa il nuovo primo nodo e 9 diventa l’ultimo nodo). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo
{
    int el;
    struct nodo *next;
};

typedef struct nodo *lista;

void shift(lista *l);
void stampa(lista l);
void inserisci(lista *l,int dato);

int main()
{
    lista l = NULL;
    int valore;
    int i;
    
    srand(time(NULL));
    
    for(i=0;i<5;i++)
    {
        valore = rand()%10;
        inserisci(&l,valore);
    }
    
    stampa(l);
    
    shift(&l);
    
    stampa(l);
    
    shift(&l);
    
    stampa(l);
    
    
    
    
    
    
    return 0;
}
void stampa(lista l)
{
    if(l == NULL)
    {
        printf(" END \n");
    }
    else
    {
      printf(" %d -> ",l->el);
      stampa(l->next);
    }
}

void inserisci(lista *l,int dato)
{
    lista temp;
    
        temp = malloc(sizeof(struct nodo));
        temp->el = dato;
        temp->next = *l;
        *l = temp;
}

void shift(lista *l)
{
    lista cur,prec,p;
    
    cur = *l;
    prec = NULL;
    if(l == NULL)
    {
        return;
    }
    else
    {
    while(cur->next != NULL) //scorro fino alla fine della lista
    {
        prec = cur;
        cur = cur->next;
    }
    prec->next = NULL;
    cur->next = *l;
    *l = cur;
    }
}
