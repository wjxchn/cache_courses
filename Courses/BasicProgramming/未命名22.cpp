#include<stdio.h>
#include<math.h>
int main()
{
	char a,b;
	int g;
	double c,d,h;
	scanf("%c %c\n%lf %lf",&a,&b,&c,&d);
	g=floor(a/c)+floor(b/d); 
	h=(a/c)+(b/d);
	printf("%d\n%.2lf",g,h);
	return 0;
}
