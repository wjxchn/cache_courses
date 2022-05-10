#include<cstdio>
using namespace std;
int n;
int arr[1000010];
int k;
int p,q;
int change(int u,int v,int mid){
	int w;
	while(arr[u]<mid){
		u++;
	}
	while(arr[v]>mid){
		v--;
	}
	if(u<=v){
		w=arr[u];
		arr[u]=arr[v];
		arr[v]=w;
		return change(u+1,v-1,mid);
	}
	else{
		return u;
	}
}
void sort1(){
	int i,j,mid;
	i=0;
	j=n-1;
	mid=arr[n/2];
	if(i<=j){
		p=change(i,j,mid);
	}
	else{
		p=i;
	}
}
void sort2(){
	int i,j,mid;
	i=0;
	j=p-1;
	mid=arr[p/2];
	if(i<=j){
		q=change(i,j,mid);
	}
	else{
		q=i;
	}
}
int main()
{
	scanf("%d",&n);
	for(k=0;k<n;k++){
		scanf("%d",&arr[k]);
	}
	sort1();
	sort2();
	for(k=q;k<p;k++){
		printf("%d ",arr[k]);
	}
}
