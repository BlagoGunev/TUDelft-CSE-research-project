#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--) 
#define fast_io ios_base::sync_with_stdio(0);
#define show(x) cout<<x<<endl;
#define pret(x) cout<<x<<endl; return 0;
#define disp(x) cout<<x<<" ";
#define let(x,y) cout<<x<<" "<<y<<endl;
int mod=-1e9;
const int maxn=2e5+5;

int dist(int x, int y){
    return x != y;
}

int32_t main(){
    fast_io;
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vi v;
    for(auto it:s){
        v.emplace_back(it - 'a');
    }
    int a = t[0] - 'a';
    int b = t[1] - 'a';
    // dp[i][j] = max ans you can get if you used i ops and have j a's
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, mod));
    if(v[0] == a) {
        dp[0][1] = 0;
    }   
    else {
        dp[1][1] = 0;
        dp[0][0] = 0;
    }
    for (int i = 1; i < n; ++i)
    {
        vector<vector<int> > newdp(n + 1, vector<int>(n + 1, mod));
        // vector<vector<int> > newdp(n, vector<int>(n, mod));
        for (int ops = 0; ops < k + 1; ++ops)
        {
            for (int numberOfA = 0; numberOfA <= i + 1; ++numberOfA)
            {
                int &ans = newdp[ops][numberOfA];
                ans = dp[ops][numberOfA];
                if(a == b){
                    int d = dist(v[i], a);
                    if(numberOfA and ops - d >= 0) ans = max(ans, dp[ops - d][numberOfA - 1] + numberOfA - 1);

                }
                else{
                    //replace with a
                    int d = dist(v[i], a);
                    if(numberOfA and ops - d >= 0) ans = max(ans, dp[ops - d][numberOfA - 1]);
                
                    //replace with b
                    d = dist(v[i], b);
                    if(ops - d >= 0) ans = max(ans, dp[ops - d][numberOfA] + numberOfA);
                }
            }
        }
        dp = newdp;
        // print(dp);
        // show("-------------");
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    show(ans);
    return 0;
}