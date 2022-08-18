/*
Scrivere una funzione ricorsiva min che riceve in ingresso un vettore v di float, 
la lunghezza n del vettore, e restituisce il valore più piccolo del vettore v.*/

#include <stdio.h>
float min(float v[],int dim);

int main()
{
    float v[]={8.6,4.87,5.15,97.94,12.65,48.31};
    float minimo;
    
    minimo = min(v,6);
    
    printf("Il valore minimo trovato e`: %f",minimo);
       
    return 0;
}

float min(float v[],int dim)
{
    float min;
    min = v[0];  //pongo il primo valore dell`array come minimo
    
    for(int i=1;i<dim;i++) 
    {
        if(v[i]<min) //confronto tutto l`array con il primo valore, se si presenta un numero minire,esso diventa il nuovo min
        {
            min = v[i];
        }
    }
    
    return min; //la funzione mi restituisce il valore minimo
}
