/*Si implementi una funzione string2list che riceve in ingresso una stringa str e restituisce una lista così organizzata:
la lista dovrà contenere un elemento per ciascun carattere distinto presente in str;
inoltre, ogni elemento della lista dovrà contenere sia il carattere associato a tale elemento, che il numero di volte in cui tale carattere compare all’interno della stringa str.
Esempio
Ingresso: “esempio” Uscita:
e|2 -> s|1 -> m|1 -> p|1 -> i|1 -> o|1 -> NULL
*/
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    char c;
    int n;
    struct nodo *next;
};

typedef struct nodo *lista;

lista string2list(char *str);
void stampa(lista l);
lista inserisci(lista l,char c);

int main()
{
    lista myl = NULL;
   
    
    myl = string2list("esempio");
    
    stampa(myl);
    

    return 0;
}

lista string2list(char *str) //funzione che riceve in input una stringa e in output produce una lista che ha come dati una lettera e il numero di occorenze di tale
{
    lista l = NULL;
    
    for(int i=0;str[i] != '\0';i++)
    {
        l = inserisci(l,str[i]);
    }
  return l;
}


lista inserisci(lista l,char c)
{
    lista cur,p;
    
    cur = l;
    
    while(cur!=NULL && cur->c != c) //controllo se nella lista ci sia gia` il carattere
    {
       cur = cur->next;
    }
    
    if(cur!=NULL) //perche` se cur si ferma prima della fine della lista vuol dire che ho trovato una lettera uguale gia` esistente
    {
        cur->n = cur->n+1; //aggiorno il numero delle occorenze della lettera
    }
    else //se sono alla fine della lista allora vuol dire che non esiste una lettera uguale quindi inserisco un nuovo nodo
    {
        p = malloc(sizeof(struct nodo));
        p->c = c;
        p->n = 1;
        p->next = l;
        l = p;
    }
    
    //aggiorno la testa della lista
    
    
    return l;
}


void stampa(lista l)
{
    if(l == NULL)
    {
        printf(" End\n");
    }
    else
    {
        printf(" %c|%d ->",l->c,l->n);
        stampa(l->next);
    }

}
