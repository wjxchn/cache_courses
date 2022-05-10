#include <iostream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

//  �����ṹ��
struct Complex
{
    double x, y;    //  ʵ�����鲿 x + yi
    Complex(double _x = 0.0, double _y = 0.0)
    {
        x = _x;
        y = _y;
    }
    Complex operator - (const Complex &b) const
    {
        return Complex(x - b.x, y - b.y);
    }
    Complex operator + (const Complex &b) const
    {
        return Complex(x + b.x, y + b.y);
    }
    Complex operator * (const Complex &b) const
    {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

//  ����FFT��IFFTǰ�ķ�ת�任
//  λ��i�ͣ�i�����Ʒ�ת���λ�ã�����
//  len����ȥ2����
void change(Complex y[], int len)
{
    int i, j, k;
    for (i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
        {
            swap(y[i], y[j]);
        }
        //  ��������С�귴ת��Ԫ�أ�i < j��֤����һ��
        //  i��������+1��j��ת���͵�+1��ʼ�ձ���i��j�Ƿ�ת��
        k = len / 2;
        while (j >= k)
        {
            j -= k;
            k /= 2;
        }
        if (j < k)
        {
            j += k;
        }
    }
    return ;
}

//  FFT
//  len����Ϊ2 ^ k��ʽ
//  on == 1ʱ��DFT��on == -1ʱ��IDFT
void fft(Complex y[], int len, int on)
{
    change(y, len);
    for (int h = 2; h <= len; h <<= 1)
    {
        Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
    {
        for (int i = 0; i < len; i++)
        {
            y[i].x /= len;
        }
    }
}

const int MAXN = 200010;
Complex x1[MAXN], x2[MAXN];
char str1[MAXN], str2[MAXN],str3[MAXN],str4[MAXN];
int sum[MAXN];
int f3,f4;

int main(int argc, const char * argv[])
{
    while (cin >> str3 >> str4)
    {
    	f3=1;
    	f4=1;
    	if(str3[0]=='-'){
    		f3=-1;
    		strcpy(str1,str3+1);
		}
		else{
			strcpy(str1,str3);
		}
		if(str4[0]=='-'){
			f4=-1;
			strcpy(str2,str4+1);
		}
		else{
			strcpy(str2,str4);
		}
        int len1 = (int)strlen(str1);
        int len2 = (int)strlen(str2);
        int len = 1;
        while (len < len1 * 2 || len < len2 * 2)
        {
            len <<= 1;
        }
        for (int i = 0; i < len1; i++)
        {
            x1[i] = Complex(str1[len1 - 1 - i] - '0', 0);
        }
        for (int i = len1; i < len; i++)
        {
            x1[i] = Complex(0, 0);
        }
        for (int i = 0; i < len2; i++)
        {
            x2[i] = Complex(str2[len2 - 1 - i] - '0', 0);
        }
        for (int i = len2; i < len; i++)
        {
            x2[i] = Complex(0, 0);
        }
        //  ��DFT
        fft(x1, len, 1);
        fft(x2, len, 1);
        for (int i = 0; i < len; i++)
        {
            x1[i] = x1[i] * x2[i];
        }
        fft(x1, len, -1);
        for (int i = 0; i < len; i++)
        {
            sum[i] = (int)(x1[i].x + 0.5);
        }
        for (int i = 0; i < len; i++)
        {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        len = len1 + len2 - 1;
        while (sum[len] <= 0 && len > 0)
        {
            len--;
        }
        if(f3*f4==-1){
        	printf("-");
		}
        for (int i = len; i >= 0; i--)
        {
            printf("%c", sum[i] + '0');
        }
        putchar('\n');
    }

    return 0;
}
