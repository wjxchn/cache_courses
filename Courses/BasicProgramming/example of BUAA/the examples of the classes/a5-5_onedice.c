#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int onedice, total = 0, gambling;
    srand( time( 0 ) ); // unsinged int time(..);

    printf("$$$$$       Welcome  to      $$$$$$$\n");
    printf("$$$$$  the Hotel of Shahang  $$$$$$$\n\n");
    printf("Rules: Odd, lose;  Even, win.\n");

    while(1)
    {
        printf("\nInput $# to play again, or, Input q or Q key to quit.");
        printf("\n\n   $");

        if(scanf("%d", &gambling) == 0 || gambling <= 0)  break;

        onedice =  1 + rand()%6;
        printf("\nDice is: %d\n", onedice);
        if (onedice % 2 == 0 ) // onedice <=3, or other condition
        {
            total += gambling;
            printf("You win:  $%d  ^_^\n", gambling);
        }
        else
        {
            total -= gambling;
            printf("You lose $%d  >_<\n", gambling);
        }

        printf("\nNow, you have won:  $%d\n", total);
    }

    printf("\n\nHave a nice day. Welcome back soon.\n");
    return 0;
}


/*
int main()
{
   int flag_roll = 1, onedice, total = 0, gambling;
   srand( time( 0 ) ); // unsinged int time(..);

   printf("$$$$$       Welcome  to      $$$$$$$\n");
   printf("$$$$$  the Hotel of Shahang  $$$$$$$\n\n");
   printf("Rules: Odd, lose;  Even, win.\n");
   while(flag_roll == 1){
       printf("\nYour gambling: ");
       scanf("%d", &gambling);

	   onedice =  1 + rand()%6;
       printf("Dice is: %d\n", onedice);
       if (onedice % 2 == 0 ) // onedice <=3, or other condition
       {   total += gambling;
           printf("You win:  $%d\n", gambling);
       }
       else
       {   total -= gambling;
           printf("You lose $%d\n", gambling);
       }

        printf("\nNow, you have won:  $%d\n", total);

		printf("\ninput 1 to continue, other to quit: ");
		scanf("%d", &flag_roll);
	}

	printf("Have a nice day. Welcome back soon.\n");
	return 0;
}
*/
