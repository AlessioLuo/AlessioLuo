/*Scrivere una funzione che riceve in ingresso un valore intero, quindi calcola e restituisce il numero di cifre che lo compongono e sono divisori del numero stesso.
Esempi: Se in ingresso la funzione riceve il valore 12, restituirà 2 (1 è divisore di 12, 2 è divisore di 12).
Se riceve in ingresso il valore 1012, restituisce 3 (1 e 2 sono divisori di 1012 e l’1 compare due volte, 0 non lo è).
Suggerimento:
Potete usare le funzioni atoi e sprintf
*/
#include <stdio.h>

int cifre(int n);

int main()
{
    printf("%d",cifre(1012));

    return 0;
}

int cifre(int n)
{
    int temp = n;
    int div;
    int cont=0;
    while(temp!=0) //finche` temp non arrivi a 0
    {
        div = temp%10;  //ultima cifra
        if(div != 0 && n%div == 0) //controllo se l`ultima cifra sia diversa da 0 (perche` 0 non e` mai divisore di n) e che div sia divisore di n
        {
            cont++; //se si`, aggiorno cont
        }
        temp = temp / 10;
    }
    
    return cont;
}
