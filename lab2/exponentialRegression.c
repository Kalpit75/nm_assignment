#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
   
int main(){
    printf("exponential regression:\n\n");
    int i,n;
    float a,b,loga;
    float sx=0, slogy=0, sx2=0, sxlogy=0;
    
   	printf("Enter total data points: ");
   	scanf("%d",&n);
   	
   	float x[n],y[n];
	   	  	
   	for(i=0; i<n; i++)
	   {
   		printf("Enter x[%d] = ",i);
		scanf("%f",&x[i]);
		printf("Enter y=f[%.2f] = ",x[i]);
		scanf("%f",&y[i]);
	}
	
	for(i=0; i<n; i++){
		sx += x[i];
		slogy += log(y[i]);
		sxlogy += x[i]*log(y[i]);
		sx2 += (x[i]*x[i]);
	}

	printf("%f %f %f %f\n",sx,slogy,sxlogy,sx2);
	
	b = ((n*sxlogy) - sx*slogy) / ((n*sx2) - (sx*sx));
	loga = (slogy/n)- ((b*sx)/n);
	a = exp(loga);
	
	printf("a = %.2f \n",a);
	printf("b = %.2f \n",b);

	printf("y = %.2fe^%.2fx \n",a,b);
    
    return 0;
}
