#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,k,n) for(int i=k; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it=a.begin(); it!=a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int t,snp1,vnp1,jnp1;
int str1,str2;
int cst = 0;
int mn1,mn2;

void take_inp(){
    cin>>t>>snp1>>vnp1>>jnp1;
	cin>>str1>>str2;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    take_inp();
	if(str2>=str1) {
	    mn2 = min(min(snp1,vnp1),jnp1);
		jnp1-=mn2;
		mn1 = min(jnp1,t);
		cst = mn1*str1 + mn2*str2;
	}  else {
		mn1 = min(jnp1,t);
		jnp1-=mn1;
		mn2 = min(min(snp1,vnp1),jnp1);
		jnp1-=mn2;
		cst = mn1*str1 + mn2*str2;
	}
	cout<<cst<<endl;
	return 0;
}