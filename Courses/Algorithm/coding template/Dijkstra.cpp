#include<stdio.h>
#define INFINITY 2000000000
int n,m,s,a,b,c;
int wfound[100];
int Sweight[100];
int Weights[100][100];
int Spath[100];
int i,j;
void Dijkstra()
{
    int i, j, v, minweight;
    for(i=1; i<=n; i++) { Sweight[i] = Weights[1][i]; Spath[i] = 1; }  //��ʼ������Sweight��Spath
    Sweight [1] = 0;  
    wfound [1] = 1;  
    for(i=1; i<= n-1; i++) {  //����VNUM-1��
        minweight = INFINITY;
        for(j=1; j <= n;  j++)   //�ҵ�δ��ǵ���СȨ��ֵ���� 
            if( !wfound[j] && ( Sweight[j] < minweight) ) {
                v = j; 
                minweight = Sweight[v];
            }
        wfound[v] = 1;	//��Ǹö���Ϊ���ҵ����·��
        for(j =1; j <= n; j++) //�ҵ�δ��Ƕ�������Ȩֵ����v��Ȩֵ+(v,j)��Ȩֵ��������Ȩֵ
            if( !wfound[j]  &&  (minweight + Weights[v][j] < Sweight[j] )) {
                Sweight[j] = minweight + Weights[v][j];
                Spath[j] = v;  //��¼ǰ������
            }
    } 
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			Weights[i][j]=INFINITY;
		}
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);	
		Weights[a][b]=c;
	}
	Dijkstra();
	for(i=1;i<=n;i++){
		printf("%d ",Sweight[i]);
	}
}
