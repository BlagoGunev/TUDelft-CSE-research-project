#include <bits/stdc++.h>

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/pb_ds/assoc_container.hpp>



using namespace std;

using namespace __gnu_pbds;



#define EPS 1e-9

#define PI acos(-1)

#define ll long long

#define Mod 1'000'000'007

#define INF 2'000'000'000

#define sz(x) int(x.size())

#define all(s) s.begin(), s.end()

#define rall(s) s.rbegin(), s.rend()

#define Num_of_Digits(n) ((int)log10(n)+1)

#define to_decimal(bin) stoll(bin, nullptr, 2)

#define fixed(n) cout << fixed << setprecision(n)

#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))

#define cout(st) for(auto& i : st) cout << i << " "; cout << "\n"

#define cout_map(mp) for(auto& [f, s] : mp) cout << f << " : " << s << "\n"

#define matrix(grid, n, m) vector < vector <int> > grid(n, vector <int> (m));

#define cout_2d(grid) for(auto& v : grid){for(auto& x : v) cout << x << " "; cout << "\n";}

#define cin_2d(grid, n, m) for(int i=0; i<n; i++) for(int j=0; j<m && cin >> grid[i][j]; j++);

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define multi_ordered_set tree<int, null_type, greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>



template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {

    for (auto &x: v) in >> x;

    return in;

}



template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 

    for (const T &x: v) out << x << ' ';

    return out;

}



void Anwar_Rizk(){

  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

  #endif

}



void solve(){

    ll n, k, ans = 0;

    string s;

    cin >> n >> k >> s;

    if(s[n - 1] == '0')

    {

        for(int i = n - 1; i >= 0; i--){

            if(s[i] == '1'){

                int d = n - (i + 1);

                if(d <= k) swap(s[i], s[n - 1]), k -= d;

                break;

            }

        }

    }

    if(s[0] == '0')

    {

        for(int i = 0; i < n - 1; i++){

            if(s[i] == '1'){

                if(i <= k) swap(s[i], s[0]);

                break;

            }

        }

    }

    for(int i = 0; i < n - 1; i++){

        ans += stoll(s.substr(i, 2));

    }

    cout << ans << "\n";

}



int main()

{   Anwar_Rizk();



    int t = 1;

    cin >> t;

    while(t--){

      solve();

    }



  return 0;

}