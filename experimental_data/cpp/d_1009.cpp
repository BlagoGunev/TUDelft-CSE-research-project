#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <climits>
#include <set>
#include <vector>
#include <complex>
#define fi first
#define se second
#define mkp make_pair
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
inline void writeln(int x){
	write(x);puts("");
}
const int N=100010;
int n,m;
vector<pair<int,int> >e;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	n=read();m=read();
	if(m<n-1)return puts("Impossible")&0;
	if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)if(gcd(i,j)==1){
				e.push_back(mkp(i,j));
				m--;if(!m)break;
			}
			if(!m)break;
		}
		if(m==0){
			puts("Possible");
			for(int i=0;i<e.size();i++)
				write(e[i].fi),putchar(' '),writeln(e[i].se);
		}else puts("Impossible");
	}else{
		for(int i=2;i<=n;i++){
			e.push_back(mkp(1,i));
			m--;if(!m)break;
		}
		if(m){
			for(int i=2;i<=1000;i++){
				for(int j=i+1;j<=1000;j++)if(gcd(i,j)==1){
					e.push_back(mkp(i,j));
					m--;if(!m)break;
				}
				if(!m)break;
			}
		}
		puts("Possible");
		for(int i=0;i<e.size();i++)
			write(e[i].fi),putchar(' '),writeln(e[i].se);
	}
	return 0;
}