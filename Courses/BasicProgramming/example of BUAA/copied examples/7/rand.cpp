#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
int point;
srand( time( 0 ) ); // unsinged int time(..);
point = 1 + rand()%6;
printf("Dice is: %d\n", point);
printf((point%2) ? "lose": "win");
return 0;
}
