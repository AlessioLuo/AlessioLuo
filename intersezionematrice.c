/*Chiaedere all’utente di inserire una matrice A di r x c float 
(r e c letti da tastiera e minori di 10, mentre i valori della matrice possoono essere qualsiasi),
chiedere all'utente quante e quali righe e colonne di A selezionare, 
quindi restituire all’utente una seconda matrice B in cui sono contenuti i valori di intersezione delle righe e colonne di A selezionate.*/

#include <stdio.h>
#define MAX 10
int main()
{
    float matriceA[MAX][MAX],matriceB[MAX][MAX];
    int r,c;
    int i,j;
    int row[MAX],col[MAX],dim1,dim2;
    
    printf("Quante righe?\n");
    scanf("%d",&r);
    printf("Quante colonne?\n");
    scanf("%d",&c);
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Posizione [%d][%d]:",i,j);
            scanf("%f",&matriceA[i][j]);
        }
        printf("\n");
    }
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%.1f ",matriceA[i][j]);
        }
        printf("\n");
    }
    
    printf("Quante righe vuoi scegliere?\n");
    scanf("%d",&dim1);
    
    for(i=0;i<dim1;i++)
    {
    printf("Scegli una riga \n");
    scanf("%d",&row[i]);
    }
    
    printf("Quante colonne vuoi scegliere?\n");
    scanf("%d",&dim2);
    
    for(i=0;i<dim2;i++)
    {
    printf("Scegli una colonna \n");
    scanf("%d",&col[i]);
    }
    
    //in row[] ho le righe scelte,in col[] ho le colonne scelte
    
    //ora ho le righe e colonne di A scelte, crea una nuova matrice B che ha come righe e colonne quelle di A scelte
    
    for(i=0;i<dim1;i++)
    {
        for(j=0;j<dim2;j++)
        {
            
            {
                matriceB[i][j] = matriceA[row[i]][col[j]];
            }
        }
    }
    
    
    for(i=0;i<dim1;i++)
    {
        for(j=0;j<dim2;j++)
        {
            printf("%.1f ",matriceB[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
