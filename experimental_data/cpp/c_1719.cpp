#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//#define ll long long

#define yugant ios_base::sync_with_stdio(false); 

#define manoj cin.tie(NULL);

#define shewale cout.tie(NULL);

#define vi std::vector<int> 

#define vvi std::vector<vi> 

#define pii pair<int,int>

#define vii std::vector<pii>

#define ff first

#define ss second

#define pb push_back

#define all(x) x.begin(), x.end() 

#define rall(x) x.rbegin(),x.rend()

#define yes cout<<"YES\n";

#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

#define no cout<<"NO\n";

#define ml '\n'

#define one cout<<"1\n";

#define negone cout<<"-1\n";

#define zero cout<<"0\n";

#define out(x) cout<<x<<'\n';

#define act cout<<"acitvated\n";

#define rep(i,a,b) for (int i = a; i < b; i++)

#define copyarray(a,n) for (int i = 0; i < n; ++i){ cin>>a[i];}

#define printarray(a,n) for (int i = 0; i < n; ++i){cout<<a[i]<<' ';}

#define line cout<<'\n';

#define setBits(x) builtin_popcount(x)

#define rfor(i,a,b) for(int i = a; i >= b;i--)

#define yrn(jack) cout<<(jack  ? "YES\n" : "NO\n");

#define pri(x,y) cout<<x<<' '<<y;

#define sz(x) x.size()

const int MOD = 1e9+7;

int N = 1000000;

bool sortbysecdesc(const pair<int,int> &a,const pair<int,int> &b){

    return a.second>b.second;

}

bool isPrime(ll n){

    if (n <= 1)

        return false;

    if (n <= 3)

        return true;

    if (n % 2 == 0 || n % 3 == 0)

        return false;

    for (int i = 5; i * i <= n; i = i + 6)

        if (n % i == 0 || n % (i + 2) == 0)

            return false; 

    return true;

}

bool isPerfectSquare(long double x){

    if (x >= 0) { 

        long long sr = sqrt(x);

        return (sr * sr == x);

    }

    return false;

}

template<typename T, size_t N>

int binary_search(T (&a)[N], const T& x)

{

    int l = 0;

    int r = N - 1;

    while (l <= r) {

        int mid = l + (r-l) / 2;

        if (a[mid] == x)

            return mid;

        else if (a[mid] < x)

            l = mid + 1;

        else

            r = mid - 1;

    }

    return -1;

}



ll nCr(ll n, ll r){

    long long p = 1, k = 1;

    if (n - r < r)

        r = n - r;

    if (r != 0) {

        while (r) {

            p *= n;   

            k *= r;

            long long m = __gcd(p, k);

            p /= m;

            k /= m;

            n--;    

            r--;

        }

    }

    else

        p = 1;

    return p;

}

int binpow(int x, int y)

{

    int temp;

    if( y == 0)

        return 1;

    temp = pow(x, y / 2);

    if (y % 2 == 0)

        return temp * temp;

    else

        return x * temp * temp;

}

int kadanes(int a[], int size)

{

    int ans = INT_MIN, currsum = 0;

    for (int i = 0; i < size; i++) {

        currsum = currsum + a[i];

        if (ans < currsum)

            ans = currsum;

 

        if (currsum < 0)

            currsum = 0;

    }

    return ans;

}



bool PrimeSieve[1000005];   // 1e6+5

/*void buildSieve(){

    for(int i=2;i<=sz;i++)    PrimeSieve[i]=1;

    PrimeSieve[0]=0;// 

    PrimeSieve[1]=0;    // 1 is neither prime nor composite 

    for(int i=2;i<sz;i++){

        if(PrimeSieve[i]==0)    continue;       // the current number itself is composite 

        for(int j=2;j*i<sz;j++){

            PrimeSieve[i*j]=0;

        }

    }

}*/

//////////////////template by yogomate/////////////////////////////

ll n,m,x,ans = 0,cnt = 0; string s,s1,s2,s3,s4;

ll bs(ll l, ll h, vector<ll> wins[], ll k, ll i)

{

    if(l<=h)

    {

        ll m=(l+h)/2;

        

        if(wins[i][m]<=k){

            if(m+1<=h){

                if(wins[i][m+1]<=k){

                    return bs(m+1, h, wins, k, i);

                }else{



                    return m+1;

                }

            }else{

                return m+1;

            }

        }else{

            return bs(l, m-1, wins, k, i);

        }

    }else{

        return 0;

    }

}

void solve() {

    ll q; cin>>n>>q;

    ll larg = INT_MIN,curr_win = -1;

    ll a[n+1];

    vector<ll> rounds[n+1];

    vector<ll> wincnt(n+1,0);

    for (int i = 1; i <= n; ++i)

    {

        cin>>a[i];

        if(a[i] == n)

            larg = i-1;

    }

    if(larg==0)

        larg = 1;

    if(a[1]>a[2])

        curr_win = 1;

    else

        curr_win = 2;

    if(larg > 1){

        rounds[curr_win].pb(1);

        wincnt[curr_win]++;

    }

    for (int i = 2; i < larg; ++i)

    {

        if(a[curr_win]<a[i+1])

            curr_win = i+1;

        wincnt[curr_win]++;

        rounds[curr_win].pb(i);

    }

    while(q--){

        ll i,k;

        cin>>i>>k;

        ll j = bs(0,wincnt[i]-1,rounds,k-1,i);

        if(a[i] == n and k >= larg){

            j = k-larg+1;

        }else{

           // cout<<binary(wincnt,i,rounds,k)<<ml;

            j=bs(0,wincnt[i]-1,rounds,k,i); //bs(0, si[i]-1, wins, k, i); l , r ,wincnt[], k , curr_player  



        }

        out(j)

    }

}

signed main() {

    yugant manoj shewale

    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int _; cin>>_; 

    while(_--)

        solve();

 

    return 0;

 

}

/*

  ll binary(vector<ll> wincnt, ll player, vector<ll> rounds[], ll k){

    int ans = 0;

    ll l = 0;

    ll r = wincnt[player]-1;

    while(l <= r){

        int mid = l + (r - l) / 2;

        if(mid+1<=r){

            if(rounds[player][mid+1]<=k){

                    l = mid+1;

                }else{

                    return m+1;

                }

        }

        else{

            r = mid-1;

        }

    }

        return ans;

}

*/