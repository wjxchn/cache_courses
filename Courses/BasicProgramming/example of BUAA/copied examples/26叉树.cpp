/*
  字典排序算法，小写字母，使用的数据结构为26叉树
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//树的结构
typedef struct _word
{
    int flag[26];               //设下标i，数组元素标记字母i是否出现，0表示未出现，1表示出现，2表示出现且为字符串的结尾
    struct _word *next[26];     //字母i的子树
} word;
/* 将w所指向的字符串添加到树*tree中 */
void wordtree (char *w, word ** tree)
{
    if (*w != 0)                //如果w未指向字符串的末尾
    {
        if (*tree == NULL)      //如果树为空，则建立树，并初始化
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
            (*tree)->flag[(*w) - 'a'] = 1;      //标记字母*w出现
        if (*(w + 1) == 0)      //标记*w为字符串结尾
            (*tree)->flag[(*w) - 'a'] = 2;
        else
            wordtree (++w, &((*tree)->next[(*w) - 'a']));       //下一个字母
    }
}
char tmp[30];                   //记录打印的字符串
void printtree (word * tr, int pos ) /* tmp中的位置 */
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

