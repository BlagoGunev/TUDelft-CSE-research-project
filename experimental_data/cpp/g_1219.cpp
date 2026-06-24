#include <bits/stdc++.h>
using namespace std;
 
struct fastio{
	fastio(){
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout << setprecision(12);
		cout << fixed;
	}
}_____;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define all(c) c.begin(), c.end()
#define FOR(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define FORD(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;

 
const ll INF = 1e9;
const int MAX = 1e5 + 10;
const ld EPS = 1e-8;
const ll mod = 1e9 + 7;

int n,m;
vector<vector<ll>> a;
ll sumx[100001];
ll sumy[100001];
int main(){                    
	cin >> n >> m;
	a.resize(n);
	for(int i =0 ;i <n;i++)
		a[i].resize(m);
	for(int i =0 ;i <n;i++)
		for(int j =0 ;j <m;j++)
			cin >> a[i][j];
	 for(int i = 0;i <n;i++)
	 	for(int j =0 ;j <m;j++)
	 		sumx[i]+=a[i][j];
	for(int i =0 ;i <m;i++)
		for(int j =0  ;j < n;j++)
			sumy[i]+=a[j][i];
	vector<ll> x;
	vector<ll > y;
	for(int i =0 ;i <n;i++)
		x.pb(sumx[i]);
	for(int i =0 ;i <m;i++)
		y.pb(sumy[i]);
	sort(x.rbegin(),x.rend());
	sort(y.rbegin(),y.rend());
	ll maxx =-1;
	ll sum =0 ;
	for(int i =0 ;i <4 && i <x.size();i++)	
	       sum+=x[i];
	maxx = max(maxx,sum);
	sum = 0;
	for(int i =0 ;i <4 && i <y.size();i++)
		sum+=y[i];
	maxx = max(maxx,sum);
	int maxnum = -1;
	ll maxans = -1;
	for(int i = 0;i <n;i++){
		y.clear();
		for(int j =0 ;j <m;j++)
			y.pb(sumy[j] - a[i][j]);
		sort(y.rbegin(),y.rend());
		ll sum = sumx[i];
		for(int i =0;i <3 && i < y.size();i++)
			sum+=y[i];
		if(maxans < sum){
			maxans = sum;
			maxnum =i;
			}	
	}
	maxx = max(maxx, maxans);
	for(int i =0 ;i <n;i++)
		if(i!=maxnum){
			y.clear();
			for(int j =0 ;j  <m;j++)
				y.pb(sumy[j] - a[i][j] -a[maxnum][j]);
			sort(y.rbegin(),y.rend());
			ll sum = sumx[i]+sumx[maxnum];
			for(int i =0 ;i <2 && i <y.size();i++)
				sum+=y[i];
		  maxx = max(maxx, sum);
	}	
	maxnum = -1;
	maxans =-1;
	for(int i =0 ;i< m;i++){
		x.clear();
		for(int j =0 ;j < n;j++)
			x.pb(sumx[j] -a[j][i]);
		sort(x.rbegin(),x.rend());
		ll sum = sumy[i];
		for(int i =  0; i <3 && i <x.size();i++)
			sum+=x[i];
		if(maxans < sum){
			maxans = sum;
			maxnum = i;
		}
	}
	for(int i =0 ;i <m;i++)
		if(i!=maxnum){
			x.clear();
			for(int j =0 ;j <n;j++)
				 x.pb(sumx[j] - a[j][i] - a[j][maxnum]);
			 sort(x.rbegin(),x.rend());
			 ll sum = sumy[i]+sumy[maxnum];
			 for(int i =0  ;i <2 && i < x.size();i++)
			 	sum+=x[i];
			maxx = max(maxx,sum);
	}

	cout << maxx;
	return 0;
}