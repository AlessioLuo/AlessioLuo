Si implementi una funzione ricorsiva per risolvere la torre di hanoi che, invece di stampare a video le istruzioni testuali,
stampi su un file (aperto in modalità testuale e passato come argomento alla funzione) la sequenza di mosse e lo stato dei pioli dopo ogni mossa.
*/

#include <stdio.h>
void hanoi (FILE *out, int n, char from, char to,char temp, int pioli[][3], int dim);
void initia (int n, int pioli[][3]);
void move (char from, char to, int pioli[][3], int n);
void print (FILE *out, int pioli[][3], int n);

int main()
{
   int n;
   FILE *out;
  
   
   printf("Quanti dischi vuoi?\n");
   scanf("%d",&n);
   
   int pioli[n+1][3];  //creo i pioli con altezza n+1

    out = fopen("hanoi.txt","w");
    
    fprintf(out,"Stato iniziale\n");
    initia(n,pioli);
    print (out, pioli, n);
    
    fprintf(out,"\nEseguire le seguenti mosse:\n\n");
    hanoi(out,n,'A','C','B',pioli,n);
   
    
    
    
    return 0;
}

void hanoi(FILE *out, int n, char from, char to, char temp, int pioli[][3], int dim) //n = num di dischi,from = partenza,to = arrivo,temp = temporaneo,i pioli sono sempre 3 mentre l`altezza dipende dal numero dei dischi,
{
    if(n==1)
    {
        move(from,to,pioli,dim);
        print(out,pioli,dim);
        fprintf(out,"Muovo il disco %d da %c a %c\n\n\n", n, from, to);
    }
    else
    {
        hanoi(out,n - 1,from,temp,to,pioli,dim);  //da from a temp utilizzando to
        move(from,to,pioli,dim);
        print(out,pioli,dim);
        fprintf(out,"Muovo il disco %d da %c a %c\n\n\n", n, from, to);
        hanoi(out, n - 1, temp, to, from, pioli, dim); //da temp a to utilizzando from
    }
    
}


void initia(int n,int pioli[][3]) //inizializzo i pioli
{
    int i;
    for(i=0;i<n;i++)
    {
        pioli[i][0] = n-i;
        pioli[i][1] = 0;
        pioli[i][2] = 0;
    }
    
    pioli[n][0] = 0;
    pioli[n][1] = 0;
    pioli[n][2] = 0;
    
}

void move(char from,char to,int pioli[][3],int n)
{
    int from_index = n,to_index = n;
    
    //cerco l`indice del disco piu in alto nel piolo from
    while(pioli[from_index][from - 'A'] == 0 )
    {
        from_index--;
    }    
    
    //cerco l`indice della prima posizione vuota nel piolo to
    while(pioli[to_index][to - 'A'])
    {
        to_index--;
    }
    
    //scambio i due pioli, cioe` from->to   from->0
    pioli[to_index][to - 'A'] = pioli[from_index][from - 'A'];
    pioli[from_index][from - 'A'] = 0;
}


//stampa nel file i pioli
void print(FILE *out,int pioli[][3],int n)
{
    int i;
    //scendo a righe
    for(n=5;n>=0;n--)
    {
        for(i=0;i<3;i++)
        {
            if(pioli[n][i]==0)
                {
                    fprintf(out,"|\t");
                }
            else
                {
                    fprintf(out,"%d\t",pioli[n][i]);
                }
        }
        fprintf(out, "\n");
    }
    
}
