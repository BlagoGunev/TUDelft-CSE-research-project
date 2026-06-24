#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=200005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int n;
struct bit{
	int64 sum[maxn];
	#define lowbit(x) (x&-x)
	inline void add(int x,int64 v){
		while(x<=n){
			sum[x]+=v;x+=lowbit(x);
		}
	}
	inline int64 query(int x){
		int64 res=0;
		while(x){
			res+=sum[x];x-=lowbit(x);
		}return res;
	}
}tree1,tree2;
int v[maxn],k,a,b,q;
int main(){
    read(n);read(k);read(a);read(b);read(q);
    rep(i,1,q){
    	int op;
    	read(op);
    	if(op==1){
    		int d,aa;read(d);read(aa);
    		tree1.add(d,max(min(aa,b-v[d]),0));
    		tree2.add(d,max(min(aa,a-v[d]),0));
    		v[d]+=aa;
    	}
    	if(op==2){
    		int p;read(p);
    		int64 ans=tree1.query(p-1)+tree2.query(n)-tree2.query(p+k-1);
    		printf("%I64d\n",ans);
    	}
    }
    return 0;
}