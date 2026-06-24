//Not the Best :)



#include <bits/stdc++.h>

using namespace std;



//DataTypes

using str =  string;

using ll  = long long;

using ld  = long double;

using vl  = vector<ll>;

using vd  = vector<ld>;

using vs  = vector<str>;

using vpl = vector<pair<ll,ll>>;

#define umap unordered_map

#define uset unordered_set



//Shorts

#define pus     push_back

#define pub     pop_back

#define ff       first

#define ss       second

#define dbg(x) cout<<#x<<" = "<<x<<'\n';



//Algorithms

#define sz(x)     ((ll)(x).size())

#define all(x)    x.begin(),x.end()

#define srt(x)    sort(all(x))

#define srtd(x)   sort(x.rbegin(),x.rend())

#define rev(x)    reverse(all(x));

#define Vmax(x)   *max_element(all(x))

#define Vmin(x)   *min_element(all(x))

#define Vsum(x)   accumulate(all(x),0ll)

#define lowB(v,x) *lower_bound(all(v),x) // >=x

#define upB(v,x)  upper_bound(all(v),x)-v.begin() // > x

#define ers(v,i)  v.erase(v.begin()+i) 

#define uniq(x)   x.erase(unique(all(x)),x.end())

#define NextP(x)  next_permutation(all(x))

#define PrevP(x)  prev_permutation(all(x))

#define cntB(x)   __builtin_popcountll(x)  

#define cntC(s,x) ll(count(all(s), x));



//loops

#define For(n)  for (ll i = 0; i < n; i++)

#define ForR(n) for (ll i = n-1; i >= 0; i--)

#define Forj(n) for (ll j = 0; j < n; j++)

#define For1(n) for (ll i = 1; i < n; i++)



//IO

#define nl      cout << "\n";

#define ya      cout << "YES\n";

#define na      cout << "NO\n";

#define inpt(v) For(sz(v)) cin >> v[i];

#define prt(v)  for(auto i:v) cout << i << " "; cout << "\n";



//Constants

const int M = 1e9+7; 

const int N = 2e5+5;

const ld pi = 3.141592653589793238;

const ll INF = 9e18;



ll n, a, b, c, k, m, x, y, q; str s;

 

//---------------------------------------------------------------------------------------------------------------------------------

//Let's Go :)



void solve()

{

    str s1, s2;

    cin>>n>>s1>>s2;

    vl v;

    swap(s1, s2);

    ll i=0, j=n, k=n;

    a=0;

    while(k>0){

        if (a%2==0){

            if (s1[k-1]==s2[j-1]){

                j--;

                k--;

                continue;

            }

            if (s2[i]==s1[k-1]){

                v.pus(1);

                if (s2[i]=='1') s2[i]='0';

                else s2[i]='1';

            }

            v.pus(k);

            

            a++;

        }

        else{

            if (s1[k-1]!=s2[i]){

                i++;

                k--;

                continue;

            }

            

            if (s2[j-1]!=s1[k-1]){

                v.pus(1);

                if (s2[j-1]=='1') s2[j-1]='0';

                else s2[j-1]='1';

            }

            v.pus(k);

            a++;





        }

    }

    cout<<v.size()<<" ";

    prt(v);

}



int main()

{

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t = 1;

    cin >> t;

    

    while(t--) solve();

    

    return 0;

}