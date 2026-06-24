#include<bits/stdc++.h>
#define db double
#define ll long long
#define ev edge[i].v
#define pb push_back
#define INF 1000000007
#define Rep(i,l,r) for(int i=(l);i<=(r);++i)
#define RepD(i,r,l) for(int i=(r);i>=(l);--i)
#define RepG(i,x) for(int i=head[x];i;i=edge[i].next)
using namespace std;

const int N=6e5+5;

char s[N];
int a[N],sum[N],sz[N];
set<int>ss[3];
set<int>::iterator it;

int main(){
	int n,ans=0,l=1,r=1,mn=INF;
	scanf("%d",&n);
	scanf("%s",s+1);
	Rep(i,1,n) a[i]=a[i+n]=(s[i]=='('?1:-1);
	Rep(i,1,2*n) sum[i]=sum[i-1]+a[i];
	if(sum[n]!=0){puts("0"),puts("1 1");return 0;}
	Rep(i,1,n) mn=min(mn,sum[i]);
	Rep(i,1,n) ans+=(sum[i]==mn);
	RepD(i,2*n,1)
		if(sum[i]-mn<=2) ss[sum[i]-mn].insert(i),sz[i]=ss[sum[i]-mn].size();
	int last=ans,pos,res;
	RepD(i,n,1)
		if(a[i+1]==-1){
			it=ss[0].upper_bound(n+i),pos=*(--it);
			it=ss[1].upper_bound(n+i),res=sz[pos+1];
			if(it!=ss[1].end()) res-=sz[*it];
			if(res>ans) ans=res,l=i%n+1,r=pos%n+1;
			it=ss[1].upper_bound(n+i),pos=*(--it);
			if(pos!=i+n){
				it=ss[2].upper_bound(n+i),res=last+sz[pos+1];
				if(it!=ss[2].end()) res-=sz[*it];
				if(res>ans) ans=res,l=i%n+1,r=pos%n+1;
			}
		}
	printf("%d\n%d %d\n",ans,l,r);
	return 0;
}