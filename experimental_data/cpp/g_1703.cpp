#include <bits/stdc++.h> 

using namespace std;

 

#define ll long long int

#define ld long double

#define mod 1000000007

#define inf 1e18

#define pb push_back

#define vi vector<ll>

#define vs vector<string>

#define pii pair<ll,ll>

#define ump unordered_map

#define mp make_pair

#define pq_max priority_queue<ll>

#define pq_min priority_queue<ll,vi,greater<ll> >

#define all(n) n.begin(),n.end()

#define ff first

#define ss second

#define mid(l,r) (l+(r-l)/2)

#define bitc(n) builtin_popcount(n)

#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}

template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}

void file_i_o()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    #ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);

    #endif

}





int main(int argc, char const *argv[]) {

    file_i_o();

    //write your code here

    int t;

    cin>>t;

    while(t--){

        int n,k;

        cin>>n>>k;

        vector<ll> a(n);

        for(int i=0; i<n; i++){

            cin>>a[i];

        }

        ll ans = 0;

        ll sum = 0;

        for(int i=0; i<n; i++){

            ll use = 2, pr = sum;

            int j = i;

            while(j<n){

                if(use>1e9) break;

                pr += a[j] / use;

                use *= 2;

                j++;

            }

            ans = max(ans, pr);

            sum += a[i]- k;

        }

        ans = max(ans, sum);

        cout << ans << endl;

        



    }







    return 0;

}