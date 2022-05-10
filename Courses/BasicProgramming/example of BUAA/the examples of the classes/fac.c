//求N!

#include <stdio.h>
main()
{
    unsigned long long m,n,result;
    double fres;
    for(n=1;n<=30;n++) //题目限制N(1 <= N <= 24),够用了?
    {

        result =1;
        fres=1;
        for(m=2;m<=n; m++)
        {

            result*=m;
            fres*=m;
        }
        printf("%llu!=%llu\n",n,result);
        printf("%llu!=%.0f\n",n,fres);


    }
}
