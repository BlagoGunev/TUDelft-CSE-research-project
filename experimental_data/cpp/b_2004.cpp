#include<iostream>
#include<algorithm>
#include<vector> 
#include<cstring>
#include<unordered_map>
#include<map>
#include<set> 
#include<stack>
#include<cmath>
#include<queue>
#include<bitset> 
#define int long long
#define double long double
#define pii pair<int,int>
#define deb cout<<'.';
#define pc putchar 
using namespace std; 
const int N=1e2+10;
const int K=50+4; 
const int M=1e4+17;
const int P=50;
const int inf=1e9+10;
const int mod=998244353;
const int eps=1e-15;
int read()
{
	int s=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void print(int x)
{
	if(x<0) pc('-'),x=-x;
	if(x>=10) print(x/10);
	pc(x%10+'0');
}
int a[N],n;
void sol()
{
	int la=read(),ra=read(),lb=read(),rb=read();
	if(la>lb) swap(la,lb),swap(ra,rb);
	if(la==lb&&ra<rb) swap(ra,rb);
	if(ra<lb) print(1);
	else if(rb<=ra) print(rb-lb+(lb>la)+(rb<ra));
	else print(ra-lb+(lb>la)+(rb>ra));
	pc('\n');
}
signed main()
{
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int TT=read();
	while(TT--) sol();
	return 0;
}