#include<stdio.h>
#include<time.h>

const int SHOWTIME = 100; // 3600(one hour), 36000

void wait ( int seconds )//��ʱ����
{
    clock_t endwait; //typedef	long	clock_t;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    //clock () ����һ��clock_t���͵�ֵ�����ֵ��ʾ����ӿ�ʼִ�е���ǰʱ�̴�����ʱ��
    //�����ֵת�����룬�������CLOCKS_PER_SEC
    //endwait ��������ֵ
    while (clock() < endwait) {}//
}

int main ()
{
    time_t rt; //���յ�ʱ������ڱ��� typedef	__time64_t time_t; typedef __int64 __time64_t; define __int64 long long
    struct tm *t; //��ʱ��ֽ���룬�֣�ʱ
    long int i;

    for (i=0; i<SHOWTIME; i++) //
    {
        time ( &rt ); //���ص�ǰ������ʱ��
        t = localtime ( &rt );//����ʱ��ת���ɷֽ�ʱ��
        system("cls");
        printf("\n\n\n\n\tBUAA Time:");
        printf("\n\t");
        printf ( "%d.", t->tm_year+1900 );//1900����������
        printf ( "%d.", t->tm_mon +1 );//1������������ 0~11
        printf ( "%d ", t->tm_mday);
        printf ( "%d:", t->tm_hour);
        printf ( "%d:", t->tm_min);
        printf ( "%d\n\n", t->tm_sec);
        wait (1);
    }
    return 0;
}
