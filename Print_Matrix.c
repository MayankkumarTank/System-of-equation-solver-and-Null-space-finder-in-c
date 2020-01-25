#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Print_Matrix(int m,int n,float Coefficient_mat[m][n+1])
{
	/*
	Method discription : this method for printing the augmented matrix.....
	*/
    int i,j;  
    printf("\n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j <= n; j++)
        {
        	if(j==n){printf("|");}
            printf("%0.2f\t",Coefficient_mat[i][j]);            
        }
        printf("\n");
    }   
}
