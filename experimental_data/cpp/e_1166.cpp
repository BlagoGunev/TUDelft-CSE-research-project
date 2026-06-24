#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e4+10;
int m,n,k,x,i,j,num[55][N];
int main(){
	read(m),read(n);
	for (i=1;i<=m;++i){
		read(k);
		for (j=1;j<=k;++j){
			read(x);
			num[i][x]=1;
		}
	}
	// cout<<50*50*(N-10)<<endl;
	for (i=1;i<=m;++i){
		for (j=i+1;j<=m;++j){
			bool flag=0;
			for (k=1;k<=n;++k)if(num[j][k]){
				if (num[i][k]){
					flag=1;
					break;
				}
			}
			if (!flag) return puts("impossible"),0;
		}
	}
	puts("possible");
	return 0;
}