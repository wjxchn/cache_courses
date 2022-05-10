/*
  �ֵ������㷨��Сд��ĸ��ʹ�õ����ݽṹΪ26����
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//���Ľṹ
typedef struct _word
{
    int flag[26];               //���±�i������Ԫ�ر����ĸi�Ƿ���֣�0��ʾδ���֣�1��ʾ���֣�2��ʾ������Ϊ�ַ����Ľ�β
    struct _word *next[26];     //��ĸi������
} word;
/* ��w��ָ����ַ�����ӵ���*tree�� */
void wordtree (char *w, word ** tree)
{
    if (*w != 0)                //���wδָ���ַ�����ĩβ
    {
        if (*tree == NULL)      //�����Ϊ�գ�������������ʼ��
        {
            *tree = (word *) malloc (sizeof (word));
            int i;
            for (i = 0; i < 26; i++)
            {
                (*tree)->next[i] = NULL;
                (*tree)->flag[i] = 0;
            }
        }
        if ((*tree)->flag[(*w) - 'a'] == 0)
            (*tree)->flag[(*w) - 'a'] = 1;      //�����ĸ*w����
        if (*(w + 1) == 0)      //���*wΪ�ַ�����β
            (*tree)->flag[(*w) - 'a'] = 2;
        else
            wordtree (++w, &((*tree)->next[(*w) - 'a']));       //��һ����ĸ
    }
}
char tmp[30];                   //��¼��ӡ���ַ���
void printtree (word * tr, int pos ) /* tmp�е�λ�� */
{
    if (tr != NULL)
    {
        int i;
        for (i = 0; i < 26; i++)
            if (tr->flag[i] > 0)
            {
                tmp[pos] = i + 'a';
                if (tr->flag[i] == 2)
                {
                    tmp[pos + 1] = 0;
                    printf ("%s/n", tmp);
                }
                printtree (tr->next[i], pos + 1);
            }
    }
}
int main ()
{
    freopen ("dictword.txt", "r", stdin);
    word *tr = NULL;
    char str[30];
    while (scanf ("%s/n", str) != -1)
        wordtree (str, &tr);
    printtree (tr, 0);
    return 0;
}

