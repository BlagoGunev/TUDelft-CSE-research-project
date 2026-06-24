// Problem: C. Prepend and Append

// Contest: Codeforces - Codeforces Round #849 (Div. 4)

// URL: https://codeforces.com/problemset/problem/1791/C

// Memory Limit: 256 MB

// Time Limit: 1000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(),v.end()

#define ha "YES"

#define na "NO"

#define fo(i,a,b) for(int i=a;i<b;i++)

#define arrin int n;cin>>n;vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];

#define sumarr int sum=0;for(int i=0;i<n;i++)sum+=a[i];

#define forloop for(int i=0;i<n;i++)

#define allr(v) (v).rbegin(),(v).rend()

#define vi vector <int>

#define set_bits __builtin_popcountll

#define mp map<int,int>

#define pb push_back

#define po pop_back

#define int long long

#define endl "\n"

#define F first

#define S second

#define mod 1e9 + 7

#define inf 1e15

signed main() {

ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;

    cin>>t;

    while(t--){

    int n;

    cin>>n;

    string s; cin>>s;

    int i=0,j=n-1;

    while(i<j){

    	if(s[i]=='0' and s[j]=='1'){

    		i++;

    		j--;

    	}

    	else if(s[i]=='1' and s[j]=='0'){

    		i++;

    		j--;

    	}

    	else break;

    }

    cout<<j-i+1;

   

    cout<<endl;

}

return 0;    

}