#include<bits/stdc++.h>

#define ll          long long int

#define pb          push_back

#define mp          make_pair

#define pii         pair<int,int>

#define vi          vector<int>

#define Max(a,b)    ((a)>(b)?(a):(b))

#define Min(a,b)    ((a)<(b)?(a):(b))

#define rep(i,a,b)  for (int i=(a);i<(b);i+=1)

#define all(a)      (a).begin(),(a).end()

#define F           first

#define S           second

#define sz(x)       (int)x.size()

#define hell        1000000007

#define endl        '\n'

#define debug(a)    cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';

using namespace std;



void solve(){

    string s;

    cin>>s;

    map<int,int>m;

    map<int,int>n;

    for(char i:s){

        m[i-'0']++;

        n[i-'0']++;

    }



    sort(all(s));

    string ans1=s,ans2=s;

    int curz=0;

    rep(i,1,10){

        if(!(m[i]>0 &&n[10-i]>0))continue;

        m[i]--;

        n[10-i]--;

        int curans=1+min(m[0],n[9])+min(m[1],n[8])+min(m[2],n[7])+min(m[3],n[6])+min(m[4],n[5])+min(m[5],n[4])+min(m[6],n[3])+min(m[7],n[2])+min(m[8],n[1])+min(m[9],n[0])+min(max(0,m[0]-n[9]),max(0,n[0]-m[9]));

        int zeroes=min(max(0,m[0]-n[9]),max(0,n[0]-m[9]));

        cerr<<i<<" "<<curans<<endl;

        if(curans>curz){



            curz=curans;

            map<int,int>used1;

            map<int,int>used2;

            ans1="";

            ans2="";

            rep(i,0,zeroes){

                ans1.pb('0');

                ans2.pb('0');

            }

            used1[0]+=zeroes;

            used2[0]+=zeroes;

            ans1.pb(i+'0');

            ans2.pb(10-i+'0');

            rep(i,0,10){

                rep(j,0,min(m[i],n[9-i])){

                    ans1.pb(i+'0');

                    ans2.pb(9-i+'0');

                    used1[i]++;

                    used2[9-i]++;

                }

            }

            int alpha=0,beta=0;

            rep(i,0,10)alpha+=m[i]-used1[i];

            rep(i,0,10)beta+=n[i]-used2[i];

            rep(kachra,0,10){

                rep(gf,0,m[kachra]-used1[kachra])ans1.pb(kachra+'0');

            }

            rep(kachra,0,10){

                rep(gf,0,n[kachra]-used2[kachra])ans2.pb(kachra+'0');

            }

        }

        m[i]++;

        n[10-i]++;

    }

    reverse(all(ans2));

    reverse(all(ans1));



    cout<<ans1<<endl<<ans2;

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