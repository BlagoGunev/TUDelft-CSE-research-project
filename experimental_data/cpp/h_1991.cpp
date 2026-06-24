/* by me */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+3;
bool vis[N];
bitset<N>win,lose,good,nb;
void Init()
{
	vis[1]=1;win[4]=1;
	for(int i=2;i<N;i++)for(int j=i+i;j<N;j+=i)vis[j]=1;
    for(int i=3;i<N;i+=2)
    {
        int x=0,j=i;
        while(!vis[j-2])x++,j-=2;
		win[i]=x%2;lose[i]=!vis[i]&&!win[i];
	}
    for(int i=3;i<N;i+=2)if(lose[i])win|=lose<<i;
    for(int i=1;i<N;i++)if(!vis[i])nb[i]=win[i];
    for(int i=1;i<N;i+=2)if(nb[i])good|=nb<<i;
}
void Solve()
{
	int n,sx=0,sy=0;cin>>n;
	for(int i=1,x;i<=n;i++)cin>>x,sx+=win[x],sy+=good[x];
	if(sx<=n-n%2)puts(sx?"Alice":"Bob");
	else puts(sy&&sy<n?"Alice":"Bob");
}
int main()
{
	int T;cin>>T;Init();
	while(T--)Solve();
	return 0;
}