/*Scrivere una funzione ricorsiva che dati due numeri interi in ingresso (positivi), stabilisca se il primo numero è una potenza del secondo (con esponente strettamente positivo). 
Ad esempio, se i parametri fossero 81 e 3, la risposta sarebbe positiva; mentre con 100 e 5, la risposta dovrebbe essere negativa.
Se il primo parametro fosse più piccolo del secondo, la risposta sarebbe chiaramente negativa.

*/
#include <stdio.h>
int potenza(int a,int b);


int main(){
    
    int a,b;
    
    
    
    printf("Inserisci il primo numero\n");
    scanf("%d",&a);
    
    printf("Inserisci il secondo numero\n");
    scanf("%d",&b);
    
    if(potenza(a,b)==1)
    {
        printf("%d e` una potenza di %d\n",a,b);
    }
    else
    {
        printf("%d non e` una potenza di %d\n",a,b);
    }
    
    
    
    
    
    
    return 0;
}


int potenza(int a,int b)
{
    if(a<b) //se a<b sicuramente a non e` una potenza di b
    {
        return 0;
    }
    if(a==b) //se a=b sono sicuramente una potenza dell`altra
    {
        return 1;
    }
    if(b>1 && a%b == 0) //prima di tutto evito a/0,poi controllo il resto fino ad arrivare o a==b o a!=0
    {
        potenza(a/b,b);
    }
    else
    {
        return 0;
    }
}
