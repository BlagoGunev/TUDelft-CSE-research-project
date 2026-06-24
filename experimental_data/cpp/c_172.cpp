#include <bits/stdc++.h>



#define pb push_back

#define mp make_pair

#define F first

#define S second



#ifndef LOCAL

#define cerr if(0)cerr

#endif // LOCAL



using namespace std;



typedef long long ll;

typedef vector<int> vi;

typedef pair<int, int> pii;

typedef long double ld;



const ld INF = 1000000000;

const long long INFll = 1ll * INF * INF;

const long double ldINF = 1e+018;

const long double EPS = 0.000000001;

const int sdx[4] = {-1, 0, 1, 0};

const int sdy[4] = {0, 1, 0, -1};

const int MOD = 1000000007;





int main()

{

    //ios_base::sync_with_stdio(0);

//#ifdef LOCAL

   // freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

//#endif

    int n, m;

    vector < pair < pair <int, int > , int > > a;

    scanf("%d%d", &n, &m);

    vi ans(n);

    for (int i=0; i<n; i++)

    {

        int x, y;

        scanf("%d%d", &x, &y);

        a.pb(mp(mp(x, y), i));

    }

    sort(a.begin(), a.end());

    int i = 0, t = 0;

    while (i<a.size())

    {

      //  cout << t << endl;

        vector < pii > v;

        int z = 0;

        while (v.size() < m && i<a.size())

        {

            v.pb(mp(a[i].F.S, a[i].S));

            z = a[i].F.F;

            i++;

        }

        t = max(t, z);

        sort(v.begin(), v.end());

        int k = 1;

        t += v[0].F;

        ans[v[0].S] = t;

        for (int j=1; j<v.size(); j++)

            if (v[j].F != v[j-1].F)

            {

                t += 1+(k/2) + v[j].F - v[j-1].F;

                k = 1;

                ans[v[j].S] = t;

            }

            else

            {

                ans[v[j].S] = t;

                k++;

                //p = 0;

            }

        t += 1 +(k/2);

       // cout << t << endl;

        t += v[v.size()-1].F;



    }

    for (int i=0; i<n; i++)

        printf("%d ", ans[i]);

    return 0;

}