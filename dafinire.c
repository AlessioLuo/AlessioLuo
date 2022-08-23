/*Data la seguente struttura dati:
typedef struct
{
    char titolo[101];
    char autore[101];
    int anno;
} libro;
typedef struct {
    libro libri[100];
    int n_libri;
} libreria;
Si implementino delle funzioni di lettura e scrittura, che consentano di 
(i) leggere e scrivere una sequenza di libri da un file e memorizzarli in una variabile libreria e 
(ii) a partire da una variabile libreria, salvi i libri in essa contenuta (separatamente) su file. 
Si implementi una coppia di funzioni di lettura/scrittura che “lavorino” in modalità binaria 
ed una coppia di funzioni che “lavorino” in modalità testuale (per queste ultime due, scegliere il formato dell’output testuale desiderato).
*/


//1. devo preparare un file in cui ho salvato una sequenza di libri
//2. letto i libri li salvo in una variabile libreria
//3. da questa libreria estraggo i libri seperatamente su file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char titolo[101];
    char autore[101];
    int anno;
} libro;

typedef struct {
    libro libri[100];
    int n_libri;
} libreria;

libreria leggi_testuale(FILE *f1);
libreria leggi_binario(FILE *f1);
void scrivi_testuale(FILE *f1,libreria lib);
void scrivi_binario(FILE *f1,libreria lib);
void stampa_libreria(libreria lib);


/* prendo una libreria da un file testuale e la butto in un file binario,viceversa prendo una libreria da un file binario e la butto in un file testuale*/
int main()
{
    libreria lib,lib2;
    FILE *fin,*fout;
    printf("sizeof(libro) = %lu\n",sizeof(libro));

    fin = fopen("libri.txt","r"); //apro in lettura testuale un file

      lib = leggi_testuale(fin);  //leggo la libreria presente nel file e la salvo nella libreria lib
      stampa_libreria(lib);    //stampa la libreria lib
      fclose (fin);

    fout = fopen("libri.dat","wb"); //apro in scrittua binaria un file

      scrivi_binario(fout, lib); //scrivo nel file la libreria lib
      fclose(fout);
   
    fin = fopen("libri.dat","rb");  //apro in lettura binaria un file 
   
      lib2 = leggi_binario(fin);  //leggo la libreria presente nel file e la salvo nella libreria lib2
      stampa_libreria(lib2);   //stampo la libreria lib2
      fclose(fin);
   
    fout = fopen("libri2.txt","w");  //apro in scrittura testuale un file 
    
      scrivi_testuale(fout, lib2);  //scrivo nel file la libreria lib2 
      fclose(fout);
    

    return 0;
}

libreria leggi_testuale(FILE *f1)  //leggo da file e lo salvo in una libreria
{
    libreria lib;
    lib.n_libri = 0; //all`inizio ho 0 libri
    
    while( !feof(f1) && !ferror(f1) )  //finche` nel file ci sono ancora testi 
    {
        libro l;
        int n;   //i dati compilati
        n = fscanf(f1,"%[^\n]%*c",l.titolo);  //fscanf restituisce il numero di elementi letti correttamente, se legge un titolo restituisce 1
        n = n + fscanf(f1,"%[^\n]%*c",l.autore);
        n = n + fscanf(f1,"%d",&l.anno);
        if(n == 3)  //i dati di un libro sono 3, se compilo un dato n++,quindi quando ho compilato correttamente 3 dati ho un libro e lo salvo in libreria
        {
            lib.libri[lib.n_libri] = l; //salvo il libro nella posizione 0 della libreria
            lib.n_libri++; // aumento numero dei libri che posso anche utilizzare come posizione
        }
    }

    return lib;
}


libreria leggi_binario(FILE *f1) //leggo da file e lo salvo in una libreria
{
  libreria lib;
  lib.n_libri = 0;
  while( !feof(f1) && !ferror(f1) )
  {
    libro l;
    if (fread(&l,sizeof(libro),1,f1)==1)   // fread restituisce il numero degli elementi effettivamente letti,quindi quando legge un libro lo salva in libreria
    {
      lib.libri[lib.n_libri] = l;
      lib.n_libri++;
    }
  }
  return lib;
}

void scrivi_testuale(FILE *f1,libreria lib)  //data una libreria la scrivo nel file indicato
{
    int i;
    for(i=0;i<lib.n_libri;i++)
    {
        fprintf(f1,"%s\n",lib.libri[i].titolo);
        fprintf(f1,"%s\n",lib.libri[i].autore);
        fprintf(f1,"%d\n",lib.libri[i].anno);
    }
   
}


void scrivi_binario(FILE *f1,libreria lib)
{
    libro l;
    fwrite(lib.libri,sizeof(libro),lib.n_libri,f1);
}

void stampa_libreria(libreria lib)
{
    int i;
    
    for(i=0;i<lib.n_libri;i++)
    {
        libro l = lib.libri[i];
        printf("%s\n %s\n %d\n",l.titolo,l.autore,l.anno);
    }
}

