#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define mk make_pair
#define pb push_back
#define f first
#define s second
using namespace std;
// using namespace __gnu_pbds;

void compile(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
const int N = 1e5 + 10;
ll mod = 1e9 + 7;
ll fact[N];
ll mul(ll a , ll b){
    return (a * b) % mod ;
}
ll add(ll a , ll b){
    return ((a % mod) + (b % mod)) % mod; 
}
ll power(ll a , ll b){
    ll ans = 1 , cur = a;
    while(b){
        if(b%2) ans = mul(ans , cur);
        cur = mul(cur , cur);
        b /= 2;
    }
    return ans % mod ;
}
vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> ans(2 , vector<int> (2 , 0));
    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<2 ; j++){
            for(int k=0 ; k<2 ; k++){
                ans[i][j] = add(ans[i][j] , mul(a[i][k] , b[k][j]));
            }
        }
    }
    return ans;
}
vector<vector<int>> power(vector<vector<int>> mat, int b){
    vector<vector<int>> ans = {{1,0},{0,1}};
    while(b){
        if(b%2) ans = mul(ans , mat);
        mat = mul(mat , mat);
        b /= 2;
    }
    return ans;
}
ll divide(ll a , ll b){
    return mul(a , power(b , mod - 2)) % mod ;
}
ll nck(ll a , ll b){
    return divide(fact[a] , mul(fact[b],fact[a-b]) ) % mod ;
}
ll npk(ll a , ll b){
    return divide(fact[a] , fact[b]) % mod;
}

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int n,m;
int s[N] , l[N];
vector<vector<int>> mat;

void solve(){   

    cin >> m >> n;
    for(int i=0 ; i<m ; i++) cin >> s[i];

    for(int i=0 ; i<m ; i++) cin >> l[i];

    mat.resize(2 , vector<int> (2,0));
    for(int i=0 ; i<m ; i++){
        mat[0][0] = add(mat[0][0] , mul(s[i] , add(s[i],l[i])));
        mat[0][1] = add(mat[0][1] , mul(l[i] , add(s[i],l[i])));
        mat[1][0] = add(mat[1][0] , mul(s[i] , s[i]));
        mat[1][1] = add(mat[1][1] , mul(s[i] , l[i]));
    }

    mat = power(mat, n-1);
    int ans = 0;
    for(int i=0 ; i<m ; i++){
        ans = add(ans, mul(s[0], mul(mat[0][1], s[i]))); 
        ans = add(ans, mul(s[0], mul(mat[0][0], add(s[i], l[i]))));
        ans = add(ans, mul(l[0], mul(mat[1][1], s[i]))); 
        ans = add(ans, mul(l[0], mul(mat[1][0], add(s[i], l[i]))));
    }
    cout << ans;


    
}

int main() {

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    

    return 0;
}