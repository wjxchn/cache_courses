#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,w,s;
int i;
int a[100010];
int main()
{
	while(~scanf("%d%d",&n,&k)){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		w=n-1;
		while(a[w]!=0&&w>=0){
			s++;
			for(i=0;i<n;i++){
				a[i]--;
			}
			if(a[w]>0&&a[w]<=k){
				a[w]=0;
				w=w-1;
			}
			else if(w>k){
				a[w]-=k;
			}
			else if(a[w]==0){
				while(a[w]==0||w>=0){
					w=w-1;
				}
				if(w<0){
					break;
				}
				else{
					if(a[w]<=k){
						a[w]=0;
						w=w-1;
					}
					else
					{
						a[w]-=k;
					}
				}
			}
		}
		printf("%d",s);
	}
}
