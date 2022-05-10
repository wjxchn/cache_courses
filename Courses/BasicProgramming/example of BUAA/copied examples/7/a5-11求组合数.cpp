#include<stdio.h>
int comb_num(int, int);
int main()
{
int m, n;
printf("Input two integers: ");
scanf("%d%d", &m, &n);
printf("%d\n", comb_num(m, n));
return 0;
}
int comb_num(int m, int n){
if ( m<n || m<1 || n<1 ) return 0;
if ( n == 1 ) return m;
if ( n == m ) return 1;
return comb_num(m-1, n) +
comb_num(m-1, n-1);
}
//a5-11求组合数 
