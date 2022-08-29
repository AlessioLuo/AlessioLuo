/*Considerare le seguenti strutture dati: 

struct nodo{
   int dato;
   struct nodo *pre;
   struct nodo *suc;
};

typedef struct nodo elem;
typedef elem *lista;

e scrivere una funzione C che inserisce un elemento (il cui contenuto è intero) 
in una lista rispettando l’ordine tra gli elementi (dal più piccolo al più grande). 
La lista non può contenere elementi duplicati e, quindi, se si tentasse 
di aggiungere un elemento già esistente, la funzione non dovrebbe fare nulla. 
Per indicare che la lista è vuota, il valore della sua testa sarà NULL.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{
   int dato;
   struct nodo *prec;
   struct nodo *suc;
};

typedef struct nodo elem;
typedef elem *lista;

lista inserisci_in_ordine(lista l,int dato);
void stampa(lista l);



int main(){
    
    lista l;
    int i;
    
    srand(time(NULL)); //inizializzazione della funzione rand,cioe` dargli un seme da dove partire
    
    for(i=0;i<5;i++)
    {
        int temp = rand()%100;  //poiche rand ci da` un numero compreso tra 0 e rand max, facciamo il resto di 100 cosi` in temp avremo un numero compreso tra 0 e 99
        printf("Inserisco %d\n",temp);
        l = inserisci_in_ordine(l,temp);
        
    }
    
    stampa(l);
    
    return 0;
}



lista inserisci_in_ordine(lista l,int dato)
{
    elem *ins,*cur,*pre;
    pre = NULL;
    cur = l;
    
    while(cur !=NULL && cur->dato < dato ) //scorrere la lista e fermarmi nel punto in cui sono compreso da un dato minore prima e un maggiore dopo
    {
        pre = cur;
        cur = cur->suc;
    }
    
    if(cur == NULL || dato!=cur->dato)  //nel caso in cui la lista non sia vuota o non abbia valori doppi
    {
        ins = malloc(sizeof(elem)); //creo uno spazio per il nodo ins,in ins inserisco il dato e metto a posto i puntatori prec e suc per posizionare ins nel posto corretto nella lista
        ins->dato = dato;
        ins->prec = pre;
        ins->suc = cur;
        
        if(cur != NULL)  //se siamo in mezzo
        {
            cur->prec = ins;
        }
        if(pre != NULL) //se siamo in mezzo
        {
            pre->suc = ins;
        }
        else  //se siamo all`inizio
        {
            l = ins;
        }
        
    }
    
    
    return l;
    
}

void stampa(lista l)
{
    if(l == NULL)
    {
        printf("La lista e` vuota\n");
    }
    else
    {
        while(l!=NULL)
        {
            printf("%d ",l->dato);
            if(l->prec==NULL)
            {
                printf("(prec = NULL, ");
            }
            else
            {
                printf("(prec = %d ",l->prec->dato);
            }
            if(l->suc == NULL)
            {
                printf("suc = NULL)\n");
            }
            else
            {
                printf("suc = %d)\n",l->suc->dato);
            }
            l=l->suc;
        }
    }
}
