#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;
typedef vector<long long> vll;
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define mp make_pair
#define Mid ((left+right)/2)
#define flash ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
int main()
{
   flash;
   ll n,m,a,b;
   cin>>n>>m>>a>>b;
   
    ll r=n%m;
   if(r==0){
   	cout<<0<<endl;
   	return 0;
   }
   ll n1=r*b;
   ll x=n/m;
   
   ll n2=(x+1)*m-n;
   n2=n2*a;
   //cout<<"n1 "<<n1<<"n2 "<<n2<<endl;
   ll ans=min(n1,n2);
   cout<<ans<<endl;
   
}