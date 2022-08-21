/*Scrivere in C una funzione void fun(FILE *f1, FILE *f2) che prende come parametri due puntatori a file; 
f2 è un puntatore ad un file testuale (aperto in scrittura), 
f1 è un puntatore a un file binario (aperto in lettura) che contiene una sequenza di coppie di valori interi v1 e v2; 
v1 rappresenta la codifica ASCII del carattere da scrivere in f2 e v2 il numero di volte che l’operazione deve essere ripetuta,
ovvero quanti caratteri v1 devono essere scritti in f2. Le diverse sequenze di v2 caratteri v1 devono essere separate tra loro da uno spazio. */
#include <stdio.h>

void fun(FILE *f1,FILE *f2);

int main()
{
    FILE *input,*output;
    int coppie[6]={'c',10,'g',2,'a',1}; //creo le coppie v1 e v2;
    
    input = fopen("dati.dat","wb");
    fwrite(coppie,sizeof(int),6,input); //scrivo nel file "input"  l`array coppie[6]
    fclose(input); // fino qui ho finito di preparare il file input
    
    input = fopen("dati.dat","rb"),// file binario aperto in lettura che contiene una sequenza coppie
    output = fopen("risultati.txt","w"); //file testuale aperto in scrittura
    fun(input,output);
    fclose(input);
    fclose(output);
    
    return 0;
}

void fun(FILE *f1,FILE *f2)   //funzione che ricevuto due puntatori a FILE copia 'v1' in f2 'v2'-volte  (v1,v2 si trovano in f1)
{
    int v1,v2;
    int i;
    
    while(fread(&v1,sizeof(int),1,f1)!=0) //while termina quando non c`e` piu` niente da leggere (fread legge da f1 degli int 1-volta e lo salva in v1)
    {
        fread(&v2,sizeof(int),1,f1); //numero di volte da scrivere una lettera
        for(i=0;i<v2;i++) //scrive in f2 v1 v2-volte
        {
            fprintf(f2,"%c",v1);
        }
        fprintf(f2," ");
    }
    
}


/* FUNZIONE FUN:
legge 'c' e lo salva in v1, legge 10 e lo salva in v2, con il ciclo for stampa 10 volte 'c' in f2;
torna nella condizione del while -> legge 'g' e lo salva in v1, legge 2 e lo salva in v2, con il ciclo for stampa 2 volte 'g' in f2;
torna nella condizione del while -> legge 'a' e lo salva in v1, legge 1 e lo salva in v2, con il ciclo for stampa 1 volta 'a' in f2;
torna nella condizione del while -> non ha piu` niente da leggere quindi la fread restituisce 0 e quindi saltiamo fuori dalla condizione del while 
e termina la funzione fun;*/
