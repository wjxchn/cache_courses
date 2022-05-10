#include<stdio.h>
void move(int n,int from,int to)
{
	printf("move disc %d from %c to %c\n",n,from,to);
} 
void hanoi(int n,int from,int via,int to)
{
	if(n==1){
		move(n,from,to);
		return;
	}
	hanoi(n-1,from,to,via);
	move(n,from,to);
	hanoi(n-1,via,from,to);
}
int main()
{
	hanoi(6,'A','B','C');
	return 0;
}
