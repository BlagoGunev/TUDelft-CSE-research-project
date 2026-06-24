#include<bits/stdc++.h>

#define ll          long long int

#define pb          emplace_back

#define mp          make_pair

#define pii         pair<int,int>

#define vi          vector<int>

#define Max(a,b)    ((a)>(b)?(a):(b))

#define Min(a,b)    ((a)<(b)?(a):(b))

#define rep(i,a,b)  for (__typeof((b)) i=(a);i<(b);i+=1)

#define all(a)      (a).begin(),(a).end()

#define F           first

#define S           second

#define sz(x)       (int)x.size()

#define hell        1000000007

#define endl        '\n'

#define debug(a)    cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';

using namespace std;



void solve(){

    int n;

    cin>>n;

    vector<pair<pii,int>>x(n);

    rep(i,0,n){

        cin>>x[i].F.F>>x[i].F.S>>x[i].S;

    }

    int m;

    cin>>m;

    vector<pair<pii,int>>y(m);

    rep(i,0,m){

        cin>>y[i].F.F>>y[i].F.S>>y[i].S;

    }

    int ans=0;

    rep(i,0,n){

        int peri=(2*(x[i].F.F+x[i].F.S));

        int cur=INT_MAX;

        rep(j,0,m){

            if((y[j].F.F/x[i].S)*y[j].F.S)cur=min(cur,((peri-1)/((y[j].F.F/x[i].S)*y[j].F.S)+1)*y[j].S);

        }

        ans+=cur;

    }

    cout<<ans;

}



int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	int t=1;

//	cin>>t;

	while(t--){

		solve();

	}

	return 0;

}