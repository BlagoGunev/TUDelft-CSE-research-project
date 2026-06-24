//i hate _____
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long int
#define lll __int128_t
#define ld long double
#define pb push_back
#define ii pair<int,int>
double pi = 2 * acos(0.0) ;

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    os << '{';
    for (const auto &x : v) os << " " << x;
        return os << '}';
}

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int n;
vector<int>v;

int make_ans(int ix, int x, int y){
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        double tmp = (double)v[ix] + ((double)(i-ix)*(v[y]-v[x])/(double)(y-x));
        if (v[i] != tmp) cnt++;
    }
    return cnt;
}

void solve(){
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (n < 3) {
        cout << "0\n";
        return;
    }
    int ans = 110;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double x = (double)(v[j] - v[i])/(double)(j-i);
            ans = min(ans,make_ans(i,i,j));
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test_cases = 1;
    cin >> test_cases;

    for (int tc = 1 ; tc <= test_cases ; tc++){

        //cout << "Case " << tc << ": ";
        solve();
        //printf("Case %d: %.10lf\n",tc,ans);

    }

    return 0;
}
/*
    problems are the sign of life
*/