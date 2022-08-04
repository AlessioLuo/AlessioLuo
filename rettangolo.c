/*Un rettangolo coi lati paralleli agli assi sia invece definito da una coppia di punti: 
il suo vertice in alto a sinistra (NO, «NordOvest») e il suo vertice in basso a destra (SE, «SudEst»).

> Esercizio 1b:
Si scriva poi un programma che, dati due rettangoli con i lati paralleli agli assi: 
1.Verifichi che i due rettangoli dati siano “corretti” (ovvero che il vertice di NO sia effettivamente a nord-ovest rispetto al vertice di SE).
2.Calcoli il loro rettangolo di inviluppo (definito successivamente).
3.Calcoli, se esiste, il rettangolo di intersezione, oppure segnali che i rettangoli sono interamente non sovrapposti (cioè del tutto disgiunti).
*/
#include <stdio.h>
#include <math.h>


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


//Verifica che il rettangolo sia ben formato cioe` i punti no e se sono davvero rispettivamente in alto a sinistra e in basso a sinistra
int degenere(rettangolo r);
punto leggiPunto();
rettangolo leggiRettangolo();
rettangolo inviluppo(rettangolo r1,rettangolo r2);
void stampaRettangolo(rettangolo r);
rettangolo intersezione(rettangolo rett1,rettangolo rett2);
int intersezione_nulla(rettangolo ret1,rettangolo ret2);

int main()
{
   rettangolo re1,re2;
   rettangolo inv,inte;
   
   printf("Inserire il primo rettangolo:\n");
   re1 = leggiRettangolo();
   printf("Il primo rettangolo inserito e`:\n");
   stampaRettangolo(re1);

   printf("Inserire il secondo rettangolo:\n");
   re2 = leggiRettangolo();
   printf("Il secondo rettangolo inserito e`:\n");
   stampaRettangolo(re2);
   
   inv = inviluppo(re1,re2);
   printf("Il rettangolo di inviluppo e`:\n");
   stampaRettangolo(inv);
   
   inte = intersezione(re1,re2);
   printf("Il rettangolo d`intersezione e`:\n");
   stampaRettangolo(inte);
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
