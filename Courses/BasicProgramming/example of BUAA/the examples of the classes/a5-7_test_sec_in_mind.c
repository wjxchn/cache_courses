#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    long d = 46*365*24*60*60;
    long t1, t2;
    int counter = 1, total = 0, step;
    char getflag = '1';
    printf("\nThis is the contest of reading second, come on!\n");

//    printf("2016-01-01-00:00 is: %ld s\n", d);
//    d = 47*365*24*60*60;
//    printf("2017-01-01-00:00 is: %ld s\n\n", d);
//    printf("%21s%u s\n", "Current time is: ", time(0));

    printf("\nRule: Press Enter to read second, 0 then Enter to finish the contest.\n");
    printf("\n\nPress Enter to go ...");
    getchar();

    while(1)
    {
        printf("%3d : ", counter);

        t1 = clock();
        getflag = getchar();
        if(getflag == '0') break;
        t2 = clock();
        step = t2-t1;

        counter++;
        total += step;

        printf("%22s", "click speed is : ");
        printf("%d ms\n", step);

        t1 = t2;
    }

    t2 = clock();
    step = t2-t1;
    total += step;
    printf("%22s", "click speed is : ");
    printf("%d ms\n", step);

    printf("\n  Click times: %d\n", counter);
    printf("      Totally: %d ms\n", total);
    printf("Average speed: %d ms\n", total/counter);

    return 0;
}
