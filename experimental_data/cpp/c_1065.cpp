#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define Stdio
#ifdef Stdio
#define Open_file(F)
#ifdef ONLINE_JUDGE
char _B[1<<15],*_S=_B,*_T=_B,_U[1<<15|1],*_O=_U,*_W=_U+(1<<15);
bool END=0;
#define getc() (_S==_T&&(_T=(_S=_B)+fread(_B,1,1<<15,stdin),_S==_T)?END=1:*_S++)
#define putc(c) (_O==_W?fwrite(_U,1,1<<15,stdout),_O=_U,1:1,*_O++=c)
#define EXIT fwrite(_U,1,_O-_U,stdout);\
	return 0
#else
#define getc() getchar()
#define putc(x) putchar(x)
#define EXIT return 0
#endif
#else
#define Open_file(F) freopen(F".in","r",stdin);\
	freopen(F".out","w",stdout)
char _B[1<<15],*_S=_B,*_T=_B,_U[1<<15|1],*_O=_U,*_W=_U+(1<<15);
bool END=0;
#define getc() (_S==_T&&(_T=(_S=_B)+fread(_B,1,1<<15,stdin),_S==_T)?END=1:*_S++)
#define putc(c) (_O==_W?fwrite(_U,1,1<<15,stdout),_O=_U,1:1,*_O++=c)
#define EXIT fwrite(_U,1,_O-_U,stdout);\
	return 0
#endif
#define I_inF 2*(233333333LL+666666666LL)
#define UI_inF 4*(233333333LL+666666666LL)
#define LL_inF (2333333333333333333LL+6666666666666666666LL)
#define ULL_inF 2*(2333333333333333333ULL+6666666666666666666ULL)
#define R register
#define D long long
#define RD R D
#define For(a,b,c) for(RD a=b;a<=c;++a)
#define foR(a,b,c) for(RD a=b;a>=c;--a)
#define Mset(a,b) memset(a,b,sizeof(a))
inline D read() {
#define isd(c) (c>='0'&&c<='9')
	RD aa,bb;
	R char ch;
	while(ch=getc(),!isd(ch)&&ch!='-');
	ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
	while(ch=getc(),isd(ch)) aa=(aa*10+ch-'0');
	return bb?aa:-aa;
}
inline void out(RD x,RD k=0) {
	if(x<0) putc('-'),x=-x;
	if(!x) putc('0');
	else {
		R char stk[20];
		RD ts;
		for(ts=0; x; x/=10) stk[++ts]=x%10+'0';
		for(; ts; putc(stk[ts--]));
	}
	if(k==1) putc(' ');
	if(k==2) putc('\n');
}
D h[200010];
int main() {
	RD n=read(),k=read(),max=0,cnt=0,tot=0,ans=0;
	For(i,1,n) {
		RD t=read();
		++h[t],max=std::max(max,t);
	}
	foR(i,200000,1) {
		cnt+=tot+=h[i];
		if(tot==n) {
			ans+=(cnt!=h[i]);
			break;
		}
		if(cnt>k) ++ans,cnt=tot;
	}
	out(ans);
	EXIT;
}