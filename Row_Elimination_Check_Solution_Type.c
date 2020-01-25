#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "Print_Matrix.c"
#include "Zero_Row_Indicator.c"
#include "Back_Suptitution.c"
#include "Row_Swapping.c"

void Row_Elimination_Check_Solution_Type(int m,int n,float Coefficient_mat[m][n+1])
{
	printf("------------------------------Row Elimination(Gaussian elimation)------------------------------------\n");
	
	/*
	Method Discription : 
						This method for row elimination based on gaussian elimination and making the upper tringular Matrix.
						here,
						m = number of rows of A
						n = number of columns of A
	*/
	int minimum_row_column = 0;          
	if(n > m) {			  
		minimum_row_column = m;
	} else {
		minimum_row_column = n;
	}
	int i=0,j=0,k=0,l=0;
	
	for(i = 0; i < minimum_row_column; i++)
	{	
		float pivot = Coefficient_mat[i][i];	//here, if pivot is not zero then we doing under pivot making all element zero.
		if(pivot != 0){	
			for(j = i + 1; j < m; j++)
			{
				float divider = Coefficient_mat[j][i]/pivot;
				for(k = 0; k < n+1; k++)
				{
					Coefficient_mat[j][k] -= divider*Coefficient_mat[i][k];
				}
			}
		}
		else if(pivot == 0){ // here, this loop for if pivot is not zero.
			Row_Swapping(m, n, Coefficient_mat, i); // if pivot is zero. we have to swap the row.
			pivot = Coefficient_mat[i][i];
			if(pivot != 0){
				for(j = i + 1; j < minimum_row_column; j++)
				{
					float divider = Coefficient_mat[j][i]/pivot;
					for(k = 0; k < m+1; k++)
					{
						Coefficient_mat[j][k] -= divider*Coefficient_mat[i][k];
					}
				}
			}
		}
		Print_Matrix(m,n,Coefficient_mat);
		
	}
	int number_of_pivots = 0;
	for(l=0; l<minimum_row_column; l++)
	{
		if(Coefficient_mat[l][l] != 0)
		{
			number_of_pivots++;
		}
	}
	if(m < n)    // Solution type for Fat matrix...
	{
		printf("\n----------------------------------Solution Type------------------------------------\n"); 
		printf("\n   ------>>      System have INFINITE SOLUTION...                                     \n");
		Back_Suptitution(m, n, Coefficient_mat,2);
	}
	else if(m == n) {               // Solution type for square matrix...
		if(number_of_pivots < n)              // number_of_pivots = number of pivots   
		{
			int i, j, Pivotyes = 0, PivotNo = 0;
			for(i=0; i<m; i++) {
				if(Zero_Row_Indicator(m, n, Coefficient_mat, i) == 1 && Coefficient_mat[i][n] == 0){
					Pivotyes++;
				}
				if(Zero_Row_Indicator(m, n, Coefficient_mat, i) == 1 && Coefficient_mat[i][n] != 0){
					PivotNo++;
				}
			}
			//printf("%d",Pivotyes);
			//printf("%d",PivotNo);
			
			if(PivotNo >= 1) {
				printf("\n----------------------------------Solution Type------------------------------------\n"); 
				printf("\n   ------>>      System have NO SOLUTION...                                     \n");
		
				Back_Suptitution(m, n, Coefficient_mat,0);
			}
			else if(Pivotyes >= 1) {
				printf("\n----------------------------------Solution Type------------------------------------\n"); 
				printf("\n   ------>>      System have INFINITE SOLUTION...                                     \n");
		
				Back_Suptitution(m, n, Coefficient_mat,2);
			} 
			
		
		}
		else if(number_of_pivots == n)
		{
			printf("\n----------------------------------Solution Type------------------------------------\n"); 
			printf("\n   ------>>      System have Unique SOLUTION...                                     \n");
		
			Back_Suptitution(m,n,Coefficient_mat,1);       //case of unique solution
			
		}
	}
	else if(m > n){                         // part of tall matrix...
		int tall_free = 0;
		for(l = number_of_pivots; l<m; l++){
			if(Coefficient_mat[l][n] == 0){
				tall_free++;
			}
		}
		if(tall_free == m-number_of_pivots){
			printf("\n----------------------------------Solution Type------------------------------------\n"); 
			printf("\n   ------>>      System have Unique SOLUTION...                                     \n");
		
			Back_Suptitution(m, n, Coefficient_mat,1);
			
		}
		else{
			printf("\n----------------------------------Solution Type------------------------------------\n"); 
			printf("\n   ------>>      System have NO SOLUTION...                                     \n");
			Back_Suptitution(m, n, Coefficient_mat,0);
		}			
	} 
}

