/*Scrivere in C una funzione ricorsiva int fun(int a[], int d) che restituisce 1 se le coppie di elementi opposti 
(primo e ultimo, secondo e penultimo, ecc.) dell’array hanno somma costante; restituisce 0 altrimenti. Ad esempio,
se fosse a = {3, 4, 1}, la funzione dovrebbe restituire 1, mentre se fosse a = {3, 2, 1, 1} dovrebbe restituire 0.
Si noti che se la lunghezza dell’array fosse dispari l’elemento centrale farebbe coppia da solo e non si sommerebbe con niente.
*/

#include <stdio.h>

int fun(int a[],int d);

int main()
{
    int a[5]={1,4,6,2,5},b[4]={1,3,4,5};
    
    printf("fun(a)=%d e fun(b)=%d\n",fun(a,5),fun(b,5));
    
    return 0;
}


int fun(int a[],int dim)
{
    int ris;
    if(dim ==0 || dim==1 || dim ==2)  //in questi casi e` con coppie a somme costanti
    {
        return 1;
    }
    else if(dim == 3) // basta controllare se la somma dei valore sulle posizioni 0 e 2 sia uguale al valore sulla posizione 1
    {
        return (a[0]+a[dim-1]==a[1]);
    }
    else
    {
        ris = fun(a+1,dim-2); // parto dal prossimo elemento e diminuisco la dimensione di una coppia
        if(ris == 0)  // basta una somma di coppia non costante e tutto l`array risulta non costante
        {
            return 0;
        }
        else
        {
            return (a[0]+a[dim-1]==a[1]+a[dim-2]);   //controllo se il primo+ultimo == secondo+penultimo
        }
    }
}
