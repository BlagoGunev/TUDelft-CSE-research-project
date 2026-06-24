#include<bits/stdc++.h>
#define N 50009
using namespace std;
typedef long long ll;
int n;
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
struct node{
	int a[5];
};
inline bool cmp(node a,node b){
	int cnt=0;
	for(int i=0;i<5;++i){
		if(a.a[i]<b.a[i])cnt++;
	}
	if(cnt>=3)return 1;
	return 0;
}
node a[N];
int main(){
	int T=rd();
	while(T--){
		n=rd();
		for(int i=1;i<=n;++i){
			for(int j=0;j<5;++j)
			   a[i].a[j]=rd();
		}
		int win=1;
		bool tag=0;
		for(int i=2;i<=n;++i)
		   if(cmp(a[i],a[win]))win=i;
		for(int i=1;i<=n;++i){
			if(win!=i&&!cmp(a[win],a[i]))tag=1;
		}
		if(!tag)printf("%d\n",win);
		else puts("-1");
	}
	return 0;
}