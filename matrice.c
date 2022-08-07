/*
Scrivere un programma che legga una matrice quadrata di dimensioni specificate dall'utente 
(al massimo 10 righe e 10 colonne). Quindi, calcoli e stampi la somma dei valori sulla diagonale principale,
la somma dei valori sopra la diagonale principale e la somma dei valori sotto la diagonale principale. 
*/

#include <stdio.h>
#define MAX 10

int main()
{
   
    int matrice[MAX][MAX];
    int dim;
    int i,j;
    int sumtop=0,sumdiag=0,sumbot=0;
    
    printf("Di che dimensione vuoi la matrice(Massimo 10)?\n");
    scanf("%d",&dim);
    
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("Posizione [%d][%d]:",i,j);
            scanf("%d",&matrice[i][j]);
            
        }
    }
    
    printf("Matrice inserita:\n");
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("%d ",matrice[i][j]);
           
            
        }
        printf("\n");
    }
    
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(i==j)
            {
                sumdiag=sumdiag+matrice[i][j];
            }
        }
    }
    printf("Somma dei valori sulla diagonale: %d\n",sumdiag);
    
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(j>i)
            {
                sumtop = sumtop + matrice[i][j];
            }
            
        }
    }
    printf("Somma valori sopra diagonale: %d\n",sumtop);
    
        for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(i>j)
            {
                sumbot = sumbot + matrice[i][j];
            }
            
        }
    }
    printf("Somma valori sotto diagonale: %d\n",sumbot);
    return 0;
}
