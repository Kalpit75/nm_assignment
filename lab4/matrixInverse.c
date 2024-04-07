#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 10
int main(){
	float a[SIZE][2*SIZE],ratio;
	int i,j,k,n;
	printf("Gauss Jordan Method for Matrix Inversion:\n");
	printf("Enter the order of matrix=");
	scanf("%d",&n);
	printf("Enter coefficient of matrix:\n");
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("a[%d][%d]=",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				a[i][j+n]=1;
			}
			else{
				a[i][j+n]=0;
			}
		}
	}
	for (i=0;i<n;i++){
		if(a[i][i]==0.00){
			printf("Mathematical error!\n");
			exit(0);
		}		
		for(j=0;j<n;j++){
			if(i!=j){
				ratio=a[j][i]/a[i][i];
				for(k=0;k<2*n;k++){
					a[j][k]=a[j][k]-ratio*a[i][k];
				}
			}
		}
	}
	for (i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			a[i][j]=a[i][j]/a[i][i];
		}
	}
	printf("\nInverse Matrix is:\n");
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			printf("%.3f\t",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
