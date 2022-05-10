#include<stdio.h>
#include<stdlib.h>
struct link {
	int u;
	struct link *next;
};

int main()
{
	int i,n,m,k;
	struct link *first=NULL, *p,*q,*r;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1; i<=n; i++){
		q = (struct link *)malloc(sizeof(struct link));
		q->u = i;
		q->next = NULL;
		if(first == NULL)
			first = p = q;
		else {
			p->next = q;
			p = p->next;
		}
	}
	p->next=first;
	p=first;
	for(i=1;i<k;i++){
//		r=p;
		p=p->next;
	} 

	while(p->next!=p){
		for(i=1;i<m-1;i++){
  //          r=p;
            p=p->next;
        }
        p->next=p->next->next;
		p=p->next; 
   //     r->next=p->next;
  //      free(p);
   //     p=r->next;
    }
    printf("%d", p->u);
    return 0;
}
	
