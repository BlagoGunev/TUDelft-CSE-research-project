#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
inline int sa(LL &x){return scanf("%lld",&x);}
inline void pu(LL x){printf("%lld",x);}
//typedef __int64 LL;
//inline int sa(LL &x){return scanf("%I64d",&x);}
//inline void pu(LL x){printf("%I64d",x);}
inline int sa(int &x){return scanf("%d",&x);}
inline int sa(char*s){return scanf("%s",s);}
inline int sa(double &x){return scanf("%lf",&x);}
inline void pu(char*s){printf("%s",s);}
inline void pu(int x){printf("%d",x);}
inline void pu(double x){printf("%g",x);}
template<class T>inline void pt(T x){putchar(' ');pu(x);}
template<class T>inline void puln(T x){pu(x);putchar('\n');}
template<class T,class V>inline int sa(T &x,V&y){sa(x);sa(y);}
#define iof ios::sync_with_stdio(false)
#define fi fflush(stdin)
#define fo fflush(stdout)
#define re(i,n) for(int i=1;i<=(n);i++)
#define re0(i,n) for(int i=0;i<(n);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define mem(a) memset(a,0,sizeof(a))
#define lowbit(i) (i&(-i))
#define fil(a,n) fill(a,a+n,0)
#define psh(x) push_back(x)
#define PI acos(-1.0)
const int inf=0x3f3f3f3f;
const int INF=0x7fffffff;
const int md=1e9 + 7;
const int maxn=750;
int cha[maxn][2],cha1[maxn][2];
char st[maxn];
int a[maxn], fly[maxn],as,n;
void init(){
    sa(st);
	n=strlen(st);
	rep0(i,0,n)a[i+1]=st[i]-'0';
	fly[0]=1;
	rep(i,1,n)fly[i]=10LL*fly[i-1]%md;
}
void add(int &x,int y){
	if((x+=y)>=md)x-=md;
}
void slove(){
    rep(u,0,8){
        mem(cha);
		cha[0][1]=1;
		rep(i,1,n){
		    mem(cha1);
		    rep0(j,0,i)rep(k,0,9){
                add(cha1[j + (k <= u)][0], cha[j][0]);
                if(k == a[i])add(cha1[j+(k<=u)][1],cha[j][1]);
                else if(k < a[i])add(cha1[j+(k<=u)][0],cha[j][1]);
				}
			memcpy(cha, cha1, sizeof cha);
		}
		int tmp=(cha[0][0]+cha[0][1])%md;
		rep(i,1,n){
			as=(as+(LL)tmp*fly[n-i])%md;
			tmp=(tmp+(LL)cha[i][0]+cha[i][1])%md;
		}
	}
}
int main() {
	init();
	slove();
	puln(as);
}