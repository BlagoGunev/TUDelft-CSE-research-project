#include<bits/stdc++.h>

using namespace std;



#define int long long

#define double long double

#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);



#define pii pair<int,int>

#define ff first

#define ss second

#define mp make_pair



#define pb push_back

#define pf push_front

#define all(x) x.begin(),x.end()



#define de(x) cout << #x << ' ' << x << '\n';

template<class T> void prt(T l,T r){

  while(l!=r) cout << *l << ' ',l++;

  cout << '\n';

}



const int N=1e6+5,M=1e9+7,INF=1e18;



signed main(){

  IO

	int n;cin >> n;

	string s;cin >> s;

	int l=1,r=1<<n;

	int cnt0=-1,cnt1=-1;

	for(int i=0;i<s.length();i++){

		if(s[i]=='1') cnt0++,l+=1<<cnt0;

		else cnt1++,r-=1<<cnt1;

	}

	for(;l<=r;l++) cout << l << ' ';

	cout << '\n';

  return 0;

}