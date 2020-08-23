//The Euler Maclaurin formula
#include <stdio.h>
#include<math.h>
#define f(x) (2*x*x + 3*x + 1)
int main()
{
    int n,x,k;
    float a,b,i,f=0;
    float B[] = {1, 0.5, 0.167, 0, -0.033, 5, 0.0238}; 
    float p,q;
    float y, c[10];
	int deg,j;
	float fa,fb;
    int l;
	float  g[10], di1 = 0, di2 = 0, pt;
	float d[10],dy1=0,dy2=0,dx1=0,dx2=0,ps;
    unsigned long long fact = 1;
    float I=0;
    printf("\n\n Enter Upper limit:");
    scanf("%f", &b);
    printf("\n\n Enter Lower limit:");
    scanf("%f", &a);
    printf("Enter the degree of polynomial equation: ");
	scanf("%d", &deg);
	for(j=0;j<=deg;j++)
	{
		printf("Enter the coefficient of x to the power %d: ",j);
		scanf("%f",&c[j]);

	}
//first term integration
    for(l=0;l>=deg-3;l--)
	{
	    y=b;
	   	pt = pow(y, deg+(l+1));
         printf("\n\npt %.2f",pt);  
		g[l] = (deg+l)*c[deg+l]*pt;
        printf("\n\ng %.2f",g[l]);
		di1 = di1 + g[l];
        printf("\nThe value %.2f",di1);
	}
	di1 = di1 + y;
    printf("\nThe value for the integration for the polynomial equation is: %.2f",di1);
	
//second term integration
	for(l=0;l>=deg-3;l--)
	{
	    y=a;
	   	ps = pow(y, deg+(l+1));
        printf("\n\npt %.2f",ps);  
		g[l] = (deg+l)*c[deg+l]*ps;
        printf("\n\ng %.2f",g[l]);
		di2 = di2 + g[l];
        printf("\nThe value %.2f",di2);
	}
	di2 = di2 + y;
    printf("\nThe value for the integration for the polynomial equation is: %.2f",di2);
	f = f + (di1-di2);
//second term 1/2 (f(b)-f(a))
    f = f - (0.5 * (f(b)-f(a)));
//first derivative part 1
  	for(j=0;j<=deg;j++)
	{
		y=b;
		ps = pow(y, deg-(j+1));
		d[j] = (deg-j)*c[deg-j]*ps;
		dy1 = dy1 + d[j];
	}
	printf("\n\n%f",dy1);
//first derivative part 2
	for(j=0;j<=deg;j++)
	{
	    y = a;
	    ps = pow(y, deg-(j+1));
		d[j] = (deg-j)*c[deg-j]*ps;
		dy2 = dy2 + d[j];
	}
	printf("\n\n%f",dy2);
//second derivative part 1
	for(j=0;j<=deg-1;j++)
	{
		ps = pow(c[2]*deg, deg-(j+1));
		d[j] = (deg-j-1)*ps;
		dx1 = dx1 + d[j];
	}
    printf("\n\n%f",dx1);
//second derivative part 2
	for(j=0;j<=deg-1;j++)
	{
		ps = pow(c[2]*deg, deg-(j+1));
		d[j] = (deg-j-1)*ps;
		dx2 = dx2 + d[j];
	}
    printf("\n\n%f",dx2);
//q indicates how many times you need to differntiate the term to get constant
    {    
        q = deg+1;
        p = (q+1)/2;
        printf ("\n\nValue for p: %f" ,p);
        for (k=1; k<=p; k++)
        {
        for (i = 1; i <=2*k; ++i)
            {
                fact *= i;
            }
        if(k==1)
        {
	            fb = dy1;
	            fa = dy2;
	    }
	    else
        {
	            fb = dx1;
	            fa = dx2;
	    }
        I = I + ((B[2*k]) / (fact)) * (fb-fa);
        }
    }
    printf("\n\n%f",I);
    {
    f = f+I;
    printf("\n\n%f",f);
    }
//last term f(b)
    f = f + f(b);
    printf("\n\nThe true solution for the integral is :%f", f);
}
