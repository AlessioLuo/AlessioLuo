/*Scrivere una funzione ricorsiva che risolva il seguente problema: 
data una stringa s ed un carattere c (unici parametri della funzione), 
calcolare le occorrenze di c in s, ovvero quante volte c compare in s.*/

#include <stdio.h>
#include <string.h>
#define MAX 100
int occ(char s[],char c);


int main()
{
    char s[MAX] = "ciao come stai";
    char c = 'c';
    int dim;
    
    dim = occ(s,c);
    
    printf("%c e` apparso %d volte in %s\n",c,dim,s);
    
    return 0;
}


int occ(char s[],char c)
{
    if(strlen(s)==0)   //se la string e` vuota restituisco 0
    {
        return 0;    
    }
    else
    {
        if(s[0]==c) // se il carattere attuale e` uguale a c, restituisco 1 occorenza + analisi del prossimo carattere
        {
            return 1 + occ(s+1,c);
        }
        else  //se l`attuale carattere e` diverso da c,allora analizzo il prossimo;
        {
            return occ(s+1,c);
        }
    }

}
