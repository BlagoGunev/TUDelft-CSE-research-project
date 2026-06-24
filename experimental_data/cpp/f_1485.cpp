#include <bits/stdc++.h>

#define int long long

//aaa

#define pai 3.141592653589793238462643383279502884197169399375105820

#define MOD 1000000007

#define eps 0.00000001

inline int min(int a,int b) {return a<b?a:b;}

inline int max(int a,int b) {return a>b?a:b;}

#define ULL unsigned long long

#define LL long long

#define INF 0x3f3f3f3f

#define INF_LL 0x3f3f3f3f3f3f3f3f

static char buf[1000000],*paa=buf,*pd=buf;

static char buf2[1000000],*pp=buf2;

#define getchar() paa==pd&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++

inline void pc(char ch){

	if(pp-buf2==1000000) fwrite(buf2,1,1000000,stdout),pp=buf2;

	*pp++=ch;

}

inline void pcc(){

	fwrite(buf2,1,pp-buf2,stdout);

	pp=buf2;

}

inline int read(void) {

	int w=1;

	register int x(0);register char c(getchar());

	while(c<'0'||c>'9') {if(c=='-') w=-1;c=getchar();}

	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();

	return w*x;

}

void write(int x) {

	static int sta[20];

	int top=0;

	do {

		sta[top++]=x%10,x/=10;

	} while(x);

	while(top) pc(sta[--top]+48);

}

void we(int x) {

	write(x);

	pc('\n');

}

inline bool cmp_xi(int a,int b) {return a<b;}

inline bool cmp_da(int a,int b) {return a>b;}

std::map<int,int> s;

int T,N,b,su,fk=1; 

signed main(void) {

    //freopen("m.in","r",stdin);

    //freopen("m.out","w",stdout);

    T=read();

    while(T--) {

    	s.clear();su=0;fk=1;

		s[0]=1;

    	N=read(); 

		for(int i=1;i<=N;i++) {

			b=read();

			su+=b;

			int v=fk-s[b-su]; 

			s[b-su]=fk;

			fk+=v;

			fk%=MOD;

			s[b-su]%=MOD;

			fk%=MOD; 

		}

		printf("%lld\n",(fk+MOD)%MOD);

	}

    return 0;

}