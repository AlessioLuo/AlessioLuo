/*Definire un tipo di dato in grado di rappresentare le coordinate di un punto nel piano cartesiano ed un tipo di dato adatto
a rappresentare una spezzata formata da (al massimo) 50 punti nel piano cartesiano. 
Scrivere quindi un programma che acquisisca da tastiera la sequenza di punti che formano una spezzata (chiedendo all'utente anche quanti punti vuole inserire).
Infine, calcolare la lunghezza della spezzata e stampare il risultato a video.*/


#include <stdio.h>
#include <math.h>
#define MAX 50


typedef struct
{
    float x;
    float y;
}punto;

punto leggiPunto();
float distanza(punto a,punto b);

int main()
{
    punto spezzata[MAX];
    int dim;
    int i;
    float dist=0;
    printf("Quanti punti vuoi?\n");
    scanf("%d",&dim);
    
    for(i=0;i<dim;i++)
    {
        spezzata[i] = leggiPunto();

    }

    for(i=0;i<dim ;i++)
    {
        dist = dist + distanza(spezzata[i],spezzata[i+1]);
    }
    dist = dist - distanza(spezzata[dim-1],spezzata[dim]);
    
    printf("La lunghezza della spezzata e`: %f",dist);
    
    //fin  qui ho completato la spezzata con quanti e quali punti voglio
    
    //calcolo la distanza da un punto all`altro
    
  
    
    
    return 0;
}


punto leggiPunto()
{
    punto p;
    printf("Inserisci coordinata x:\n");
    scanf("%f",&p.x);
    printf("Inserisci coordinata y:\n");
    scanf("%f",&p.y);
    
    return p;
}


float distanza(punto a,punto b)
{
    float d;
    
    d = sqrtf((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    
    return d;
}
