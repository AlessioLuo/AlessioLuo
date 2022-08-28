/*Implementare una funzione che consenta di inserire interi in ordine crescente all’interno di una linked list.*/

#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *next;
};

typedef struct nodo *lista;
lista inserisci_testa(lista l,int dato);
lista inserisci_in_ordine(lista l,int dato);
void stampa_lista(lista l);

int main()
{
    int a[5] = {1,6,3,100,5};
    int i;
    lista myl = NULL;
    
    for(i=0;i<5;i++)
    {
        myl = inserisci_in_ordine(myl,a[i]);
    }
    stampa_lista(myl);
    
    
    return 0;
}


lista inserisci_testa(lista l,int dato)
{
  struct nodo *temp = malloc(sizeof(struct nodo)); //creiamo un puntatore dove successivamente salveremo il nuovo nodo
  temp->dato = dato; //diamo a dato il valore voluto
  temp->next = l; //passiamo al puntatore next l`indirizzo del primo elemento cosi saremo in testa alla lista
  
  return temp;
  
}

lista inserisci_in_ordine(lista l,int dato)
{
    struct nodo *cur,*prec;
    cur = l;
    prec = NULL;
    while(cur != NULL && cur->dato < dato) //scorro il cur finche` non finisce la lista (allora cur ha il dato maggiore) e finche` il dato in cur e` minore di un dato
    {
        prec = cur;
        cur = cur->next;
    }//il while stoppa quando siamo alla fine della lista oppure quando troviamo un dato maggiore di cur->dato 
    
    if(prec==NULL) //se siamo all`inizio della lista o la lista e` vuota
    {
       return inserisci_testa(l,dato); //allora basta inserire il nodo in testa alla lista
    }
    else //quando ho un nodo precedente e un nodo subito dopo
    {
        prec->next = inserisci_testa(cur,dato);  //aggancio temp dopo prec e prima di cur
        return l; //ritorno la lista (cioe` la testa)
    }
    
}


void stampa_lista(lista l) 
{
    if(l==NULL)
    {
        printf("FINE");
    }
    else
    {
        printf("%d->",l->dato);
        stampa_lista(l->next); //funzione ricorsiva che stampa gli elementi della lista uno dopo l`altro
    }
}
