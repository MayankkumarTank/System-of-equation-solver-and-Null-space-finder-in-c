#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Row_Swapping(int m,int n,float Coefficient_mat[m][n+1], int Row_index)
{
	/*
	Method discription : this menthod for swapping the row.this method called when pivot is zero.here,I am finding the not zero 
							element on that row and swap it...
	*/
	int temp, i, j, k, l;
	for(i=Row_index + 1; i < m; i++){
		if(Coefficient_mat[i][Row_index] != 0){
			int temp;
			for(j=0; j<=n; j++){
				temp = Coefficient_mat[i][j];
				Coefficient_mat[i][j] = Coefficient_mat[Row_index][j];
				Coefficient_mat[Row_index][j] = temp;
			}
			break;
		}
	}	
}
