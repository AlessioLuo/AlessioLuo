/*La torre di Hanoi è un rompicapo in cui si hanno tre pioli (A,B,C) ed n dischi di dimensione crescente. 
All’inizio del gioco, tutti i dischi sono sul piolo A ordinati dal più grande (in basso) al più piccolo (in alto). 
Lo scopo del gioco è spostare tutti i dischi sul piolo C rispettando due regole:
non si può muovere più di un disco per volta;
non si può mai appoggiare un disco sopra un disco più piccolo.

Suggerimento: provare a pensare ad una soluzione ricorsiva, usando come dimensione del problema il numero di dischi da spostare.*/


#include <stdio.h>
void hanoi(int dischi,char from,char to,char temp);

int main()
{
    
    int dischi;
    
    printf("Quanti dischi vuoi?\n");
    scanf("%d",&dischi);
    
    hanoi(dischi,'A','C','B');
    
    
    return 0;
}

void hanoi(int dischi,char from,char to,char temp) //pos1=partenza,pos2=temporaneo,pos3=arrivo
{
    if(dischi == 1)
    {
        printf("%c -> %c\n",from,to);
    }
    else
    {
        hanoi(dischi-1,from,temp,to); // i n-1 dischi partono da a verso b,usando c come posto temporaneo   
        printf("%c -> %c\n",from,to); 
        hanoi(dischi-1,temp,to,from);  //i n-1 dischi partono da b verso c,usando a come posto temporaneo
    }
    
    
    
}
