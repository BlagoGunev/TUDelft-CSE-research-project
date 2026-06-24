#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <array>
#include <bitset>

using namespace std;
typedef long long ll;

const int maxn=2e5+5;

vector < int > ms[maxn];
int rev[maxn];

int h[maxn];

int kol[maxn];
int kad[maxn];

void siri(int x){
	if(kol[x]!=-1){
		return;
	}
	kol[x]=0;
	kad[x]=h[x];
	for(int i=0; i<(int)ms[x].size(); i++){
		int y=ms[x][i];
		siri(y);
		if(h[y]<h[x]){
			if(kol[y]+1>kol[x]){
				kol[x]=kol[y]+1;
				kad[x]=kad[y];
			}
			else if(kol[y]+1==kol[x] && kad[y]>kad[x]){
				kad[x]=kad[y];
			}
		}
		else{
			if(kol[y]>kol[x]){
				kol[x]=kol[y];
				kad[x]=kad[y];
			}
			else if(kol[y]==kol[x] && kad[y]>kad[x]){
				kad[x]=kad[y];
			}
		}
	}
}


vector < pair < int, pair < int, int > > > v;
map < int, pair < int, bool > > aha;

bool cmp(pair < int, pair < int, int > > a, pair < int, pair < int, int > > b){
	if(a.first!=b.first){
		return a.first>b.first;
	}
	return a.second.first<b.second.first;
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		cin >> h[i];
		kol[i]=-1;
	}
	int a, b;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		a--;
		b--;
		ms[a].push_back(b);
		rev[b]++;
	}
	for(int i=0; i<n; i++){
		if(!rev[i]){
			siri(i);
			v.push_back({kol[i], {h[i], kad[i]}});
		}
	}
	sort(v.begin(), v.end(), cmp);
	int maksi=v[0].first;
	int kolicina=maksi, tren=0;
	for(int i=0; i<(int)v.size(); i++){
		if(maksi==v[i].first){
			tren=max(tren, v[i].second.second);
			if(aha.find(v[i].second.first)!=aha.end()){
				aha[v[i].second.first].first=max(aha[v[i].second.first].first, v[i].second.second);
			}
			else{
				aha[v[i].second.first]={v[i].second.second, 1};
			}
		}
		else if(maksi==v[i].first+1){
			if(aha.find(v[i].second.first)==aha.end()){
				aha[v[i].second.first]={v[i].second.second, 0};
			}
			else if(!aha[v[i].second.first].second){
				aha[v[i].second.first].first=max(aha[v[i].second.first].first, v[i].second.second);
			}
		}
	}
	ll sol=(ll)kolicina*k+tren;
	for(auto x : aha){
		sol=min(sol, (ll)kolicina*k+tren-x.first);
		if(x.second.second){
			if(kolicina==maksi){
				kolicina++;
				tren=x.second.first;
			}
			else{
				tren=max(tren, x.second.first);
			}
		}
		else if(kolicina==maksi){
			tren=max(tren, x.second.first);
		}
	}
	cout << sol << '\n';
	v.clear();
	aha.clear();
	for(int i=0; i<n; i++){
		ms[i].clear();
		rev[i]=0;
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}