#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000010,p=1000000007;
void dfs(int);
int f[maxn],ans=0;
int n,k,a[maxn],root,lc[maxn]={0},rc[maxn]={0},s[maxn],top=0,L[maxn],R[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,j=0;i<=n;i++){
		while(1+j*(k-1)<=i)j++;
		f[i]=(f[i-1]+j-1)%p;
		//printf("f[%d]=%lld\n",i,f[i]);
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	s[++top]=root=1;
	for(int i=2;i<=n;i++){
		s[top+1]=0;
		while(top&&a[i]>a[s[top]])top--;
		if(top)rc[s[top]]=i;
		else root=i;
		lc[i]=s[top+1];
		s[++top]=i;
	}
	dfs(root);
	if(ans<0)ans+=p;
	printf("%d\n",ans);
	return 0;
}
void dfs(int x){
	if(lc[x]){
		dfs(lc[x]);
		L[x]=L[lc[x]];
	}
	else L[x]=x;
	if(rc[x]){
		dfs(rc[x]);
		R[x]=R[rc[x]];
	}
	else R[x]=x;
	//printf("x=%d L=%d R=%d\n",x,L[x],R[x]);
	int n=R[x]-L[x]+1,l=x-L[x],r=R[x]-x;
	ans=(ans+(long long)a[x]*(f[n]-f[l]-f[r]))%p;
	//printf("cnt=%lld\n",f[n]-f[l]-f[r]);
}