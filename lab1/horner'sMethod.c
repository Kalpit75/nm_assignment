#include<stdio.h>
#include<conio.h>
#include<math.h>

void horner()
{
	int i,n;
	int x0;
	printf("\nEnter the degree of polynomail n = ");
	scanf("%d",&n);
	
	int a[n],b[n];
	
	printf("\nEnter the value of the coefficients : ");
	for(i=0;i<=n;i++)
	{
		printf("\nEnter the value of a%d = ",i);
		scanf("%d",&a[i]);
		
	}
	
	for(i=0;i<=n;i++)
	{
		printf("\n a%d = %d",i,a[i]);
	}
	
	printf("\nEnter the value at which polynomial to evaluate , i.e x0 =  ");
	scanf("%d",&x0);
	
	
	b[n]=a[n];
	printf("\n  b%d = %d ",n,b[n]);
	while((n-1)>=0)
	{
		b[n-1]=a[n-1]+b[n]*x0;
		printf("\n  b%d = %d ",(n-1),b[n-1]);
		n--;
	}
	printf("\nThe evaluated value at x=%d i.e p(%d) = %d ",x0,x0,b[0]);
}


int main(){
    printf("horner's method:\n\n");
	horner();
	return 0;
}