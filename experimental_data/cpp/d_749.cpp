#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=200010;
vector<int> c[N];
int q[N],x,y,k,val[N],n,m,id[N],a[N],b[N],ban[N],F,S;
bool cmp(int a,int b){return val[a]>val[b];}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	    scanf("%d%d",&x,&y);
	    val[x]=y;
	    c[x].push_back(y);
	}for(int i=1;i<=n;i++)q[i]=i;
	sort(q+1,q+n+1,cmp);
	scanf("%d",&m); 
	while(m--){
		F=S=0;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)scanf("%d",&b[i]),ban[b[i]]=1;
		for(int i=1;i<=n;i++){
			if(val[q[i]]==0)break;
			if(ban[q[i]])continue;
			if(F){S=q[i];break;}
			else F=q[i]; 
		}
		if(F==0)puts("0 0");
		else if(S==0)printf("%d %d\n",F,c[F][0]);
		else{
			int v=lower_bound(c[F].begin(),c[F].end(),val[S])-c[F].begin();
			printf("%d %d\n",F,c[F][v]);
		}
		for(int i=1;i<=k;i++)ban[b[i]]=0;
	}return 0;
}