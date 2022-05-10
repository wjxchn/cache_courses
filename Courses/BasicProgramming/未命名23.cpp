#include<stdio.h>
int main()
{
    double a,b,c,d,e,f;
    double i,j;
	scanf("%lf %lf %lf\n%lf %lf %lf",&a,&b,&c,&d,&e,&f);
	a*i+b*j==c;
	d*i+e*j==f;
	i=(c*e-b*f)/(a*e-b*d);
	j=(c*d-a*f)/(b*d-a*e);
	printf("(%.2lf,%.2lf)",i,j);
	return 0;	
} 
