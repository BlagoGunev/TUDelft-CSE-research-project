/**
 *　　　　　　  　　┏┓　　 　┏┓
 * 　　　　　  　　┏┛┗━━━━━━━┛┗━━━┓
 * 　　　　　  　　┃　　　　　　　┃ 　
 * 　　　　　  　　┃　　　━　　 　┃
 * 　　　　　  　　┃　＞　　　＜　┃
 * 　　　　　  　　┃　　　　　　　┃
 * 　　　　　  　　┃...　⌒　... 　┃
 * 　　　　　　  　┃              ┃
 * 　　　　　　  　┗━┓          ┏━┛
 * 　　　　　　　　　┃          ┃　Code is far away from bug with the animal protecting　　　　　　　　　　
 * 　　　　　　　　　┃          ┃   神兽保佑,代码无bug
 * 　　　　　　　　　┃          ┃　　　　　　　　　　　
 * 　　　　　　　　　┃          ┃  　　　　　　
 * 　　　　　　　　　┃          ┃
 * 　　　　　　　　　┃          ┃　　　　　　　　　　　
 * 　　　　　　　　　┃          ┗━━━┓
 * 　　　　　　　　　┃              ┣┓
 * 　　　　　　　　　┃              ┏┛
 * 　　　　　　　　　┗┓┓┏━━━━━━━━┳┓┏┛
 * 　　　　　　　　　　┃┫┫       ┃┫┫
 * 　　　　　　　　　　┗┻┛       ┗┻┛
 */ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<set>
#include<bitset>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge *j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long
#define eps 1e-6
#define succ(x) (1<<x)
#define lowbit(x) (x&(-x))
#define sqr(x) ((x)*(x))
#define mid (x+y)/2
#define NM 1100005
#define nm 32768
#define pi 3.1415926535897931
const ll inf=1e18;
using namespace std;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f*x;
}






int n,a[NM],b[NM][2];
ll s;

int main(){
    n=read();inc(i,1,n)a[i]=read();
    inc(i,1,n)a[i]^=a[i-1];
    b[0][0]=1;
    inc(i,1,n){
	s+=b[a[i]][i%2];
	b[a[i]][i%2]++;
    }
    return 0*printf("%lld\n",s);
}