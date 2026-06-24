#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f(i,x,n) for(long long i = x; i < n; i++)
#define fr(i,x,n) for(long long i = n - 1; i >= x; i--)
#define pb push_back
#define pf push_front
#define mod 1000000007
#define endl '\n'
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef long double ld;
 
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};



int main(){
    fast_io
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin >> t;

    while(t--){

        string s;
        cin >> s;

        int n = (int) s.length();
        int ans = 0;
        if(s[0] == '_') ans++;
        f(i,0,n){
            if(s[i] == '_'){
                if(i == n - 1) ans++;
                else if(s[i + 1] == '_') ans++;
            }
        }

        if(n == 1 && s[0] == '^'){
            ans++; 
        }

        cout << ans << endl;

    }

    return 0;
}