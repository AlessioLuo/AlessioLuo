/*
Definire un tipo di dato che rappresenti un libro, in grado di contenere le seguenti informazioni:


Codice ISBN (sequenza di 13 cifre)
Autore
Titolo
Anno di pubblicazione
Codice scaffale (numero intero)
Prezzo

Si definisca poi un tipo di dato in grado di rappresentare una libreria che può contenere 100 libri e 
scrivere un programma che acquisisce i dati di N libri (con N letto da tastiera), 
 utilizzando la funzione descritta di seguito al punto A. Implementare anche le seguenti funzioni:

A.una funzione che consente di acquisire da tastiera i dati di un singolo libro OK
B.una funzione che stampi i dati di un libro OK
C.una funzione che stampi i prezzi dei libri che si trovano in un certo scaffale 
D.una funzione che stampi tutti gli autori (senza duplicati)
*/

#include <stdio.h>

typedef char stringa[100]; 

typedef struct
{
    char ISBN[14];
    stringa autore;
    stringa titolo;
    int anno;
    int codicescaffale;
    float prezzo;
    
}libro;

libro leggiLibro();
void stampaLibro(libro l1);


int main()
{
    libro libreria[100];
    int dim,i;
    int code;
    
    printf("Quanti libri vuoi inserire?\n");
    scanf("%d",&dim);
    
    for(i=0;i<dim;i++)
    {
        printf("Inserire %d^ libro\n",i+1);
        libreria[i] = leggiLibro();
        printf("Libro %d:\n",i+1);
        stampaLibro(libreria[i]);
    }
    
    printf("Inserisci un codice scaffale:\n");
    scanf("%d",&code);
    
    printf("I prezzi dei libri su questi scaffali sono:\n");
    for(i=0;i<dim;i++)
    {
        if(libreria[i].codicescaffale==code)
        {
            printf("%f\n",libreria[i].prezzo);
        }
    }
    
    printf("Tutti gli autori presenti sono:\n");
    for(i=0;i<dim;i++)
    {
        printf("%s\n",libreria[i].autore);
    }
    
    
    
    return 0;
}

libro leggiLibro()
{
    libro l;
    printf("Inserisci ISBN:\n");
    scanf("%s",l.ISBN);
    printf("Inserisci Autore:\n");
    scanf("%s",l.autore);
    printf("Inserisci Titolo:\n");
    scanf("%s",l.titolo);
    printf("Inserisci Anno di pubblicazione:\n");
    scanf("%d",&l.anno);
    printf("Inserisci Codice Scaffale:\n");
    scanf("%d",&l.codicescaffale);
    printf("Inserisci il prezzo:\n");
    scanf("%f",&l.prezzo);
    
    return l;
}

void stampaLibro(libro l1)
{
    printf("ISBN: %s \n",l1.ISBN);
    printf("AUTORE: %s \n",l1.autore);
    printf("TITOLO: %s \n",l1.titolo);
    printf("Anno di Pubblicazione: %d \n",l1.anno);
    printf("Codice Scaffale: %d \n",l1.codicescaffale);
    printf("Prezzo: %f \n",l1.prezzo);
    
    
}

