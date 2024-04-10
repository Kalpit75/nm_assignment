    
#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
   
int main(){
    printf("linear least square method:\n\n");
    int i,n;
    float a,b;
    float sx=0, sx2=0, sy=0, sxy=0;
    
   	printf("Enter total data points: ");
   	scanf("%d",&n);
   	
   	float x[n],y[n];
	   	  	
   	for(i=0; i<n; i++){
   		printf("Enter x[%d] = ",i);
		scanf("%f",&x[i]);
		printf("Enter y=f[%.2f] = ",x[i]);
		scanf("%f",&y[i]);
	}
	
	for(i=0; i<n; i++){
		sx += x[i];
		sy += y[i];
		sxy += x[i]*y[i];
		sx2 += (x[i]*x[i]);
	}

	printf("%f %f %f %f\n",sx,sy,sxy,sx2);
	
	b = ((n*sxy) - sx*sy) / ((n*sx2) - (sx*sx));
	a = (sy/n)- ((b*sx)/n);
	
	printf("a = %.2f \n",a);
	printf("b = %.2f \n",b);
	if(b>=0)
		printf("y = %.2fm + %.2f \n",a,b);
	else 
		printf("y = %.2fm - %.2f \n",a,fabs(b));


    return 0;
}