#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
namespace io{
    #define ll long long
    #define inf 0x3f3f3f3f
    #define il inline 
    #define in1(a) read(a)
    #define in2(a,b) in1(a),in1(b)
    #define in3(a,b,c) in2(a,b),in1(c)
    #define in4(a,b,c,d) in2(a,b),in2(c,d)
    il void readl(ll &x){
        x=0;ll f=1;char c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
        x*=f;
    }
    il void read(int &x){
        x=0;int f=1;char c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
        x*=f;
    }
}using namespace io;
#define N 100005
int n,m,k;
int a[N],c[N];
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	int ans=0;
	in3(n,m,k);
	for(int i=1;i<=n;i++) read(a[i]);
	ans+=a[n]-a[1]+1;
	for(int i=2;i<=n;i++){
		c[i-1]=a[i]-a[i-1];
	}
	sort(c+1,c+n,cmp);
	for(int i=1;i<=k-1;i++){
		ans=ans-c[i]+1;
	}
	printf("%d\n",ans);
	return 0;
}