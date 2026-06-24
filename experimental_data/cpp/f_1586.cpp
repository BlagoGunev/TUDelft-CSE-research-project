#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define N 2005
#define inf 1047483647
#define LL long long
using namespace std;
int n,m,tot,ans,T,l[N],r[N],b[N][N];
inline void solve(int x){
	ans++,tot=0;for(register int i=1;i<=x;i+=m){
		for(register int j=0;j^m;j++)
		for(register int k=j+1;k<m&&i+k<=x;k++)
		for(register int p=l[i+j];p<=r[i+j];p++)
		for(register int q=l[i+k];q<=r[i+k];q++)
		b[p][q]=ans,T++;l[++tot]=l[i],r[tot]=r[min(x,i+m-1)];
	}
	if(tot==1) return;solve(tot);
}
struct FastIO{
	static const int S=1048576;
	char buf[S],*L,*R;int stk[20],Top;~FastIO(){clear();}
	inline char nc(){return L==R&&(R=(L=buf)+fread(buf,1,S,stdin),L==R)?EOF:*L++;}inline void clear(){fwrite(buf,1,Top,stdout);Top=0;}
	inline void pc(char ch){Top==S&&(clear(),0);buf[Top++]=ch;}inline void endl(){pc('\n');}
	FastIO& operator >> (char&ch){while(ch=nc(),ch==' '||ch=='\n');return *this;}
	template<typename T>FastIO& operator >> (T&ret){
		ret=0;int f=1;char ch=nc();while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=nc();}
		while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=nc();}ret*=f;return *this;
	}
	FastIO& operator >> (char* s){int Len=0;char ch=nc();while(ch!='\n'){*(s+Len)=ch;Len++;ch=nc();}}
	template<typename T>FastIO& operator << (T x){
		if(x<0){pc('-');x=-x;}do{stk[++stk[0]]=x%10;x/=10;}while(x);
		while(stk[0]) pc('0'+stk[stk[0]--]);return *this;
	}
	FastIO& operator << (char ch){pc(ch);return *this;}
	FastIO& operator << (string str){int Len=str.size()-1;for(stk[0]=0;Len>=0;Len--) stk[++stk[0]]=str[Len];while(stk[0]) pc(stk[stk[0]--]);return *this;}
}fin,fout;
int main(){
//	freopen("data.in","r",stdin);//freopen("jxc.out","w",stdout);
	cin>>n>>m;for(register int i=1;i<=n;i++) l[i]=r[i]=i;solve(n);fout<<ans<<'\n';for(register int i=1;i<=n;i++) for(register int j=i+1;j<=n;j++) fout<<b[i][j]<<' ';return 0;
}