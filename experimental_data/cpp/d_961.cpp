#include<cstdio>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#define rg register
#define il inline
#define vd void
#define ll long long
#define maxn 100005
#define pa pair<int,int>
#define inf 1e17
#define pb push_back
#define fir first
#define sec second 
#define For(i,x,y) for (rg int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (rg int i=(x);i>=(y);i--)
#define cross(i,k) for (rg int i=first[k];i;i=last[i])
using namespace std;
il ll max(ll x,ll y){return x>y?x:y;}
il ll min(ll x,ll y){return x<y?x:y;}
il ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
il ll Get(pa a,pa b,pa c){return 1ll*(a.fir-c.fir)*(b.sec-c.sec)-1ll*(b.fir-c.fir)*(a.sec-c.sec);}
bool bj[maxn];
vector<pa> B;
int n;
pa a[maxn];
il bool Check(pa x,pa y){
	B.clear();memset(bj,0,sizeof bj);
	For(i,1,n) 
		if (Get(x,y,a[i])==0) bj[i]=true;
			else B.push_back(a[i]);
	if (B.size()<=2) return 1;
	for(int i=2;i<B.size();i++) if (Get(B[0],B[1],B[i])!=0) return 0;
	return 1;
}
int main(){
	n=read();
	For(i,1,n)
		a[i].fir=read(),a[i].sec=read();
	if (Check(a[1],a[2])||Check(a[1],a[3])||Check(a[2],a[3])) puts("YES"); 
		else puts("NO");
}