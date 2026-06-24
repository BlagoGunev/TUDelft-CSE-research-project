#include <bits/stdc++.h>

using namespace std;

const int OO = 0x3f3f3f3f;
const double eps = (1e-10);

#define watch(x) cout << (#x) << " is " << (x) << '\n'
#define trav(a, x) 			for(auto& a : x)
#define lp(i, n) 			for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n) 		for(int i=(j);i>=(int)(n);--i)
#define ndl 				cout<<'\n'
#define all(v) 				((v).begin()), ((v).end())
#define rall(v) 			((v).rbegin()), ((v).rend())
#define present(a, x) 		((a).find((x)) != a.end())
#define cpresent(a, x) 		(find(all(a),x) != a.end())
#define sz(v) 				((int)((v).size()))
#define clr(v, d) 			memset(v, d, sizeof(v))
#define pb 					push_back
#define mp 					make_pair
#define fs 					first
#define sc 					second
#define fstok(s,del) 		strtok((char *)s.c_str(),del)
#define tok(del) 			strtok(nullptr,del)
#define mod(x, m) 			((((x) % (m)) + (m)) % (m))


typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<int> > vvi;
typedef vector<bool> vb;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef set<int> si;
	int n , arr[300005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
    cin>> n ;
    deque<int> q ;
    int x, dd=0 ;
    char c ;

    lp(i,n)
    {
        cin >>c>>x;
        if (c=='R')
            q.pb(x), arr[x] = q.size()-1-dd;
        else if (c== 'L')
            dd+= (i>0 ), arr[x] = -dd, q.push_front(x);
        else
        {
            int idx = arr[x] + dd;
            int left = q.size()-1-idx;
           //    watch(idx), watch(x),watch(left), watch(i);
            cout << min(idx , left),ndl;
        }
    }
	return 0;
}