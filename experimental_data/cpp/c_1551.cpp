#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nln "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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

#ifndef ONLINE_JUDGE
#define log(x...) cerr << #x << ": "; _print(x); cerr << nln;
#else
#define log(x...)
#endif

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("error.err", "w", stderr);
    #endif
    int t;
    cin >> t;
    while(t--) {
    	int n; cin >> n;
    	string s;
    	int a, b, c, d, e;
    	int freq[5][n];
    	for(int i = 0; i < n; i++) {
    		cin >> s;
    		a = b = c = d = e = 0;
    		for(char ch : s) {
    			switch(ch) {
    				case 'a':
    					a++;
    					break;
    				case 'b':
    					b++;
    					break;
    				case 'c':
    					c++;
    					break;
    				case 'd':
    					d++;
    					break;
    				case 'e':
    					e++;
    					break;
    			}
    		}
    		freq[0][i] = 2 * a - s.length();
    		freq[1][i] = 2 * b - s.length();
    		freq[2][i] = 2 * c - s.length();
    		freq[3][i] = 2 * d - s.length();
    		freq[4][i] = 2 * e - s.length();
    	}
    	int ans = -1, j;
    	for(int i = 0; i < 5; i++) {
    		sort(freq[i], freq[i] + n, greater<int>());
    		int sum = freq[i][0];
    		if(sum < 1) continue;
    		j = 1;
    		while(j < n) {
    			sum += freq[i][j];
    			if(sum < 1) break;
    			j++;
    		}
    		if(ans < j) ans = j;
    	}
    	cout << max(ans, 0) << nln;
    }
    return 0;
}