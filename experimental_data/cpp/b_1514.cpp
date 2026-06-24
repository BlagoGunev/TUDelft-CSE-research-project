// Problem: B. AND 0, Sum Big

// URL: https://codeforces.com/problemset/problem/1514/B

// I can surely make it in time



#include<bits/stdc++.h>

using namespace std ;

#define codestein ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define fr(i,k,n) for(int i=k;i<n;i++)

#define test int _t;cin>>_t;fr(_i,0,_t)

#define vip vector<pair<int,int>>

#define be(v) v.begin(),v.end()

#define sz(s) (int)s.size()

#define mci map<char,int>

#define mii map<int,int>

#define pb emplace_back

#define vi vector<int>

#define nl cout<<"\n"

#define int long long



int mod = 1000000007;



signed main()

{

	codestein;

	test{

   		int n,k,flag=0;

   		cin>>n>>k;

   		int ans = 1;

   		fr(i,0,k){

   			ans=(ans*n)%mod;

   		}

   		cout<<ans;

   		

   		nl;

  	}

return 0;

}