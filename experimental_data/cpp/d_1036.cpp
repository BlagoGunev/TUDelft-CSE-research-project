#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=3e5+10;
int n,m,i,j,a[N],b[N];
ll A,B,res;
int main(){
	read(n);
	for (i=1;i<=n;i++) read(a[i]),A+=a[i];
	read(m);
	for (i=1;i<=m;i++) read(b[i]),B+=b[i];
	if (A!=B) puts("-1");
	else{
		A=a[1],B=b[1];
		for (i=2,j=2;i<=n&&j<=m;){
			if (A<B){
				if (i==n+1) return puts("-1"),0;
				A+=a[i];
				i++;
			}
			else if (A>B){
				if (j==m+1) return puts("-1"),0;
				B+=b[j];
				j++;
			}
			else{
				res++;
				A=a[i];
				B=b[j];
				i++,j++;
			}
		}
		res++;
		cout<<res<<endl;
	}
	return 0;
}