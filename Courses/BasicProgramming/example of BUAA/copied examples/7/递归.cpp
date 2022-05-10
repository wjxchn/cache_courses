#include<stdio.h>
unsigned long f( unsigned long );
int main()
{
int i;
for(i = 1; i <= 10; i++ )
printf("%2d != %lu\n", i, f(i));
return 0;
}
unsigned long f(unsigned long n)
{
if ( n <= 1 )
return 1;
return ( n * f(n-1) );
}
