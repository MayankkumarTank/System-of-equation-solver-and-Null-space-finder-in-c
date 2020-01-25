#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int Zero_Row_Indicator(int m, int n, float Coefficient_mat[m][n+1], int Row_Index){
	
	/*
	Method discription : If the whole row zero then this finction return the one....
							this is used for finding infinite solution or no solution...
	*/
	int i, cnt = 0;
	for(i=0; i<n; i++){
		if(Coefficient_mat[Row_Index][i] == 0 || Coefficient_mat[Row_Index][i] == (float)(-0)) {
			cnt++;
		}
	}
	if(cnt == n){
		return 1;
	}
	else {
		return 0;
	}
}
