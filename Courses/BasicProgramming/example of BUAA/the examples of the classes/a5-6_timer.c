#include<stdio.h>
#include<time.h>

const int SHOWTIME = 100; // 3600(one hour), 36000

void wait ( int seconds )//延时函数
{
    clock_t endwait; //typedef	long	clock_t;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    //clock () 返回一个clock_t类型的值，这个值表示程序从开始执行到当前时刻处理器时间
    //把这个值转换成秒，将其除以CLOCKS_PER_SEC
    //endwait ：计数终值
    while (clock() < endwait) {}//
}

int main ()
{
    time_t rt; //紧凑的时间和日期编码 typedef	__time64_t time_t; typedef __int64 __time64_t; define __int64 long long
    struct tm *t; //把时间分解成秒，分，时
    long int i;

    for (i=0; i<SHOWTIME; i++) //
    {
        time ( &rt ); //返回当前的日历时间
        t = localtime ( &rt );//日历时间转换成分解时间
        system("cls");
        printf("\n\n\n\n\tBUAA Time:");
        printf("\n\t");
        printf ( "%d.", t->tm_year+1900 );//1900以来的年数
        printf ( "%d.", t->tm_mon +1 );//1月以来的月数 0~11
        printf ( "%d ", t->tm_mday);
        printf ( "%d:", t->tm_hour);
        printf ( "%d:", t->tm_min);
        printf ( "%d\n\n", t->tm_sec);
        wait (1);
    }
    return 0;
}
