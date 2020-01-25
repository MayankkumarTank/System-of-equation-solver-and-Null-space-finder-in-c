#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Null_Finder(int m,int n,float Coefficient_mat[m][n+1])
{
	//printf("called");
	/*
	Method discription : This function is used for finding the null space of a matrix....
	*/
	int i,number_of_pivots=0,j=0,k=0,l=0,s=0;
	int minimum_row_column;
	if(m < n) {
		minimum_row_column = m;
	} else {
		minimum_row_column = n;
	}
	for(i=0;i<minimum_row_column;i++)
	{
		if(Coefficient_mat[i][i]!=0)
		{
			number_of_pivots++;
		}
	}
	
	int rawzero=0;
	
	int pivot=0;
	
	if(n > m) {			  
		minimum_row_column = m;
	} else {
		minimum_row_column = n;
	}
	for(l=0;l<m;l++)
	{
		if(Zero_Row_Indicator(m,n,Coefficient_mat,l) == 1)
		{
			
			rawzero++;
		}
	}
	int rows_new = m - rawzero;
	float matrix_withno_zero_row[rows_new][n]; // here we are descarding the whole zero row....
	
	//float **matrix_withno_zero_row = NULL;
	//matrix_withno_zero_row = (float **) calloc(rows_new,sizeof(float *));
	
	int z=0;
	for(l=0;l<m;l++)
	{
		//matrix_withno_zero_row[l] = (float *)calloc(n,sizeof(float));
		if(Zero_Row_Indicator(m,n,Coefficient_mat,l) == 0)
		{
			for(j=0;j<n;j++)
			{
				matrix_withno_zero_row[z][j] = Coefficient_mat[l][j];
			}
			z++;
			
		}
	
	}
	/*
	swapping if  whole column is zero than we have to swap with pivot column for finding null space....
	*/
	int *storing_column_swap = (int *)calloc(n,sizeof(int));
	float temp=0;
	int cnt=0;
	for(i=0; i<n-1; i++)
	{
		for(j=i; j<rows_new; j++)
		{
			if(matrix_withno_zero_row[j][i]==0){
				cnt++;
			}
		}
		if(cnt==rows_new-i){
			int pivot_column = i;
			while(pivot_column<n){
				int next_col = pivot_column+1;
				if(cnt==rows_new-i && matrix_withno_zero_row[i][next_col]!=0)
				{
					for(k=0; k<rows_new; k++)
					{
						temp = matrix_withno_zero_row[k][i];
						matrix_withno_zero_row[k][i] = matrix_withno_zero_row[k][next_col];
						matrix_withno_zero_row[k][next_col] = temp;
					}
						storing_column_swap[i] = next_col;
						storing_column_swap[next_col] = i;
						break;
				}
				else{
					pivot_column++;
				}
			}
		}
		
		cnt = 0;
	}
	
	float F[rows_new][n-rows_new];
	
	//float **F = NULL;
	//F = (float **) calloc(rows_new,sizeof(float *));
	
	int r=0,c=0;
	
	for(i=0;i<rows_new;i++)
	{
		c=0;
		//F[i] = (float *)calloc((n-m+rawzero),sizeof(float));
		for(j=number_of_pivots;j<n;j++)
		{
			F[i][c] = -matrix_withno_zero_row[i][j];
			
			
				c++;
			
		}
		printf("\n");
		
	}
	printf("\n---------------------------------- NULL SPACE ------------------------------------\n"); 
	
		
	
	
	float I[c][c];
	
	for(i=0;i<c;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==j)
			{
				I[i][j] =1;
				
			}
			else
			{
				I[i][j] = 0;
			}
		}
	}
	if((rows_new) >= n)
	{
		for(i =0;i<n;i++)
		{
			printf("\t0.00\t\n");
		}
		
		
	}
	else{
		
		for(i=0;i<rows_new;i++)
		{
			for(j=0;j<c;j++)
			{
				printf("\t%.2f\t",F[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<c;i++)
		{
			if(i < (rows_new))
			{
				for(j=0;j<c;j++)
					{
						printf("\t%.2f\t",I[i][j]);
					}
					printf("\n");
			}
			
		}
	}
	
	
	float null[n][n-m+rawzero];
	int check_I = 0;
	int a=0,b=0;
	for(i =0;i<n;i++)
	{
		for(j=0;j<n-m+rawzero;j++)
		{
			if(i < rows_new)
			{
				null[i][j] = F[i][j];
			}
			else
			{
				null[i][j] = I[a][b];
				b++;
				check_I++;
			}
		}
		if(check_I != 0)
		{
			i++;	
		}
		
	}
	
	//Print_Matrix(m,n,Coefficient_mat);
	printf("\n--------------------------------------------------------------------------------------------\n"); 
}


