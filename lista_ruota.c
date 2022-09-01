/*Data la seguente struttura dati
struct nodo
{
    int el;
    struct nodo *next;
};

typedef struct nodo *lista;

Implementare la funzione void ruota(lista *l), che riceve in ingresso un puntatore alla testa di una lista l e la modifica nel modo seguente.
Il nodo che contiene l`elemento minore viene portato in testa alla lista, spostando in coda tutta la sottolista che lo precedeva.

Esempio: 8->9->6->3->7 diventa 3->7->8->9->6
*/

#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int el;
    struct nodo *next;
};

typedef struct nodo *lista;

void ruota(lista *l);






void ruota(lista *l)
{
    lista prec_min = NULL,last = *l,min = *l;
    lista cur = *l,prec = NULL;
    
    
    while(cur != NULL)  //finche` non arrivo alla fine della lista
    {
        if(cur->el < min->el) //se incontro un el minore aggiorno min, e aggiorno precmin al nodo precedente al corrente 
        {
            
            min = cur;
            prec_min = prec;
        }
        prec = cur;  //inizio a scorrere
        last = cur;  //aggiorno sempre last all`ultimo elemento passato
        cur = cur->next;
    }
    if(prec_min != NULL) //se il min non e` al primo posto
    {
        prec_min->next = NULL;
        last->next = *l;
        *l = min;
    }
 
}
