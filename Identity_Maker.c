#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void Identity_Maker(int m,int n,float Coefficient_mat[m][n+1],int solution_type)
{   
	/*
	Method discription : this method for making the matrix identity means all piivots are going to one.
						m = number of rows of A
						n = number of columns of A..
						Solution type = 0 , means system of equations have no solution..
						Solution type = 1 , means system of equations have unique solution..
						Solution type = 2 , means system of equations have infinite solution..
	*/
	int minimum_row_column = 0  ;
	if(n > m){
		minimum_row_column=m;
	}else{
		minimum_row_column = n;
	}
	int i=0,j=0,k=0,l=0;
	int number_of_pivots = 0;
	for(l=0; l<minimum_row_column; l++)
	{
		if(Coefficient_mat[l][l] != 0)
		{
			number_of_pivots++;
		}
	}
	for(i=0;i<minimum_row_column;i++)
	{
		float priv=Coefficient_mat[i][i];
		if(priv)
		{
			for(j=0;j<n+1;j++)
		{
			Coefficient_mat[i][j]/=priv;
		}
			
		}
		
	}
	if(solution_type == 1 || solution_type == 2)
	{
		printf("\n--------------------------------------------------------------------------------------------\n"); 
		printf("\n--------------------------------------------------------------------------------------------\n"); 
		printf("\n--------------------------------------Solution----------------------------------------------\n");
		if(number_of_pivots==n && number_of_pivots==m)
		{
			int loop=0;
			for(loop=0;loop<n;loop++)
			{
				if(Coefficient_mat[loop][loop] != 0)
				{
					printf("X%d    =   %.4f\n",loop+1,(Coefficient_mat[loop][n])/Coefficient_mat[loop][loop]);
				}
			
			}
		}
		else if(number_of_pivots<n)
		{
			int loop=0;
			int sum=0;
			int j =0;
			printf("\n Taking free variable's value as Value = 1 ...\n");
			for(loop=0;loop<n;loop++)
			{
				for(j = n-m;j<n;j++)
				{
					sum += Coefficient_mat[loop][j];
				}
				if(Coefficient_mat[loop][loop] != 0)
				{
					
					printf("X%d   =   %.4f\n",loop+1,((Coefficient_mat[loop][n]-sum)/Coefficient_mat[loop][loop]));
				}
				else if(Coefficient_mat[loop][loop] == 0)
				{
					printf("X%d   =  1.0000\n",loop+1);
				}
			}
		}
		else if(number_of_pivots>n)
		{
			int loop=0;
			for(loop=0;loop<n;loop++)
			{
				if(Coefficient_mat[loop][loop] != 0)
				{
					printf("X%d = %f\n",loop+1,(Coefficient_mat[loop][n]/Coefficient_mat[loop][loop]));
				}
				else if(Coefficient_mat[loop][loop] == 0)
				{
					printf("X%d   =  1.0000\n",loop+1);
				}
			}
		}
		}
}
