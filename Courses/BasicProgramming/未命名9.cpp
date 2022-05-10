#include <stdio.h>
#include <string.h>
int main()
{
    char a[200];
    int i, b= 0;
    gets (a);       
    for (i=0; i<strlen(a); i++)
    {
        if (a[i] == 89)
        {
            b ++;
        }
    }
    printf ("%d\n", b);
    return 0;
}
