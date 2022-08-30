/*Una lista circolare è una lista dinamica in cui l’ultimo elemento, invece che indicare un valore NULL come successivo, punta di nuovo al primo elemento. Il puntatore di inizio lista punta ad un elemento arbitrario. 
		
Il singolo elemento della lista è descritto dalla dichiarazione di tipo che segue. Si supponga inoltre che ciascun elemento della lista sia unico, cioè non esistono nella lista due elementi con lo stesso valore per il campo data.
					
struct circular
{ 
int data;
struct circular* next;					
} ;

typedef struct circular circularlist;
typedef circularList *lista;
					
Si implementi una funzione inserisci in linguaggio C che, data una lista circolare in input e un intero, aggiunga tale intero in una qualunque posizione della lista, controllando nel contempo che tale intero non sia già presente. In questo caso, la lista rimane inalterata. 
Si implementi una funzione stampa in linguaggio C che, data una lista circolare in input, ne stampa a video il contenuto.

*/
#include <stdio.h>
#include <stdlib.h>

struct circular
{ 
    int dato;
    struct circular *next;					
};

typedef struct circular circularlist;

typedef circularlist *lista;

lista inserisci(lista l,int dato);
void stampa(lista l);


int main()
{
    lista l = NULL;
	l = inserisci (l,1);
	stampa(l);
	l = inserisci (l,2);
	stampa(l);
	l = inserisci (l,3);
	stampa(l);
	l = inserisci (l,1);
	stampa(l);
	l = inserisci (l,4);
	stampa(l);
	l = inserisci (l,2);
	stampa(l);
	l = inserisci (l,5);
	stampa(l);
}


lista inserisci(lista l,int dato)
{
    lista elem,pre,cur; //sono puntatori che puntano a una struct circularList
    int trovato = 0;
    
    if(l == NULL) //se la lista e` vuota inserisco direttamente l`elemento in lista
    {
        elem = malloc(sizeof(struct circular));
        elem->dato = dato;
        elem->next = elem; //poiche` e` il primo e anche ultimo elemento in lista, punta a se stesso
        l = elem;
    }
    else
    {
        cur = l;
        
        do
        {
            if(cur->dato == dato) //se trovo un valore uguale nella lista, non alloco spazio ad elem
            {
                trovato = 1;
            }
            pre = cur;
            cur = cur->next;
            
        }while(trovato == 0 && cur!=l );
        
        if(trovato == 0)
        {
            elem = malloc(sizeof(struct circular));
            elem->dato = dato;
            elem->next = l;
            pre->next = elem;
            l = elem;
        }
    }
    return l;
}


void stampa(lista l)
{
	lista cur; 
	printf("Lista:");
	if (l == NULL)
	{
		printf(" vuota\n");
	}
	else
	{
		cur = l;
		do
		{
			printf(" %d", cur->dato);
			cur = cur->next;
 
		} while (cur!=l);
		printf("\n");
	}
}
