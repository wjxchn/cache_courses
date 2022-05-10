#include<stdio.h>
int gcd(int, int);
int main()
{
int a, b;
printf("Input two integers: ");
scanf("%d%d", &a, &b);
printf("%d\n", gcd(a, b));
return 0;
}
int gcd(int a, int b)
{
if ( b == 0 )
return a;
return gcd(b, a%b);
}
//a5-10最大公约数 
