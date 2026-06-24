#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

#include<bits/stdc++.h>

using namespace __gnu_pbds;

using namespace std;

typedef long long ll;

#define Rep(i,n) for(ll i=0; i<int(n); ++i)

#define read(v) for (auto &it : v) cin >> it;

void __print(int x) {cerr << x;}

void __print(ll x) {cerr << x;}

void __print(char x) {cerr << x;}

void __print(const string &x) {cerr << '\"' << x << '\"';}

template<typename T, typename V>

void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>

void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>

void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE

#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)

#else

#define deb(x...)

#endif

#define all(v) (v).begin(),(v).end()

#define rall(v) (v).rbegin(),(v).rend()

#define pii pair<int, int>

#define pll pair<ll, ll>

#define vi vector<int>

#define vl vector<ll>

#define pb push_back

#define ld long double

#define mod 1000000007

#define endl '\n'

#define m_p make_pair

#define ff first

#define ss second

const int INF = INT_MAX;

int dx[]={0,0,+1,-1};

int dy[]={+1,-1,0,0};

#define int long long

const int N = 1e5+5;



void solve(){

    int n,m; cin>>n>>m;

    vector<vector<int>> v(n+5,vector<int>(m+5)),

    sum(n+5,vector<int>(m+5));



    for(int i=1; i<=n; i++){

        for(int j=1; j<=m; j++){

            cin>>v[i][j];

        }

    }

    if(n == 1 || m==1){

        cout<<"1\n";

        return;

    }

    int l = 1, r = n, ans = 1;

    while(l<=r){

        int mid = (l+r)/2;

        auto check = [&]()->bool{

            if(mid==1) return 1;

            else if(mid>n || mid>m) return 0;



            for(int i=1; i<=n; i++){

                for(int j=1; j<=m; j++){

                    sum[i][j] = (v[i][j]>=mid);

                }

            }

            for(int i=1; i<=n; i++){

                for(int j=1; j<=m; j++){

                    sum[i][j] += sum[i][j-1];

                }

            }

            for(int i=1; i<=n; i++){

                for(int j=1; j<=m; j++){

                    sum[i][j] += sum[i-1][j];

                }

            }

            for(int i=mid; i<=n; i++){

                for(int j=mid; j<=m; j++){

                    int x = sum[i][j]+sum[i-mid][j-mid]

                    -sum[i-mid][j]-sum[i][j-mid];

                    if(x == mid*mid) return 1;

                }

            }

            return 0;

        };

        if(check()){

            ans = mid;

            l = mid+1;

        }

        else r = mid-1;

    }

    cout<<ans<<"\n";

}



int32_t main(){

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

    #endif

    int tt=1;

    cin>>tt;

    for(int i=1; i<=tt; i++){

        // cout<<"Case "<<i<<": ";

        solve();

    }

    return 0;

}