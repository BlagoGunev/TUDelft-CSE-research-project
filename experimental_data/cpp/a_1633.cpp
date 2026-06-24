#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define fast  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tc ll t; cin>>t; while(t--)
#define f() for(ll i=0;i<n;i++)
#define f1() for(ll i=1;i<=n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define int ll
#define vi vector<int>
#define a6 1000001
#define p push
#define pii pair<int,int> 
#define um unordered_map<int,int>
#define flag if(fg) cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define fo(o,n) for(int i=o;i<n;i++)
#define fro(o,n) for(int i=o;i>=0;i--)
#define a7 10000001
#define inf INT_MAX
#define ff first
#define ss second
#define vpii vector<pii>
#define endl "\n"
#define len(s) (int)s.size()
#define google int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";solve();}
#define read(x) int x;cin>>x;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void intext(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	#endif
}
void solve(){
	int n; cin>>n;
	int ans=n%7;
	if(n%7==0){
		cout<<n<<endl;
		return;
	}
	if(n%10<ans){
		cout<<n+(7-ans)<<endl;
	}
	else cout<<n-ans<<endl;
}
signed main()
{
	fast
	intext();
	tc solve();
}