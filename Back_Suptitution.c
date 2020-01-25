#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "Identity_Maker.c"
void Back_Suptitution(int m,int n,float Coefficient_mat[m][n+1],int solution_type)
{	
	/*
	Method Discription :
						This method for doing the back suptitution and making matrix of only pivot colums else zeros.
						m = number of rows of A
						n = number of columns of A
					
	*/
	int minimum_row_column = 0;
	if(n>m){
		minimum_row_column=m;
	}else{
		minimum_row_column = n;
	}
	int i=0,j=0,k=0, l=0, number_of_pivots=0;
	printf("\n--------------------------------------------------------------------------------------------\n");   
	printf("\n-----------------------------------Back Suptitution-----------------------------------------\n");
	for(l = 0; l<minimum_row_column; l++){
		if(Coefficient_mat[l][l] != 0){
			number_of_pivots++;
		}
	}
	for(i=minimum_row_column-1; i>=0; i--)
	{
		
		float pivot=Coefficient_mat[i][i];
		if(pivot)
		{
			for(j=i-1;j>=0;j--)
			{			
				float divider=Coefficient_mat[j][i]/pivot;
				for(k=n;k>=0;k--)
				{
					Coefficient_mat[j][k]-=divider*Coefficient_mat[i][k];
				}
			}
			Print_Matrix(m,n,Coefficient_mat);	
		}	
				
	}
	Identity_Maker(m,n,Coefficient_mat,solution_type);	//this method called for making Identity metrix...
	
}
