#include<bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;

inline ll read(){
	ll num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

struct node{
	int t,key;
}pro[200010];

bool cmp1(node x,node y){return x.t<y.t;}
int T,n,lmt,a,b,sum,ans;
int cnt[200010];

signed main(){
	T=read();
	while(T--)
	{
		n=read(),lmt=read(),a=read(),b=read();
		for(int i=1;i<=n;i++) pro[i].key=read();
		for(int i=1;i<=n;i++) pro[i].t=read();
		sort(pro+1,pro+n+1,cmp1);ans=sum=0;
		pro[n+1].t=lmt+1;cnt[n+1]=0;
		for(int i=n;i>=1;i--) cnt[i]=cnt[i+1]+(pro[i].key==0?1:0);
		
		
		for(int i=1;i<=n+1;i++){
			if(pro[i].t!=pro[i-1].t){
				if(sum<=pro[i].t-1){
					int res=pro[i].t-1-sum;
					if(cnt[i]*a<=res){
						int tmp=n-i+1-cnt[i];
						res-=cnt[i]*a;
						ans=max(ans,cnt[i]+i-1+min(res/b,tmp));
					}
					else ans=max(ans,res/a+i-1);
				}

				sum+=(pro[i].key?b:a);
			}
			else sum+=(pro[i].key?b:a);
			if(pro[i].t>lmt)break;
		}
		cout<<ans<<endl;
	}return 0;
}