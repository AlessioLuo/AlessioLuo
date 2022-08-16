/*Scrivere una funzione swap in C che consenta di scambiare il valore di due variabili di tipo float.*/
#include <stdio.h>

void scambio(float *p1,float *p2);

int main()
{
    float a,b;
    
    printf("Inserisci a:\n");
    scanf("%f%*c",&a);
    printf("Inserisci b:\n");
    scanf("%f%*c",&b);
    
    printf("a: %f,b: %f \n",a,b);
    
    scambio(&a,&b);
    
    printf("a: %f,b: %f",a,b);
    
    

    return 0;
}

void scambio(float *p1,float *p2)
{
    float temp; //una variabile temporanea
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
