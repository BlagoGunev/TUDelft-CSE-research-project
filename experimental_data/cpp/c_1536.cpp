#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define dl double long

using namespace std;

const int N = 1e5 + 7;
const long long mod = 998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
        int n;
        string s;
        cin >> n >> s;
        int A = 0, B = 0;
        map<int, int> d[n + 1];
        for(int i = 0; i < n; i++){
                A += (s[i] == 'D');
                B += (s[i] == 'K');
                if(min(A, B) == 0)cout << i + 1 << " ";
                else{
                        cout << ++d[A / __gcd(A, B)][B / __gcd(A, B)] << " ";
                }
        }
        cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}