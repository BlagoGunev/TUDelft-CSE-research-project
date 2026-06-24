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

int a,b,c,n,m,q,i,t,j,k,x,y,cnt=0,sum=0,res=0;

Baytoro_Mayrambekov{

	cin>>n>>k>>x;

	vector<int> vec(n);

	for(i=0;i<n;i++)

		cin>>vec[i];

	sort(all(vec));

	vector<pair<int,int>> g;

	int min=vec[0];

	for(i=1;i<n;i++){

		if(vec[i]-vec[i-1]>x){

			g.pb({min,vec[i-1]});

			min=vec[i];

		}

	}

	g.pb({min,vec[n-1]});

	res=g.size();

	vector<int> ans;

	for(i=1;i<g.size();i++){

		a=(g[i].fr-g[i-1].sc)/x;

		if((g[i].fr-g[i-1].sc)%x>0)

			a++;

		ans.pb(a-1);

		

	}

	sort(all(ans));

//	for(auto it: vec)

//		cout<<it<<' ';

//	cout<<endl;

//	cout<<res<<endl;

//	for(auto it: ans)

//		cout<<it<<' ';

//	cout<<endl;

	for(i=0;i<ans.size();i++){

		if(k<=0)

			break;

		if(ans[i]<=k){

			k-=ans[i];

			res--;

		}

		else

			break;

	}

	cout<<res<<endl;

}

main(){

	ios;

	int T=1;

//	cin>>T;

	while(T--){

		solve();

	}

}