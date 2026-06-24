#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fr(n) for(int i=1;i<=n;++i)
#define re return 0;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
 
const int N = int(5e5) + 3;
const int LG = 20;
const ll mod = 1e9+7;
const int INF = 2147483647;
const ll linf = 1e18;
const ld pi = acos(-1);
const ld EPS = 1e-10;
const ll maxn = 1e5+7; 
 
 
 map <int ,int >mpp;
 int xx,n,k,a;
 int main(){
 	deque<int>q;
 	cin>>n>>k;
 	for(int i=0;i<n;++i){
 		cin>>a;
 		if(mpp[a]!=0){
 			continue;
		 }
		 else if(xx<k){
		 	q.push_front(a);
		 	++xx;
		 	mpp[a]++;
		 }
		 else {
		 	mpp[q.back()]--;
		 	q.pop_back();
		 	q.push_front(a);
		 	mpp[a]++;
		 }
		 
	 }
	 cout<<xx<<'\n';
	 while(sz(q)){
	 	cout<<q.front()<<" ";
	 	q.pop_front();
	 }
 }