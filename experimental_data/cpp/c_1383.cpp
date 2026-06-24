// LUOGU_RID: 93083202
#include<bits/stdc++.h>

#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

#define mod 1000000007

#define ll long long

#define N 300005

using namespace std;

template<class T>void read(T&x) {

	T f=1;x=0;char c=getchar();

	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}

	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}

	x*=f;

}

template<class T>void write(T x) {

	if(x<0)putchar('-'),x=-x;int s[20],top=0;

	while(s[++top]=x%10,x/=10);

	while(top)putchar(s[top--]+'0');putchar(' ');

}

template<class T,class...Ts>void write(T arg,Ts...args){write(arg);write(args...);}

template<class...Ts>void print(Ts...args){write(args...);putchar('\n');}

void cer(){cerr << '\n';}

template<class T,class...Ts>void cer(T arg,Ts...args){cerr << arg << ' ';cer(args...);}

namespace MAIN {

char _st;

int T,n,e[20],f[1<<20],fa[20];

char s[N],t[N];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

char _ed;

int main() {

	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';

	read(T);

	while(T--) {

		read(n);scanf("%s",s+1);scanf("%s",t+1);

		for(int i=0; i<20; ++i)e[i] = 0,fa[i] = i;

		int c = 20;

		for(int i=1; i<=n; ++i) {

			int x = s[i]-'a',y = t[i]-'a';

			e[x] |= 1<<y;

			if(find(x) != find(y))c--,fa[find(x)] = find(y);

		}

		int ans = 2*20-c,mx = 0;memset(f,0,sizeof(f));f[0] = 1;

		for(int s=0; s<1<<20; ++s)if(f[s]) {

			mx = max(mx,__builtin_popcount(s));

			for(int i=0; i<20; ++i)if(!(s>>i&1) && (e[i]&s) == 0)f[s^(1<<i)] = 1;

		}

		print(ans-mx);

	}

	return 0;

}

}

int main(){MAIN::main();}