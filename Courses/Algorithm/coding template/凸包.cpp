#include<cstdio>
#include<algorithm>
#include<cmath>
#define rint register int
using namespace std;

struct node {
	double x,y;
} a[100005];
int n,p,st[100005],top;
double ans,miny=2e9,minx=2e9;

int cmp(node b,node c) { //极角排序
	if (fabs((b.y-miny)*(c.x-minx)-(c.y-miny)*(b.x-minx))<=1e-8) return fabs(minx-b.x)<fabs(minx-c.x);
	return (b.y-miny)*(c.x-minx)<(c.y-miny)*(b.x-minx);
}

int check(int b,int c,int d) { //叉积判断
	return ((a[b].x*a[c].y)+(a[c].x*a[d].y)+(a[d].x*a[b].y)-(a[b].x*a[d].y)-(a[c].x*a[b].y)-(a[d].x*a[c].y))>0;
}

double dist(double x1,double y1,double x2,double y2) { //计算两点间的距离
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {
	rint i;
	scanf("%d",&n);
	for (i=1; i<=n; ++i) {
		scanf("%lf%lf",&a[i].x,&a[i].y);
		if (a[i].y<miny) { //寻找最下方的点
			miny=a[i].y;
			minx=a[i].x;
		}
	}
	sort(a+1,a+1+n,cmp); //极角排序
	st[1]=1;
	st[2]=2;
	top=2; //将两个点加入栈中
	for (i=3; i<=n; ++i) { //扫描
		while (!check(st[top-1],st[top],i)) top--;
		st[++top]=i;
	}
	for (i=2; i<=top; ++i) //计算答案
		ans+=dist(a[st[i-1]].x,a[st[i-1]].y,a[st[i]].x,a[st[i]].y);
	ans+=dist(a[st[top]].x,a[st[top]].y,a[1].x,a[st[1]].y);
	double area=0;
	for(i=1;i<top;i++){
		area+=(a[st[i]].x*a[st[i+1]].y-a[st[i+1]].x*a[st[i]].y);
	} 
	area+=(a[st[top]].x*a[st[1]].y-a[st[1]].x*a[st[top]].y);
	area/=2;
	printf("%.2lf %.2lf",ans,area);
	return 0;
}
