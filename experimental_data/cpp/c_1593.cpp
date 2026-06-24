#include<cstdio>
#include<algorithm>
#define int long long
const int Q=400005;
const int INF=(1<<30);
typedef long long ll;
#define rg register int
#define cint const register int
char Buf[1<<21],*p1=Buf,*p2=Buf;
#define gc() (p1==p2&&(p2=(p1=Buf)+fread(Buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline bool ig(char c){return c>=48&&c<=57;}
inline void read(int &oi){char c;int f=1,res=0;while(c=gc(),(!ig(c))&&c^'-');c^'-'?res=(c^48):f=-1;while(c=gc(),ig(c))res=res*10+(c^48);oi=f*res;}
inline void print(int oi){if(oi<0)putchar('-'),oi=~oi+1;if(oi>9)print(oi/10);putchar(oi%10+48);}
inline void write(int oi,char c){print(oi);putchar(c);}
int T,N,n,a[Q];
signed main(){
	read(T);for(;T--;){
		read(N);read(n);rg ans=0;
		for(rg i=1;i<=n;++i)read(a[i]);
		std::sort(a+1,a+1+n);rg pos=0;
		for(rg i=n;i>=1;--i){
			if(pos>=a[i])break;
			++ans;pos+=N-a[i];
		}
		write(ans,'\n');
	}
	return 0;
}