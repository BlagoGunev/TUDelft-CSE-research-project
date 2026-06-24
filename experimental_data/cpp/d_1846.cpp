// JAI BAJARANG BALI
// ThinkTank30

// give me some sunshine, give me some rain, give me another chance to grow up once again

#include <bits/stdc++.h>

#define int long double
#define endl "\n"
#define all(s) (s).begin(), (s).end()
#define vi vector<int>
#define pb push_back
#define sz(x) ((int)(x).size())
#define set_bits __builtin_popcountll

const int MOD =1e9+7;

using namespace std;

//vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
//int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

void solve(){
    int n,d,h;
    cin>>n>>d>>h;
    vi y(n);
    for(auto&it : y){
        cin>>it;
    }
    int ans =d*h*0.5;
    for (int i=0;i<n-1;i++){
       if(y[i+1]>=y[i]+h){
        ans+=0.5*h*d;
       }
       else{
         int d2 = d * (y[i] + h - y[i + 1]) / h;
            int nh = y[i + 1] - y[i];
                ans += (d + d2) / 2.0 * nh;
       }
    }
    cout<<setprecision(6)<<fixed<<ans<<endl;
}
signed main (){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    int tt=1;
    cin>>tt;
    while(tt--){
    solve();
    }

}