#include <stdio.h>

void conv(int A[][100], int B[][100], int K[3][3], int nr, int nc);
void stampa_matrice(int mat[][100],int n_righe,int n_col);


int main()
{
 int K[3][3] = {{0,-1,0},{-1,3,-1},{0,-1,0}};
 int A[6][100] = {{7,6,5,5,6,7},{6,4,3,3,4,6},{5,3,2,2,3,5},{5,3,2,2,3,5},{6,4,3,3,4,6},{7,6,5,5,6,7}}; //matrice A e B con dichiarazione [][100] perche` se non fosse cosi` la funzione conv non la legge
 int B[6][100];
 
 conv(A,B,K,6,6);
 printf("A:  \n");
 stampa_matrice(A,6,6);
 printf("B:  \n");
 stampa_matrice(B,6,6);
 
 return 0;
}

stampa_matrice(int mat[][100],int n_righe,int n_col)
{
    int i,j;
    
    for(i=0;i<n_righe;i++)
    {
        for(j=0;j<n_col;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    
}

void conv(int A[][100], int B[][100], int K[3][3], int nr, int nc)
{
    int i,j,l,m;
    
    for(i=0;i<nr;i++)
    {
        for(j=0;j<nc;j++)
        {
            int temp = 0; //un valore temporaneo dove salviamo i calcoli della convoluzione applicata su A, dopodiche` salvo il valore nella corrispondente posizione in B
            //applico la convoluzione che e` una matrice 3x3
            for(l=0;l<3;l++)
            {
                for(m=0;m<3;m++)
                {
                    int indice_riga_A = i-1+l;
                    int indice_col_A = j-1+m;
                    
                    if(indice_riga_A < 0 || indice_riga_A >= nr)
                    {
                        indice_riga_A = i;
                    }
                    if(indice_col_A < 0 || indice_riga_A >= nc)
                    {
                        indice_col_A = j;
                    }
                    
                    temp = temp + (A[indice_riga_A][indice_colonna_A]*K[l][m]);
                }
            }
            B[i][j]= temp;
            
            
        }
    }
    
    
}
