#include<bits/stdc++.h>
#define I64 "%I64d"
#define RAN(v)v.begin(),v.end()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
template<class T>
inline void upd1(T&a,T b){a>b?a=b:0;}
template<class T>
inline void upd2(T&a,T b){a<b?a=b:0;}
struct ano{
	operator ll(){
		ll x=0,y=0,c=getchar();
		while(c<48)
			y=c==45,c=getchar();
		while(c>47)
			x=x*10+c-48,c=getchar();
		return y?-x:x;
	}
}buf;
const int N=2e5+5;
int a[N];
vector<int>t[N];
int main(){
	int n=buf;
	for(int i=0;i<n;++i){
		int x=buf,j=ub(a,a+n,x,greater<int>())-a;
		a[j]=x;
		t[j].pb(x);
	}
	for(int i=0;a[i];++i){
		for(int e:t[i])
			printf("%d ",e);
		puts("");
	}
}