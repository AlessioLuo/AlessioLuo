/*Esercizio 2
estendere esercizio precedente ad un numero arbitrario di rettangoli (massimo 100) inseriti dall’utente.*/




#include <stdio.h>
#include <math.h>
#define MAX 100 

//punto del rettangolo
typedef struct
{
    float x;
    float y;
}punto;

//punti NO e SE che definiscono un rettangolo

typedef struct
{
    punto no;
    punto se;

}rettangolo;

//dichiarazione formale delle funzioni che usero`

int degenere(rettangolo r);
punto leggiPunto();
rettangolo leggiRettangolo();
rettangolo inviluppo(rettangolo r1,rettangolo r2);
void stampaRettangolo(rettangolo r);
rettangolo intersezione(rettangolo rett1,rettangolo rett2);
int intersezione_nulla(rettangolo ret1,rettangolo ret2);

int main()
{
    rettangolo sequenza[MAX];//un array di 100 rettangoli
    rettangolo invi,inter;
    int dim,i;
    
    printf("Quanti rettangoli vuoi inserire?(Massimo 100):\n");
    scanf("%d",&dim);
    printf("\n");
    
    for(i=0;i<dim;i++)
    {
        printf("Inserisci il %d-esimo rettangolo:\n",i+1);
        sequenza[i] = leggiRettangolo();
        stampaRettangolo(sequenza[i]);
    }//finito il ciclo avro` inserito nell`array tot numero di rettangoli con i relativi dati
    
    invi = sequenza[0];
    for(i=1;i<dim;i++) // poiche il rettangolo i+1 sara` vuoto se saremo alla fine della sequenza
    {
        
        invi = inviluppo(sequenza[i],sequenza[i+1]);
        
    }
    printf("Il triangolo inviluppo:\n");
    stampaRettangolo(invi);
    
    inter = sequenza[0];
    for(i=1;i<dim;i++) // poiche il rettangolo i+1 sara` vuoto se saremo alla fine della sequenza
    {
        inter = intersezione(sequenza[i],sequenza[i+1]);
        if(degenere(inter))
        {
            break;
        }
    }
    
    if(degenere(inter))
    {
    printf("L`intersezione dei rettangoli e` nulla!\n");
    }
    else 
    {
    stampaRettangolo(inter);
    }
    return 0;
}

//funzione che stampa a video un rettangolo,quindi non restituisce niente
void stampaRettangolo(rettangolo r) 
{
	printf("Rettangolo:\n");
	printf(" NO: [ %2.2f, %2.2f ]\n", r.no.x, r.no.y);
	printf(" SE: [ %2.2f, %2.2f ]\n", r.se.x, r.se.y);
}






int degenere(rettangolo r)
{
    return r.no.x >= r.se.x || r.no.y <= r.se.y;
}



//una funzione che non legge niente in input ma chiede solo da tastiera di inserire il punto 
punto leggiPunto()
{
    punto p;
    printf("Inserisci la coordinata x:");
    scanf("%f",&p.x);
    printf("Inserisci la coordinata y:");
    scanf("%f",&p.y);
    return p;
}

//una funzione che chiede da tastiera l`inserimento di un rettangolo

rettangolo leggiRettangolo()
{
    rettangolo r;
    do
    {
    printf("Vertice NORD-OVEST:\n");
    r.no = leggiPunto();
    printf("Vertice SUD-EST:\n");
    r.se = leggiPunto();
    }while(degenere(r)==1);
    
    return r;
}

/*il rettangolo di inviluppo e` il rettangolo minimo che riesce a comprendere entrambi i rettangoli, quindi basta prendere il punto NO piu` NORD-OVERST dei due e 
il punto SE piu` SUD-EST dei due*/
rettangolo inviluppo(rettangolo r1,rettangolo r2)
{
    rettangolo invi;
    
    invi.no.x = fmin(r1.no.x,r2.no.x);
    invi.no.y = fmax(r1.no.y,r2.no.y);
    invi.se.x = fmax(r1.se.x,r2.se.x);
    invi.se.y = fmin(r1.se.x,r2.se.y);
    
    return invi;
}

rettangolo intersezione(rettangolo rett1,rettangolo rett2)
{
    rettangolo inter;
    inter.no.x = fmax(rett1.no.x,rett2.no.x);
    inter.no.y = fmin(rett1.no.y,rett2.no.y);
    inter.se.x = fmin(rett1.se.x,rett2.se.x);
    inter.se.y = fmax(rett1.se.y,rett2.se.y);

    return inter;    
}


int intersezione_nulla(rettangolo ret1,rettangolo ret2)
{
    rettangolo nullo;
    
    return (degenere(intersezione(ret1,ret2)));
}
