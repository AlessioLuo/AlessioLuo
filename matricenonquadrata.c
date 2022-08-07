/*Matrice non quadrata,
SOMMA DIAGONALE,SOMMA SOPRA DIAGONALE,SOMMA SOTTO DIAGONALE
*/

#include <stdio.h>
#define MAX 10

int main()
{
   
    int matrice[MAX][MAX];
    int row,col;
    int i,j;
    int sumtop=0,sumdiag=0,sumbot=0;
    
    printf("Quante righe?\n");
    scanf("%d",&row);
    printf("Quante colonne?\n");
    scanf("%d",&col);
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("Posizione [%d][%d]:",i,j);
            scanf("%d",&matrice[i][j]);
            
        }
    }
    
    printf("Matrice inserita:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",matrice[i][j]);
           
            
        }
        printf("\n");
    }
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i==j)
            {
                sumdiag=sumdiag+matrice[i][j];
            }
        }
    }
    printf("Somma dei valori sulla diagonale: %d\n",sumdiag);
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(j>i)
            {
                sumtop = sumtop + matrice[i][j];
            }
            
        }
    }
    printf("Somma valori sopra diagonale: %d\n",sumtop);
    
        for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
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
