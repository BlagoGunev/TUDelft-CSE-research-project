#include<bits/stdc++.h>
using namespace std;
template<typename T>
void rin(T &t)
{t=0;int k=1;char c=getchar();while(!isdigit(c)){if(c=='-')k=-1;c=getchar();}while(isdigit(c)){t=t*10+c-'0';c=getchar();}t*=k;}
typedef long long ll;
const int maxn=3e5+5;
int a[maxn],d[maxn];
int main()
{
	int n,k;
	rin(n);rin(k);
	ll sum=0;
	for(int i=1;i<=n;i++){rin(a[i]);}
	sum=a[n]-a[1];
	for(int i=1;i<=n;i++)d[i]=a[i]-a[i+1];
	sort(d+1,d+n);
	for(int i=1;i<k;i++)sum+=d[i];
	cout<<sum;
	return 0;
}