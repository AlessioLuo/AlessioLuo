/*Scrivere una funzione che riduce una stringa rimuovendo tutte le sue vocali. Si scriva poi un programma che lette due stringhe, verifica se queste sono uguali a meno delle vocali (esempio “ripieno” e “rapina”).
Implementare tre diverse versioni della funzione riduci:

void riduci_iter(char *s); // versione iterativa che modifica s
void riduci_ric(char *s); // versione ricorsiva che modifica s
char* riduci_ric2(char *s); // versione ricorsiva che NON modifica s e 
 // restituisce la stringa senza vocali
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void riduci_iter(char *s);
void riduci_ric(char *s);
char* riduci_ric2(char *s);


int main()
{
    char string[10],string2[10];
    char *s3;

    printf("Inserisci una stringa:\n");
    scanf("%s",string);
    printf("Inserisci una string:\n");
    scanf("%s",string2);
   
    riduci_iter(string);
    riduci_ric(string2);
    s3 = riduci_ric2(string);
    
    printf("stringa 1 ridotta (con ric2): %s\n", s3);
    printf("stringa 1:%s\n",string);
    printf("stringa 2:%s\n",string2);
    
    if(strcmp(string,string2)==0)
    {
        printf("Le due stringhe sono uguali \n");
    }
    else
    {
        printf("Senza vocali sono diverse\n");
    }
    
    
    
    return 0;
}

void riduci_iter(char *s) //puntatore a s,quindi posso modificare s
{
    int i,j=0;
    
    for(i = 0;s[i] != '\0';i++)
    {
        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
        {
            s[j] = s[i];
            j++;
        }
    }
    
    s[j] = '\0';
}

void riduci_ric(char *s)
{
    if(strlen(s) == 0)
    {
        return;
    }
    
    riduci_ric(s+1); //analizzo dal prossimo carattere
    
    if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') //se il primo carattere analizzato e` una vocale
    {
      for(int i=1;i<strlen(s)+1;i++)  
      {
          s[i-1] = s[i];  //la sostuituisco con il prossimo carattere
      }
    }
}


char* riduci_ric2(char *s) //restuituisce un puntatore
{
    
    if(strlen(s)==0)
    {
        return "";
    }
    if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u')
    {
    riduci_ric2(s+1);
    }
    else
    {
        char *new_s = (char *)malloc(sizeof(char)*strlen(s)+1); 
        char *suff = riduci_ric2(s+1);
        new_s[0] = s[0];
        new_s[1] = '\0';
        strcat(new_s,suff);
        if(strlen(suff)>0)
        {
            free(suff);
        }
        return new_s;
    }
    
    
}
