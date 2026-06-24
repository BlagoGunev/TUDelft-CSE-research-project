// Problem: A. Minimal Coprime
// Contest: Codeforces - Codeforces Round 1000 (Div. 2)
// URL: https://codeforces.com/contest/2063/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// This Code is written By Anas_Da
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define cy cout<<"YES\n";
#define cn cout<<"NO\n";
#define c1 cout<<"-1\n";
#define all(x) x.begin(),x.end()
#define re(x) x.rbegin(),x.rend()
#define F first
#define S second
#define ii pair<ll,ll>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll x,n,m,k;
string s;
vector<ll>vec;
set<ll>st;
map<ll,ll>mp;
ll arr[200200];
ll GCD(ll x,ll y)   {   return y ? GCD(y,x%y) : x ;   }
void _clear(){
	
}
void solve(int tc){
	cin>>n>>m;
	if(m==1){
		cout<<1<<'\n';
		return;
	}
	cout<<m-n<<'\n';
}
int main()
{
    IOS
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
       _clear();
       solve(i);
    }
}