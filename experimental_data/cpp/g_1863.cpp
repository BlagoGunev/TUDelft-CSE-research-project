// LUOGU_RID: 156730407
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+10,mod=1e9+7;
inline int Add(const int &a,const int &b){
	return a+b>=mod?a+b-mod:a+b;
}
inline int Del(const int &a,const int &b){
	return a-b<0?a-b+mod:a-b;
}
inline int Mul(const int &a,const int &b){
	return 1ll*a*b%mod;
}
int qmi(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=Mul(ans,a);
		a=Mul(a,a);
		b/=2;
	}
	return ans;
}
int n,a[N],ans=1,cnt[N];
bool vis[N];
vector<int>tmp;
int main()
{
    // freopen("1.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++)
        ans=Mul(ans,cnt[i]+1);
    for(int i=1;i<=n;i++)
    if(!vis[i])
    {
        tmp.clear();
        bool flag=0;
        int x=i,res1=1,res2=0;
        while(!vis[x]){
            tmp.push_back(x);vis[x]=1;
            x=a[x];
        }
        for(int y:tmp){
            if(x==y)
                flag=1;
            if(flag){
                res1=Mul(res1,cnt[y]+1);
                res2=Add(res2,cnt[y]);
            }
        }
        if(flag)
        ans=Mul(Mul(ans,qmi(res1,mod-2)),Del(res1,res2));
    }
    cout<<ans;
    return 0;
}