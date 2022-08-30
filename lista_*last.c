/*Si definiscano le strutture dati e la funzione di inserimento per una lista in cui ogni elemento ha un puntatore verso l’elemento successivo 
ed uno verso l’ultimo elemento della lista. Implementare le principali funzioni di inserimento e rimozione per questo nuovo tipo di lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo
{
    int dato;
    struct nodo *next;
    struct nodo *last;
};

typedef struct nodo *lista;
lista inserisci_in_testa(lista l,int dato);
lista inserisci_in_coda(lista l,int dato);
lista rimuovi_in_testa(lista l);
lista rimuovi_in_coda(lista l);
void stampa(lista l);
int lunghezza(lista l);
lista ricerca(lista l,int dato);

int main()
{
    lista l=NULL;
    int n;
    srand(time(NULL));

    printf("Inserire lunghezza lista: ");
    scanf("%d",&n);

  for (int i = 0; i<n/2; i++)
  {
    l = inserisci_in_coda(l,rand()%10);
    stampa(l);
  }

  for (int i = 0; i<n/2; i++)
  {
    l = inserisci_in_testa(l,rand()%10);
    stampa(l);
  }

  printf("l{%d}: ", lunghezza(l));
  stampa(l);

  printf("Rimuovi un elemento in coda\n");
  l = rimuovi_in_coda(l);
  stampa(l);
 
  printf("Rimuovi un elemento in testa\n");
  l = rimuovi_in_testa(l);
  stampa(l);

  printf("l{%d}: ", lunghezza(l));
  stampa(l);

  for (int i=0; i<3; i++)
  {
    int el = rand()%10;
    lista e = ricerca(l,el);
    if (e!=NULL)
      printf("%d trovato\n", el);
    else
      printf("%d non trovato\n", el);

    printf("l{%d}: ", lunghezza(l));
    stampa(l);
  }
  return 0;
}
    



lista inserisci_in_testa(lista l,int dato)
{
    struct nodo *elem;//sono dei puntatori che puntano a dei struct nodo
    
    elem = malloc(sizeof(struct nodo));
    elem->dato = dato;
    elem->next = l;
    if(l!=NULL) //se non e` vuota 
    {
        elem->last = l->last; //allora l`ultimo elemento e` quello che punta anche l->last
    }
    else //se lista vuota allora elem di per se e` l`ultimo elemento della lista 
    {
        elem->last = elem;
    }
    l = elem;
    
    return l; //ritorno la lista (cioe` l`indirizzo del primo nodo)
}


lista inserisci_in_coda(lista l,int dato)
{
    if(l==NULL)
    {
        l = inserisci_in_testa(l,dato);
    }
    else
    {
        lista elem = malloc(sizeof(struct nodo)); //creo un elemento
        elem->dato = dato; 
        elem->next = NULL; //dico che non punta a niente dopo di lui quindi sono alla fine della lista 
        elem->last = elem; //lui stesso e` l`ultimo elemento della lista
        lista cur = l; // puntatore cur che serve a scorrere nella lista
        while(cur->next!=NULL) //finche` non siamo arrivati alla fine della lista
        {
           cur->last = elem; //punta all`ultimo elemento della lista che e` elem
           cur = cur->next;  //scorre
        }
        cur->next = elem; //alla fine cur deve fermarsi al penultimo posto e puntare prossimo e anche ultimo che e` elem
        cur->last = elem;
    }
    
    return l; //ritorno la lista
    
}

lista rimuovi_in_testa(lista l)
{
    if(l!=NULL) //perche` se la lista e` vuota non devo rimuovere niente
    {
    lista temp = l;
    l = temp->next;
    free(temp);
    }
    return l;
}

lista rimuovi_in_coda(lista l)
{
    if(l == NULL || l->next == NULL) //con 0 o 1 elemento in lista,rimuovere in cosa e` uguale a rimuovere in testa 
    {
        l = rimuovi_in_testa(l);
    }
    else
    {
        struct nodo *cur = l;
        while(cur->next != cur->last)
        {
            cur = cur->next;
        }
        
        struct nodo *new_last = cur;
        
        cur->next = rimuovi_in_testa(cur->next);  //fin qui ho gia` rimosso l`ultimo elemento dalla lista
        
        //faccio puntare cur all`inizio della lista e inizio a scorrere
        cur = l;
        //ora devo aggiornare i puntatori-last di tutti i nodi che devono puntare tutti a new_last
        while(cur!=NULL)
        {
            cur->last = new_last;
            cur = cur->next;
        }
    
    }
    
    return l;
    
}

void stampa(lista l)
{
    while(l!=NULL)
    {
        printf("%d [last:%d] ",l->dato,l->last->dato);
        l = l->next;
    }
    printf("\n");
}

int lunghezza(lista l)
{
    if(l==NULL)
    {
        return 0;
    }
    else
    {
        return 1 + lunghezza(l->next);
    }
}

lista ricerca(lista l,int dato)
{
    if(l==NULL)
    {
        return NULL;
    }
    if(l->dato == dato)
    {
        return l;
    }
    else
    {
        return ricerca(l->next,dato);
    }
}
