#include <bits/stdc++.h>

using namespace std;

#define Baytoro_Mayrambekov void solve()

#define ios ios::sync_with_stdio(false); cin.tie(NULL);

#define pb push_back

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

#define fr first

#define sc second

#define int long long

#define endl '\n'

const int INF=1e18;

void fopn(string name){

	freopen((name+".in").c_str(),"r",stdin);

	freopen((name+".out").c_str(),"w",stdout);

}

int binpow(int a,int n){

	if(n==0)

		return 1;

	if(n%2==1)

		return binpow(a, n-1)*a;

	else{

		int b=binpow(a, n/2);

		return b*b;

	}

}

int a,b,c,n,m,q,i,j,k,x,y,cnt=0,sum=0,res=0;

Baytoro_Mayrambekov{

	cin>>n>>q;

	string s;

	cin>>s;

	vector<int> pref(n+1);

	for(i=0;i<n;i++){

		pref[i+1]=pref[i]+(s[i]-'a'+1);

	}

	while(q--){

		int l,r;

		cin>>l>>r;

		cout<<pref[r]-pref[l-1]<<endl;

		

	}

}

main(){

	ios;

	int T=1;

	//cin>>T;

	while(T--){

		solve();

	}

}