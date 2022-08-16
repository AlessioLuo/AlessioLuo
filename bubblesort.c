/*Scrivere un programma che legga una sequenza di 10 float e poi li stampi in ordine dal più piccolo al più grande.*/

#include <stdio.h>
#define N 10
void scambio(float *p1,float *p2);

int main()
{
   float sequenza[N];
   int i,j;
   
   printf("Inserisci 10 numeri:\n");
   for(i=0;i<N;i++)
   {
       printf("Inserisci il %d numero\n",i+1);
       scanf("%f",&sequenza[i]);
   }
   
   printf("La sequenza inserita:\n");
   for(i=0;i<N;i++)
   {
       printf("%f\n",sequenza[i]);
   }
   

    for(j=0;j<N;j++)
       {
           for(i=0;i<N-1;i++)
           if(sequenza[i]>sequenza[i+1])
           {
           scambio(&sequenza[i],&sequenza[i+1]);
           }
       }
      
   
   
   printf("La sequenza ordinata:\n");
   for(i=0;i<N;i++)
   {
       printf("%f\n",sequenza[i]);
   }

    return 0;
}

void scambio(float *p1,float *p2) //input 2 numeri e cambio il loro ordine
{
    float temp;
    
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
