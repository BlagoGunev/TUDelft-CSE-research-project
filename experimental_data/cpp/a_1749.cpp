#include <bits/stdc++.h>

using namespace std;



#define int long long int

#define pb push_back

#define f(i, j, k) for (int i = j; i < k; i++)

#define rev(i, j, k) for (int i = j; i >= k; i--)

#define all(x) (x).begin(), (x).end()



const int MOD = 1e9 + 7;

typedef vector<int> vi;

typedef vector<pair<int, int>> vp;

typedef priority_queue<int> pq;

const int N = 2e5 + 1;





void solve(){

    int n,m;

    cin>>n>>m;

    f(i,0,m){

        int temp1,temp2;

        cin>>temp1>>temp2;

    }

    if(n>m) cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

}



int32_t main(){

    #ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);

        freopen("Error.txt", "w", stderr);

    #endif

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    auto start1 = std::chrono::high_resolution_clock::now();

    int tt = 1;

    cin >> tt;

    f(i, 1, tt + 1)

    {

        solve();

    }

    auto stop1 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop1 - start1);

    // cerr << "Time: " << ((long double)duration.count()) / ((long double)1e9) << "s " << endl;

    return 0;

}