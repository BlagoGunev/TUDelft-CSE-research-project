#include<bits/stdc++.h>

using namespace std;



#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define endl '\n'

#define eb emplace_back

#define pb push_back

#define fi first

#define se second

#define all(x) (x).begin(),(x).end()

mt19937 mrand(random_device{}()); 

int rnd(int x) { return mrand() % x;}

typedef vector<int> VI;

typedef pair<int,int> PII;

typedef double db;



void solve(){

	int a,b,ab,ba;cin>>a>>b>>ab>>ba;

	string s;cin>>s;

	

	if (count(all(s),'A')!= a+ab+ba){

		cout<<"NO\n";return; 

	}

	

	int n=s.size(),l=1,sum=0;

	s+=s[n-1];

	VI q[2];

	for (int i=1;i<=n;++i)

	 if (s[i]==s[i-1]){

	 	if (l&1) sum+=l/2;

	 	 else q[(s[i-1]-'A')^1].pb({l/2});

	 	l=1;

	 }else l++;

	

	sort(all(q[0]));sort(all(q[1]));

	int i=0,j=0;

	while (i<q[0].size() && ab>=q[0][i]) ab-=q[0][i++];

	while (j<q[1].size() && ba>=q[1][j]) ba-=q[1][j++];

	while (i<q[0].size()) sum+=q[0][i++]-1;

	while (j<q[1].size()) sum+=q[1][j++]-1;

	cout<<(ab+ba<=sum ? "YES\n":"NO\n");

}



signed main(){

	IOS

	int T;cin>>T;

	while (T--) solve();

}