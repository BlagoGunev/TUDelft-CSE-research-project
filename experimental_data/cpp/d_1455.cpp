#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define all(x) (x).begin(), (x).end()

//debugging
//ChangeBinaryDisplay
static const int bytedisplaysize = 1;
#define debug(x) cerr << "db "<< #x <<": "; _print(x); cerr << endl;
#define debugbin(x) cerr << "db "<< #x <<": "; _printbin(x); cerr << endl;
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(char t) {cerr << '\'' << t << '\'';}
void _print(double t) {cerr << t;}
void _print(string t) {cerr << '"' << t << '"';}

void _printbin(ll t) {cerr << t; cerr <<" 0b";cerr << bitset<bytedisplaysize*8>(t);}
void _printbin(int t) {cerr << t; cerr << " 0b";cerr << bitset<bytedisplaysize*8>(t);}
void _printbin(ull t) {cerr << t; cerr << " 0b";cerr << bitset<bytedisplaysize*8>(t);}
void _printbin(char t) {cerr << '\'' << t << "' 0b"; cerr << bitset<bytedisplaysize*8>(t);}
void _printbin(ld t) {cerr << t; cerr << " 0b"; cerr << bitset<bytedisplaysize*8>(t);}
void _printbin(double t) {cerr << t; cerr << " 0b"; cerr << bitset<bytedisplaysize*8>(t);}
void _printbin(string t){cerr << "[ "; for (char i : t){_printbin(i); cerr << ", ";} cerr << "]";}

template <class T, class V> void _print(pair <T, V> p);
template <class T, class V> void _printbin(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _printbin(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _printbin(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _printbin(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _printbin(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T, class V> void _printbin(pair <T, V> p) {cerr << "{"; _printbin(p.first); cerr << ","; _printbin(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << ", ";} cerr << "]";}
template <class T> void _printbin(vector <T> v) {cerr << "[ "; for (T i : v) {_printbin(i); cerr << ", ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << ", ";} cerr << "]";}
template <class T> void _printbin(set <T> v) {cerr << "[ "; for (T i : v) {_printbin(i); cerr << ", ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << ", ";} cerr << "]";}
template <class T, class V> void _printbin(map <T, V> v) {cerr << "[ "; for (auto i : v) {_printbin(i); cerr << ", ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << ", ";} cerr << "]";}
template <class T> void _printbin(multiset <T> v) {cerr << "[ "; for (T i : v) {_printbin(i); cerr << ", ";} cerr << "]";}

const ld eps = 5e-8;
const int MOD = 1e9+7;

//#define int ll // Uncommment in case of emergency!

bool sorted(vector<int> &a){
    bool sor = true;
    for(int i = 1; i < a.size(); i++){
        if(a[i-1] > a[i])
            sor = false;
    }
    return sor;
}

void solve(int Case){

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &i : a) cin >> i;

    int ans = 0;
    int idx = 0;
    while(!sorted(a)){
        for(int i = idx; i < n; i++)
            idx += a[i] < x;

        if(idx == n) break;

        ans += a[idx] != x;
        int temp = a[idx];
        if(a[idx] < x){
            cout << "-1\n";
            return;
        }
        a[idx] = x;
        x = temp;
        idx ++;
    }

    if(!sorted(a)){
        cout << "-1\n";
        return;
    }

    cout << ans << '\n';

	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase;
	testCase = 1;
	cin >> testCase;

	for(int i= 1; i <= testCase; i++){
		solve(i);
	}

	return 0;
}