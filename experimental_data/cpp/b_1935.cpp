//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")

#include <bits/stdc++.h>


clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

#ifdef TEPAMID
    #define debug_print(x) cerr << x << endl;
    #define debug(x) cerr << #x << " = " << x << endl;
    #define debug_v(v)             \
        {                          \
            cerr << #v << " = [ "; \
            for (auto x : v)       \
                cerr << x << " ";  \
            cerr << "]" << endl;   \
        }
    #define debug_vp(v)                       \
        {                                     \
            cerr << #v << " = [ ";            \
            for (auto [x, y] : v)             \
                cerr << x << "," << y << " "; \
            cerr << "\\" << endl;             \
        }
#else
    #define debug_print(x) 0;
    #define debug(x) 0;
    #define debug_v(x) 0;
    #define debug_vp(x) 0;
#endif // TEPAMID

using namespace std;

// mt19937 rng(5);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fo(i, n) for (int i = 0; i < n; ++i)
#define foback(i, n) for (int i = n - 1; i >= 0; --i)
#define fo1(i, n) for (int i = 1; i <= n; ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())

typedef long long ll;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void one();


int main() {
	startTime = clock();
    fastio();

    int t = 1;
// #ifdef TEPAMID
    cin >> t;
// #endif
    fo(TEST, t) {
        debug_print("TEST " + to_string(TEST) + " START");
        one();
        debug_print("TEST " + to_string(TEST) + " END time = " + to_string(getCurrentTime()) + " sec\n");
// #ifdef TEPAMID
//     cout << "\n";
// #endif
    }

    return 0;
}

void one () {
   int n; cin>>n;
  
   vector<int> a(n);
   fo(i,n) cin>>a[i];

    multiset<int> se(all(a));

    set<int> ls;
    set<int> rs;
    fo(x,n+1) {
        ls.insert(x);
        if (se.find(x) == se.end()) rs.insert(x);
    }

    for(int i=0; i<n-1; i++) {
        ls.erase(a[i]);
        se.erase(se.find(a[i]));
        auto x = a[i];
        if (se.find(x) == se.end()) rs.insert(x);
        
        auto mexl = *ls.begin();
        auto mexr = *rs.begin();

        if (mexl == mexr) {

            cout << 2 << "\n";
            cout << 1 << " " << i+1 <<"\n";
            cout << i+1+1 << " " << n <<"\n";

            return;
        }
    }

    cout <<"-1\n";

    // int l=0;
    // int r=n-1;
    // int x=0;

    // while(l < r) {
    //     int c = se.count(x);
    //     // if (se.find(x) == se.end()) {
    //     if (c==0) {
    //         break;
    //     }
    //     if (c==1) {
    //         cout <<"-1\n";
    //         return;
    //     }

    //     while(a[l]!=x) {
    //         se.erase(se.find(a[l]));
    //         l++;
    //     }
    //     while(a[r]!=x) {
    //         se.erase(se.find(a[r]));
    //         r--;
    //     }
    //     x++;
    // }
    // debug(l)
    // debug_v(a)
    // debug(x)

    // cout << 2 << "\n";
    // cout << 1 << " " << l+1 <<"\n";
    // cout << l+2 << " " << n <<"\n";
}