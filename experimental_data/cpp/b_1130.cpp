#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long LL;
const int maxn=1e5+5;

LL a[maxn],b[maxn],book[maxn];
LL n,ans=0;

inline LL read(){
	LL sum=0,fl=1,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) sum=(sum<<3)+(sum<<1)+ch-'0';
	return sum*fl;
}

int main(){
	n=read();
	for(int i=1;i<=(n<<1);i++){
		int x=read();
		if(book[x]){
			b[x]=i;
		}else{
			a[x]=i;
			book[x]=1;
		}
	}
	a[0]=1;
	b[0]=1;
	for(int i=1;i<=n;i++){
		ans+=abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
	}
	printf("%I64d\n",ans);
	return 0;
}