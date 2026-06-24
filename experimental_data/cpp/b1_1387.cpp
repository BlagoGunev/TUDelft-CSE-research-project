#include<bits/stdc++.h>

#define int long long

#define pii pair<int,int>

#define fi first

#define se second

/*#pragma GCC tarGet ("avx2")

#pragma GCC optimization ("O3")

#pragma GCC optimization ("unroll-loops")

#pragma GCC optimize("Ofast")

#pragma GCC tarGet("avx,avx2,fma")*/

using namespace std;

using ll = long long;

const int mod = 1e9+7;

const int maxN = 2e5+5;

const int N = 2e6;

const ll infty = 1e16;

void InputFile()

{

    freopen("test.inp","r",stdin);

    freopen("test.out","w",stdout);

    //freopen("test.out","r",stdin);

}



int n;

int x[maxN],y[maxN];

vector<int> adj[maxN];

int trace[maxN];

int dp[maxN][2];

int hm[maxN];



void Read()

{

    cin >> n;

    for(int i = 1; i < n; i++)

    {

        cin >> x[i] >> y[i];

        adj[x[i]].push_back(y[i]);

        adj[y[i]].push_back(x[i]);

    }

    for(int i = 0; i <= n; i++)

    {

        dp[i][0] = dp[i][1] = mod;

        hm[i] = i;

    }

}



void DFS(int u,int p)

{

    dp[u][0] = 0;

    dp[u][1] = 0;

    int leaf = 1;



    int mxd = mod;

    int id = -1;



    int rt = 0;



    for(int v : adj[u])

    {

        if(v == p) continue;

        DFS(v,u);

        leaf = 0;

        dp[u][0] += dp[v][1];

        dp[u][0] = min(dp[u][0],mod);



        dp[u][1] += min(dp[v][1],dp[v][0] + 2);

        if(dp[v][0] + 2 <= dp[v][1]) rt = 1;

    }



    if(leaf) dp[u][1] = mod;

    else if(!rt)

    {

        dp[u][1] += 2;

    }

}



void Trace(int u,int t,int p)

{

    int rt = 0;

    for(int v : adj[u])

    {

        if(v == p) continue;

        if(t == 0)

        {

            Trace(v,1,u);

        }

        else

        {

            if(dp[v][0] + 2 <= dp[v][1])

            {

                rt = 1;

                Trace(v,0,u);

                swap(hm[u],hm[v]);

            }

            else

            {

                Trace(v,1,u);

            }

        }

    }



    if(!rt && t == 1)

    {

        for(int v : adj[u])

        {

            if(v == p) continue;

            swap(hm[u],hm[v]);

            break;

        }

    }

}



void Solve()

{

    DFS(1,0);

    Trace(1,1,0);

    cout << dp[1][1] <<'\n';

    for(int i = 1; i <= n; i++)

        cout << hm[i] <<' ';

}



int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    //InputFile();

    //int sub_type;

    //cin >> sub_type;

    //Sieve();

    //Prepare();

    int test;

    //cin >> test;

    test = 1;

    while(test--)

        //for(int prc = 1; prc <= test; prc++)

    {

        Read();

        Solve();

        //Debug();

    }

}