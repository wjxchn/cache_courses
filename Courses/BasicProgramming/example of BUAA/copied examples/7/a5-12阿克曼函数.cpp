#include<stdio.h>
int ack(int, int);
int main()
{
int m, n, r;
printf("Input two integers (>=0): ");
scanf("%d%d", &m, &n);
printf("ack num is: %d\n", ack(m, n));
return 0;
}
int ack(int m, int n)
{
if ( 0 == m ) return n+1;
if ( 0 == n ) return ack(m-1, 1);
return ack(m-1, ack(m, n-1));
}
//a5-12°¢¿ËÂüº¯Êı 
