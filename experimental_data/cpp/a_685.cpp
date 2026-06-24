#include<cstdio>

#include<algorithm>

using namespace std;



typedef long long LL;



int n,m,l1,l2,ans;

bool used[7];



int len(int n){int ret=0;for(;n;n/=7)ret++;return max(1,ret);}



void dfs(int dep,LL p,LL q){

	if(p>=n||q>=m)return;

	if(dep==l1+l2)return ans++,(void)0;

	for(int i=0;i<7;i++)if(!used[i]){

		int np=p,nq=q;

		used[i]=1;

		if(dep<l1)np=p*7+i;

		else nq=q*7+i;

		dfs(dep+1,np,nq);

		used[i]=0;

	}

}



int main(){

	scanf("%d%d",&n,&m);

	l1=len(n-1),l2=len(m-1);

	if(l1+l2>7)return puts("0"),0;

	dfs(0,0,0);

	return printf("%d\n",ans),0;

}