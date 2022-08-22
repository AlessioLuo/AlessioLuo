/*Scrivere una funzione: void fun(FILE *f1, FILE *f2), che riceve due puntatori a FILE (aperti in lettura/scrittura) di tipo binario; 
f1 contiene una sequenza di interi e la funzione deve scrivere in f2 (che è vuoto) i numeri pari della sequenza contenuta in f1 in ordine inverso.
*/
#include <stdio.h>
void fun(FILE *f1, FILE *f2);


int main()
{
    FILE *input,*output;
    int numeri[10] = {1,2,3,4,5,6,7,8,9,10};
    int numeri_pari[10];
    int i,n;
    input = fopen("input.dat","wb");
    fwrite(numeri,sizeof(int),10,input);
    fclose(input);  //ho scritto numeri[10] nel file input
    
    input = fopen("input.dat","rb");
    output = fopen("output.dat","wb");
    fun(input,output);
    fclose(input);
    fclose(output);
    
    output = fopen("output.dat","rb");
    n = fread(numeri_pari,sizeof(int),10,output); //in numeri_pari salvo cio` che ho letto da "output", n e` il numero di valori letti
    for(i=0;i<n;i++)
    {
        printf("%d ",numeri_pari[i]);
    }
    printf("\n");
    fclose(output);



    return 0;
}

void fun(FILE *f1, FILE *f2)
{
    int r,num_letto;
    /* INDICATORE FILE:
    inizio <----(un int alla volta)------ fine */
    r = fseek(f1,-sizeof(int),SEEK_END); //fseek restituisce 0 se lo spostamento dell`indicatore avviene con successo,in questo caso parte dalla fine del file e torna indietro di un int alla volta verso l`inizio del file
    while(r == 0 ) //finche l`indicatore riesce a spostarsi indietro di un int (finche` ci sono caratteri)
    {
      if(fread(&num_letto,sizeof(int),1,f1)!=0 && num_letto%2==0)/*fread restituisce il numero di caratteri letti,quindi se impongo che fread sia !=0 vuol dire finche` legge un valore e tale valore sia pari lo scrivo in f2*/
      {
          fwrite(&num_letto,sizeof(int),1,f2); //tutti i valori che son pari in f1 vengono scritti in f2; in ordine inverso perche` leggiamo f1 dalla fine all`inizio
      }
      r = fseek(f1, -2*sizeof(int), SEEK_CUR); //finito di scrivere un valore in f2, sposto l`indicatore indietro di 2 int, e ricomincia il ciclo
    }
    
    
    
}
