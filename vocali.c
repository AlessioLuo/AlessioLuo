/*Scrivere una funzione che riduce una stringa rimuovendo tutte le sue vocali. 
Si scriva poi un programma che lette due stringhe, verifica se queste sono uguali a meno delle vocali (esempio “ripieno” e “rapina”).*/

#include <stdio.h>
#include <string.h>
#define MAX 100
void vocali(char *s);

int main()
{
    
    char s1[MAX],s2[MAX];
    
    printf("Inserisci una stringa:\n");
    scanf("%[^\n]%*c",s1);
    printf("Inserisci una stringa:\n");
    scanf("%[^\n]%*c",s2);
    
    vocali(s1);
    printf("La stringa1 ridotta: %s \n",s1);
    vocali(s2);
    printf("La stringa2 ridotta: %s \n",s2);
    
    if(strcmp(s1,s2)==0)
    {
        printf("S1 e S2 sono uguali\n");
    }
    else
    {
        printf("le due stringhe sono diverse\n");
    }
    
}


void  vocali(char *s) //uso il puntatore perche` dato un indirizzo con qualcosa salvato, voglio modificare il valore salvato nello stesso indirizzo
{
    int i,j=0; // il primo contatore per scorrere la string s, il secondo per copiare le consonanti di secondo
    
    for(i=0;s[i] != '\0';i++)
    { 
        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
        {
            s[j] = s[i]; // se s[i] non e` una vocale(quindi consonante) copio la lettera in s[j] 
            j++;
        }
    }
    s[j] = '\0';
}

//finita la funzione la string originale sara` sovrascritta da solo consonanti
