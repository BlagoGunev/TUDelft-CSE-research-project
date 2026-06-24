//raja1999
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);
vii v1;
vii v2;
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,j,tmp,x,y,c=0,c1=0,ans,val;
	cin>>n>>m;
	rep(i,n){
		cin>>x>>y;
		tmp=x;
		x=min(x,y);
		y=max(tmp,y);
		v1.pb(mp(x,y));
	}	
	set<int>se;
	rep(i,m){
		cin>>x>>y;
		tmp=x;
		x=min(x,y);
		y=max(tmp,y);
		v2.pb(mp(x,y));
	}
	rep(i,n){
		set<int>se1;
		rep(j,m){
			if(v1[i].ff==v2[j].ff&&v1[i].ss==v2[j].ss){
				continue;
			}
			if(v1[i].ff==v2[j].ss||v1[i].ff==v2[j].ff){
				se1.insert(v1[i].ff);
				ans=v1[i].ff;
			}
			else if(v1[i].ss==v2[j].ss||v1[i].ss==v2[j].ff){
				se1.insert(v1[i].ss);
				ans=v1[i].ss;
			}
		}
		if(se1.size()>1){
			cout<<-1<<endl;
			return 0;
		}
		else if(se1.size()==1){
			se.insert(ans);
		}
	}
	rep(i,m){
		set<int>se1;
		rep(j,n){
			if(v2[i].ff==v1[j].ff&&v2[i].ss==v1[j].ss){
				continue;
			}
			if(v2[i].ff==v1[j].ss||v2[i].ff==v1[j].ff){
				se1.insert(v2[i].ff);
				ans=v2[i].ff;
			}
			else if(v2[i].ss==v1[j].ss||v2[i].ss==v1[j].ff){
				se1.insert(v2[i].ss);
				ans=v2[i].ss;
			}
		}
		if(se1.size()>1){
			cout<<-1<<endl;
			return 0;
		}
		else if(se1.size()==1){
			se.insert(ans);
		}
	}
	//cout<<se.size()<<endl;
	if(se.size()==1){
		cout<<ans<<endl;
	}
	else {
		cout<<0<<endl;
	}
}