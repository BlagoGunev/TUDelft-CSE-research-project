#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long 
#define endl '\n'
#define pb push_back
#define mp make_pair
#define freopen freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll powerFunc(ll n , ll k){
    ll mod = 1000000000 + 7;
    n%=mod;
    k%=mod;
    ll temp = n;
    ll result = 0;
    if(k&1) 
    result=1;
    
    k>>=1;
    
    while(k > 0) {
        if(k&1){
            result += (n%mod);
        }
        
        n = (n*temp)%mod;
        k>>=1;
    }
    return result%mod;
}


void solution() {
	ll n, k;
	cin>>n>>k;
	cout<<powerFunc(n,k)<<endl;
	return ;
}

int main() {
	fast
	int t = 1;
	cin>>t;
	while(t--)
	solution();
}