/*author : Yashvardhan
Tuesday, February 19, 2019
9:51 PM
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll
#define pb push_back
#define vi vector<int>
#define pi pair<int,int>
#define vpi vector<pi>
#define ff first
#define ss second
#define endl '\n'

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS

#ifdef __APPLE__
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << "  ";
	__f(comma + 1, args...);}
#else
#define debug(...)
#endif

template <typename T> ostream& operator << (ostream& os,const vector<T>& v){for(int i=0;i<v.size();++i) os<<v[i]<<" ";return os;} 
template <typename T> ostream& operator << (ostream& os,const set<T>& v){for(auto it:v) os<<it<<" ";return os;} 
template <typename T, typename S> ostream& operator << (ostream& os, const pair<T,S>& v) {os<<v.ff<<" "<<v.ss;return os;}

const int mod = 1e9 + 7;
const int inf = 2e18;
const int ninf = -2e18;

vi dose;
int n,m;

int pow(int a, int b, int m)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % m;
		b /= 2;
		a = (a * a) % m;
	}
	return ans;
}

bool checker(int days){
	int pages = 0;
	if(days >= n){
		
		for(int i = 0; i < n ; i++){
			pages += dose[i];
		}
	}
	else{
		int indi = 0;
		
		int pass = 0;
		int d = 0;
		while(indi < n){
			pages += max(dose[indi] - pass,(ll)0);
			d++;
			if(d%days == 0){
				pass++;
			}
			indi++;
		}
	}
	debug(days);
	debug(pages);
	if(pages >= m) return true;
	return false;
}

signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef __APPLE__
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#endif

	time_t t1, t2;
	t1 = clock();
	
	
	cin>>n>>m;
	for(int i = 0; i < n  ; i++){
		int x;
		cin>>x;
		dose.pb(x);
	}
	sort(dose.rbegin(),dose.rend());

	int low = 1;
	int high = n;
	int ans = 0;
	if(!checker(n)){
		ans = -1;
	}
	else{
		while (low <= high)
		{
			int mid = (low+high)/2;
			if(checker(mid)){
				high = mid - 1;
				ans = mid;
			}
			else{
				low = mid + 1;
			}
		}
	}
	cout<<ans<<endl;
	
	

	t2 = clock();
	cerr<<endl<<t2-t1<<endl;
	
	return 0;
}