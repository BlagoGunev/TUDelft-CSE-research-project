/*
    in the name of god
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long 
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
typedef long long ll ;

#define ord_set(T)    tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
#define min_heap(X)   priority_queue<X,vector<X>,greater<X>>
#define max_heap(X)   priority_queue<X>
#define File          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define loop(i,f,d)   for(int i = f;i<d;i++)
#define loop2(j,f,d)  for(int j = f;j>=d;j--)
#define len(V)        (int)(V.size())
#define sep           ' '
#define endl          '\n'
#define pb(x)         push_back(x)
#define debug(x)      cerr  << "bug " << x << endl;
#define migmig        cin.tie(NULL);ios_base::sync_with_stdio(false);
#define fi            first
#define sec           second
#define popcount(x)   __builtin_popcount(x)
#define md(x)         (((x%MD)+MD)%MD)
#define all(V)        V.begin(),V.end()
#define Mp(a,b)       make_pair(a,b)
#define gaws(a,b)     (((b-a+1LL)*(a+b))/2LL)
#define vvi           vector<vector<int>>
#define setprec(x)    fixed << setprecision(x)
#define lid           u<<1
#define rid           (u<<1)|1
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll N = 1e5 + 10,SQ=320,LOG=31, MD = 1e9 + 7;
const ll inf = 2e9 , riz = -2e9;
int n , arr[N];
bool bt[N][LOG];
int ps[N][LOG][2],ps2[N][LOG][2];
int get(int x,int i){
    int a = ps[n][x][0];
    a -= ps[i-1][x][0];
    a -= ps2[i+1][x][0];
    return a;
}
int32_t main() {
    migmig
    int t;
    cin >> t;
    while(t--){
        cin >> n ;
        loop(i,1,n+1) cin >> arr[i];
        loop(i,0,n+3){
            loop(j,0,LOG){
                loop(k,0,2){
                    ps[i][j][k] = 0;
                    ps2[i][j][k] = 0;
                }
                bt[i][j] = 0;
            }
        }
        loop(i,1,n+1){
            loop(j,0,LOG){
                if(arr[i]&(1<<j)) bt[i][j] = 1;
                else bt[i][j] = 0;
            }
        }
        loop(j,0,LOG){
            ps[1][j][bt[1][j]] = 1;
            ps[1][j][bt[1][j]^1] = 0;
            int c0 = 0 ,c1 = 0 ;
            if(bt[1][j]) c1 = 1;
            else c0 = 1;
            loop(i,2,n+1){
                ps[i][j][0] = ps[i-1][j][0];
                ps[i][j][1] = ps[i-1][j][1];
                ps[i][j][bt[i][j]]++;
                if(bt[i][j]){
                    ps[i][j][0] += c1;
                    ps[i][j][1] += c0;
                    swap(c0,c1);
                    c1++;
                }
                else{
                    ps[i][j][0] += c0;
                    ps[i][j][1] += c1;
                    c0++;
                }
            } 
            ps2[n][j][bt[n][j]] = 1;
            ps2[n][j][bt[n][j]^1] = 0;
            c0 = 0;
            c1 = 0;
            if(bt[n][j]) c1 = 1;
            else c0 = 1;
            loop2(i,n-1,1){
                ps2[i][j][0] = ps2[i+1][j][0];
                ps2[i][j][1] = ps2[i+1][j][1];
                ps2[i][j][bt[i][j]]++;
                if(bt[i][j]){
                    ps2[i][j][0] += c1;
                    ps2[i][j][1] += c0;
                    swap(c0,c1);
                    c1++;
                }
                else{
                    ps2[i][j][0] += c0;
                    ps2[i][j][1] += c1;
                    c0++;
                }
            }
        }
        int ans = 0;
        loop(i,1,n+1){
            int x = log2(arr[i]);
            ans += get(x,i);
        }
        cout << ans << endl;
    }    
    return 0;
}