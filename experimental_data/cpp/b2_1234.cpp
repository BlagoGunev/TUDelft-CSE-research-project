#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int ans=0;
	char a=getchar();
	while(a<'0'||a>'9'){
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		ans=ans*10+a-'0';
		a=getchar();
	}
	return ans;
}
struct node{
	int num,k;
	int s;
}id[200005];
int n,k;
struct node que[200005];
bool book[200005];
bool cmp(node x,node y){
	return x.num<y.num;
}
bool cmp1(node x,node y){
	return x.k<y.k;
}
int main(){
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		id[i].num=read();
		id[i].k=i;
	}
	sort(id+1,id+n+1,cmp);
	id[0].num=-1;
	int now=0;
	for(int i=1;i<=n;i++){
		if(id[i].num!=id[i-1].num){
			now++;
		}
		id[i].s=now;
	}
	sort(id+1,id+n+1,cmp1);
	int head=1,tail=1;
	que[head]=id[1];
	book[id[1].s]=1;
	for(int i=2;i<=n;i++){
		if(book[id[i].s]==0){
			book[id[i].s]=1;
			que[++tail]=id[i];
			if(tail-head+1>k){
				book[que[head].s]=0;
				head++;
			}
		}
	}
	printf("%d\n",tail-head+1);
	for(int i=tail;i>=head;i--){
		printf("%d ",que[i].num);
	}
	return 0;
}