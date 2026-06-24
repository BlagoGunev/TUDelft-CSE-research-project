#include "bits/stdc++.h"

using namespace std;

#define pb push_back

#define ff first

#define ss second

#define endl "\n" 

#define MOD 998244353

#define int long long

#define double long double

#define sz(x) ((int)(x).size())

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define what_is(x) cerr << #x << " is " << x << endl;

#ifdef LOCAL

    #include "debug.h"

#else

    #define debug(x...) void(37)

    #define showarr(x) void(37)

#endif

const int N=200005;

const long long INF = LLONG_MAX;

const int INF2=(int)1e18;

const int LOG=20;

typedef pair<int,int> pii;

typedef tuple<int,int,int> tp;

typedef priority_queue<pii,vector<pii>,greater<pii>> min_pq;

typedef priority_queue<pii> max_pq;

typedef long long ll;

//sunlari dusun//

/*

 * kodu kisaltcak  fonksiyon

 * cevaba binary search ya da normal bs

 * segment tree / sparse table

 * stack

 * teklik ciftlik

 * precomputation

 * EN ONEMLISI OVERKILLEME

 * edge case dusunr

 * constraintlere bak

 * indisleri kontrol et 

 * dp

 * greedy

 * sorting

 * dfs bfs

 * sieve

*/

void solve()

{

    int n,d;cin >> n >> d;

    vector<bool> vis(n+1,0);

    queue<pii> q;

    int cnt=0;

    for(int i=0;i<n;i++)

    {

       int a;

       cin >> a;

       if(a==0)

       {

        vis[i]=1;

        q.push({i,0});

       }

    }

    while(!q.empty())

    {

        pii cur=q.front();

        q.pop();

        cnt=max(cnt,cur.ss);

        if(vis[(cur.ff+n-d)%n]==0)

        {

            vis[(cur.ff+n-d)%n]=1;

            q.push({(cur.ff+n-d)%n,cur.ss+1});

        }

    }

    for(int i=0;i<n;i++)

    {

        if(vis[i]==0)

        {

            cout << "-1\n";

            return;

        }

    }

    cout << cnt << endl;

}



int32_t main(){

   



     cin.tie(0); ios::sync_with_stdio(0);

     cout << fixed <<  setprecision(15);

 int t=1;cin>> t;

 

 while(t--) solve();

 

 return 0;

}