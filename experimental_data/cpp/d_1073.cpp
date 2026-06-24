#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define per(i,x,y) for (int i=(x);i>=(y);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define y1 ___y1
using namespace std;
char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
ll read(){
	char ch=gc();ll x=0;int op=1;
	for (;!isdigit(ch);ch=gc()) if (ch=='-') op=-1;
	for (;isdigit(ch);ch=gc()) x=(x<<1)+(x<<3)+ch-'0';
	return x*op;
}
const int N=2e5+5;
ll n,T,a[N],sum,ans,pre[N],nxt[N],cnt;
int main(){
	n=read(),T=read();
	rep (i,1,n) a[i]=read(),sum+=a[i];
	ans+=T/sum*n; T%=sum;
	rep (i,1,n) pre[i]=i-1,nxt[i]=i+1;
	pre[1]=n; nxt[n]=1; cnt=n;
	for (int i=1;cnt;i=nxt[i]){
		if (T>=a[i]) T-=a[i],ans++;
		else{
			nxt[pre[i]]=nxt[i],pre[nxt[i]]=pre[i],cnt--;
			sum-=a[i];
			if (sum&&T>=sum) ans+=T/sum*cnt,T%=sum;
		}
	}
	cout<<ans;
	return 0;
}