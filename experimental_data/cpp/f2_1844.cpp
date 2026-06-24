#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    forn(ti, t) {
        int n; ll c;
        cin >> n >> c;
        vector<ll> a(n);
        forn(i, n) cin >> a[i];
        sort(a.begin(), a.end());

        if(c >= 0) {
            // print a increasing
            forn(i, n) {
                cout << a[i] << " ";
            }
            cout << "\n";
            continue;
        }

        // c < 0
        reverse(a.begin(), a.end());
        vector<int> left(n), right(n);
        forn(i, n) {
            left[i] = i-1;
            right[i] = i+1;
        }
        vector<int> out(n); // the farthest you can reach
        vector<set<int>> ins(n); // the indices that reach you
        vector<int> inptr(n);
        forn(i, n) inptr[i] = i;
        //out[i] is the largest j > i such that a[j] - a[i] >= c, or i+1 if no such j exists
        
        int currind = 0;
        forn(i, n) {
            while(currind < n-1 && a[currind + 1] - a[i] >= c) {
                currind++;
            }
            if(currind == i) currind++;
            out[i] = currind;
            if(currind < n)
                ins[currind].insert(i);
        }

        vector<bool> articulation(n);
        forn(i, n) {
            if(i > 0 && out[i-1] == i) {
                articulation[i] = true;
            }
        }
        set<int> nonartics;
        forn(i, n) {
            if(!articulation[i]) {
                nonartics.insert(i);
            }
        }

        // cout << "HERE" << endl;
        vector<bool> alive(n, true);
        vector<int> ans;
        // cout << out << endl;
        int prev = -1;
        forn(i, n) {
            // cout << "i: " << i << endl;
            int to_remove;
            if(prev == -1) {
                to_remove = 0;
            } else {
                //to_remove is largest element of nonartics that's <= out[prev]
                auto it = nonartics.upper_bound(out[prev]);
                assert(it != nonartics.begin());
                it--;
                to_remove = *it;
            }
            // cout << to_remove << endl;
            ans.pb(to_remove);
            alive[to_remove] = false;
            
            // remove to_remove
            nonartics.erase(to_remove);
            int lft = left[to_remove], rgt = right[to_remove];
            if(lft == -1) {
                nonartics.insert(rgt);
            } else {
                if(out[lft] == rgt) {
                    nonartics.erase(rgt);
                }

                if(ins[inptr[to_remove]].find(left[lft]) != ins[inptr[to_remove]].end()) {
                    nonartics.erase(lft);
                }

                //merge the ins of lft and to_remove
                if(ins[inptr[lft]].size() < ins[inptr[to_remove]].size()) {
                    swap(inptr[lft], inptr[to_remove]);
                }
                for(int x: ins[inptr[to_remove]]) {
                    if(!alive[x]) continue;
                    ins[inptr[lft]].insert(x);
                }
            }


            if(lft >= 0) {
                right[lft] = rgt;
            }
            if(rgt < n) {
                left[rgt] = lft;
            }
            prev = to_remove;
        }

        // cout << ans << "\n";
        // print ans
        forn(i, n) {
            cout << a[ans[i]] << " ";
        }
        cout << "\n";

    }
}