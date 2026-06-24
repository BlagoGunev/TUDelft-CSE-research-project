#include <stdio.h>
#include <algorithm>
int n,m,tot,path[100001],kk;
struct q3{
	int pass,cap,no;
	bool operator() (q3 a,q3 b){
		return a.pass>b.pass;
	}
}heap[100001];
struct q{
	int pass,cap,no;
	bool operator() (q a,q b){
		return a.cap>b.cap;
	}
}su[100001];
struct q2{
	int no,comp;
	bool operator() (q2 a, q2 b){
		return a.comp>b.comp;
	}
}bug[100001];
bool check(int max){
	int i,j=0,sum=0;
	kk=0;
	for(i=0;i<m;i+=max){
		for(;j<n;j++){
			if(bug[i].comp>su[j].cap) break;
			heap[kk].cap=su[j].cap;
			heap[kk++].pass=su[j].pass;
			std::push_heap(heap,heap+kk,q3());
		}
		if(kk==0) return false;
		sum+=heap[0].pass;
		if(sum>tot) return false;
		std::pop_heap(heap,heap+kk,q3());
		kk--;
	}
	return true;
}
void pro(int max){
	int i,j=0,sum=0,k;
	kk=0;
	for(i=0;i<m;i+=max){
		for(;j<n;j++){
			if(bug[i].comp>su[j].cap) break;
			heap[kk].cap=su[j].cap;
			heap[kk].no=su[j].no;
			heap[kk++].pass=su[j].pass;
			std::push_heap(heap,heap+kk,q3());
		}
		sum+=heap[0].pass;
		for(k=0;k<max;k++){
			if(i+k<m)
				path[bug[i+k].no]=heap[0].no;
		}
		std::pop_heap(heap,heap+kk,q3());
		kk--;
	}
}
int main(){
	int i,low,high,mid,print=-1;
	//freopen("input.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&tot);
	for(i=0;i<m;i++){
		scanf("%d",&bug[i].comp);
		bug[i].no=i;
	}
	for(i=0;i<n;i++){
		scanf("%d",&su[i].cap);
		su[i].no=i+1;
	}
	for(i=0;i<n;i++)
		scanf("%d",&su[i].pass);
	std::sort(su,su+n,q());
	std::sort(bug,bug+m,q2());
	low=1;high=m;
	while(low<=high){
		mid=(low+high)>>1;
		if(check(mid)){
			high=mid-1;
			print=mid;
		}
		else
			low=mid+1;
	}
	if(print==-1)
		printf("NO\n");
	else{
		printf("YES\n");
		pro(print);
		for(i=0;i<m;i++)
			printf("%d ",path[i]);
	}
	return 0;
}