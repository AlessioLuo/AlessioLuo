/*Sia dato il seguente tipo di dato per la rappresentazione di una lista per la gestione dei caratteri. 

typedef struct _elem 
{ 
char car; 
struct _elem * next; 
} car_t; 

typedef car_t *lista;

Il tipo di dato lista deve essere gestito in modo che gli elementi in essa contenuti siano sempre ordinati (seguendo l’ordine alfabetico) pur consentendo più ripetizioni dello stesso carattere.
Inoltre, deve essere possibile caricare/salvare il contenuto di una lista da/su file, usando il seguente formato:
per ogni carattere presente nella lista si dovrà riportare su file tale carattere seguito (senza spazi) dal numero di volte in cui questo compare nella lista.  
Si tenga presente che, essendo la lista ordinata, i caratteri uguali occupano sempre posizioni adiacenti. 

Implementare due funzioni carica e salva che permettono di caricare e salvare una lista da file (specificandone il nome). 
Si scelga opportunamente il tipo dei parametri in ingresso e di quello di ritorno delle funzioni.

Esempio 
La lista, a → a → a → c → e → e → e → e → e → r → r, se salvata su file produrrà un file contenente a3c1e5r2 (e viceversa, caricando una lista da quel file si otterà la lista rappresentata).
*/
#include <stdio.h>
#include <stdlib.h>


struct _elem 
{ 
    char car; 
    struct _elem *next; 
}; 

typedef struct _elem cat_t;
typedef cat_t *lista;

void inserisci(char c,lista *l);
void carica(char filename[],lista *l);
void salva(char filename[],lista l);

int main()
{
    
    lista list = NULL;
    
    
    carica("lista_input.txt",&list);
    inserisci('g',&list);
    salva("lista_output.txt",list);

    return 0;
}


void inserisci(char c,lista *l) //inserisci in lista c
{
    lista pre,cur,p;
    
    cur = *l;    //cur parte dalla testa della lista
    pre = NULL;
    
    while(cur != NULL && c > cur->car)  //faccio scorrere cur finche` non incontra un carattere maggiore 
    {
        pre = cur;
        cur=cur->next;
    }
    
    p = malloc(sizeof(cat_t));  //cur->car e` maggiore di c quindi allochiamo una memoria p con il carattere da inserire in lista, e lo inseriamo in lista prima di cur
    p->car = c;
    p->next = cur;
    
    if(pre!=NULL) //se non siamo all`inizio della lista allora aggiorniamo il next del nodo precedente
    {
        pre->next = p;
    }
    else //se p e` il primo elemento della lista allora il puntatore testa puntera` a p
    {
        *l = p;
    }
}


void carica(char filename[],lista *l) //file --->lista , dato il nome del file possiamo caricare la lista dal file
{
    FILE *f;
    char c;
    int n,i;
    
    f = fopen(filename,"r");
    if(f!=NULL) //se f == NULL vuol dire che l`apertura del file e` fallita
    {
        while(fscanf(f,"%c%d",&c,&n)==2) //fscanf restituisce il numero di caratteri letti,finche` abbiamo coppie
        {
            for(i=0;i<n;i++)
            {
                inserisci(c,l);
            }
        }
    }
    fclose(f);
}


void salva(char filename[],lista l)
{
    char c;
    FILE *f;
    int n;
    lista cur;
    
    
    
    
    f = fopen(filename,"w");
    if(f!=NULL)
    {
            cur = l;
            while(cur!=NULL)
            {
                if(cur==l)  //se siamo all`inizio della lista
                {
                    c = cur->car; //salviamo il primo elemento in c
                    n=1;
                }
                else if(c!=cur->car) // se il carattere cambia
                {
                    fprintf(f,"%c%d",c,n); //stampo il carattere e il numero di volte in file
                    c = cur->car; //aggiorno il carattere in quello nuovo
                    n = 1; //n ritorna a 1
                }
                else //se il carattere letto non cambia
                {
                    n++;
                }
            
            
            cur = cur->next;
            }
            if(l!=NULL) //risolvo l`ultimo carattere che dopo di esso non avra` mai un cambio di carattere
            {
                fprintf(f,"%c%d",c,n);
            }
            fclose(f);
    }
   
}
