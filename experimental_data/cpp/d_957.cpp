//      3/25
#include<bits/stdc++.h>
#define ll long long
bool Fin;
using namespace std;
#define maxx(a,b) ((a)>(b)?(a):(b))
#define minn(a,b) ((a)<(b)?(a):(b))
#define abss(a) ((a)>0?(a):(a)*(-1))
template<class T>inline void read(T &x){Fin=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Fin=1;}
//?????????????defines ????????????? 
const int N=100005;
ll n,q,a[N],h[N];
ll ans;

int main() {
 cin >> n;
 for(int i=1;i<=n;i++)read(a[i]);
 for(int i=n;i>=1;i--)h[i]=maxx(a[i]+1,h[i+1]-1);
 for(int i=1;i<=n;i++){q=maxx(q,h[i]);ans+=q-a[i]-1;}
 cout<<ans; 
}