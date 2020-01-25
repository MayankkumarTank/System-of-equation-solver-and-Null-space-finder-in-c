#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "Row_Elimination_Check_Solution_Type.c"
#include "Null_Finder.c"

int main()
{
    int n,m,j,i;
    printf("\n\t\tRoll No. AU1841057\n");
    printf("\nEnter the Following Details :: ");
    printf("\nEnter the Number of Rows of a Matrix (M): ");
    scanf("%d",&m);
    printf("\nEnter the Number of columns of a Matrix (N): ");
    scanf("%d",&n);
    
    printf("Enter Coefficient A for Ax=b: \n");
    
	float Coefficient_mat[m][n+1];
	//float **Coefficient_mat = NULL;
	//float **mat = (float **)calloc(m,sizeof(float *));
    for ( i = 0; i < m; i++)
    {    	
    	//mat[i] = (float *)calloc(n+1,sizeof(float));
    	
	    for (j = 0; j < n; j++)
        {
            printf("Enter the value of A[%d][%d]:",i+1,j+1);
            scanf("%f", &Coefficient_mat[i][j]);   
			
        }        
    }	
    printf("\nEnter Vector b for Ax=b: \n");
    for ( i = 0; i < m; i++)
    {    
		printf("Enter b[%d]:",i+1);
	    scanf("%f", &Coefficient_mat[i][n]);       
    }

   	printf("-----------------------------Augmented Matrix--------------------------------\n");
	
    Print_Matrix(m,n,Coefficient_mat);
    Row_Elimination_Check_Solution_Type(m,n,Coefficient_mat);
    printf("\n--------------------------------------------------------------------------------------------\n"); 
    printf("\n---------------------------------FINAL Matrix-----------------------------------------------\n");
	  
    Print_Matrix(m,n,Coefficient_mat);
    
    Null_Finder(m,n,Coefficient_mat);
    //free(Coefficient_mat);
 	return 0;
 	
}
/*
Dear sir,
		I am tried with dynamic memory allocation but  few errors are coming.(segmentation fault)
		and I am not able to fix it.without dynamic memory allocation it is fine working.
		Please, apologize me.
*/

