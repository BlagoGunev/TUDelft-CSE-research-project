#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;
ll n,m,an1[200005],an2[200005],ans,fix[200005],mx[200005],xx,yy;
vector<ll>v[200005],g,an;
vector<pair<ll,ll> > anss;
void dfs(ll x,ll par){
	g.pb(x);
    an1[x]=1;
    an2[x]=1;
    fix[x] = 1;
    for(int i=0; i<v[x].size(); i++){
        if(v[x][i]==par)continue;
        dfs(v[x][i],x);
        if(an1[v[x][i]] + 1 > an1[x]){
            ll p = an1[x];
            an1[x] = an1[v[x][i]] + 1;
            an2[x] = p;
        }
        else an2[x] = max(an2[x],an1[v[x][i]] + 1);
    }
    ans = max(ans,an1[x] + an2[x] - 2);
}
void gg(ll x,ll par,ll tt,ll dep){
	mx[tt] = max(mx[tt],dep);
	fix[x] = 1;
	for(int i=0; i<v[x].size(); i++){
		if(v[x][i] != par)gg(v[x][i],x,tt,dep+1);
	}
}
int main(){
	cin>>n>>m;
	
	for(int i=1; i<=m; i++){
		cin >> xx >> yy;
		v[xx].pb(yy);
		v[yy].pb(xx);
	}
	
	
	for(int i=1; i<=n; i++){
		gg(i,-1,i,0);
	}
	for(int i=1; i<=n; i++)fix[i] = 0;
	for(int i=1; i<=n; i++){
		if(!fix[i]){
			g.clear();
			dfs(i,-1);
			ll mn = 9999999999,ind;
			for(int j=0; j<g.size(); j++){
				if(mn > mx[g[j]]){
					ind = g[j];
					mn = mx[g[j]];
				}
			}
			anss.pb({mn,ind});
		}
	}
	
	sort(anss.begin(),anss.end());
	ll b = 1;
	for(int i=0; i < anss.size(); i++){
		an.pb(anss[i].s);
	}
	
	for(int i=0; i<an.size()-1; i++){
		v[an[an.size()-1]].pb(an[i]);
		v[an[i]].pb(an[an.size()-1]);
	}
	ans = 0;
	dfs(1,-1);
	
	cout << ans << endl;
	
	for(int i=0; i<an.size()-1; i++){
		cout << an[an.size()-1] << " " << an[i] << endl;
	}
	
	
	return 0;
}