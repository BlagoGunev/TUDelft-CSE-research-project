#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
char c;
bool flag;
#define ll long long
const
	ll Mod=(int)1e9+7;

inline void read(ll&a)
{a=0;do c=getchar();while((c<'0'||c>'9')&&c!='-');c=c=='-'?flag=true,getchar():c;while(c<='9'&&c>='0')a=(a<<3)+(a<<1)+c-'0',c=getchar();a=flag?flag=false,-a:a;}
inline ll Max(ll&a,ll b){return a>b?a:a=b;}
inline ll Min(ll&a,ll b){return a<b?a:a=b;}
inline ll min(ll a,ll b){return a<b?a:b;}
inline ll max(ll a,ll b){return a>b?a:b;}
inline ll abs(ll a){return a>0?a:-a;}

ll Div(ll x,ll y)
{
	if(y==0)return 1;
	ll t=Div(x,y>>1);
	return y&1?((t*1ll*t)%Mod*x)%Mod:(t*1ll*t)%Mod;
}

int main()
{
	//freopen("self.in","r",stdin);
	//freopen("self.out","w",stdout);
	ll D3=Div(3,Mod-2);
	ll C1=1,C2=1;
	ll k;
	read(k);
	while(k--)
	{
		ll t1;
		read(t1);
		t1%=Mod-1;
		C1=C1*1ll*t1%(Mod-1);
	}
	C2=C1!=0?C1-1:Mod-2;
	ll T1=(((Div(2,C2)-Div(-1,C2))*1ll*D3%Mod)+Mod)%Mod,T2=(((Div(2,C1)-Div(-1,C1))*1ll*D3%Mod)+Mod)%Mod;
	cout<<T1<<'/'<<(T2+T1)%Mod<<endl;
	return 0;
}