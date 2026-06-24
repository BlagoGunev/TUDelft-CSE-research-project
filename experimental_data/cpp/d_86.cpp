#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair <int, int> ii;

typedef vector <int> vi;

typedef vector <vi> vvi;

typedef vector <ii> vii;

typedef vector <vii> vvii;

#define endl '\n'

#define PB push_back

#define MP make_pair

#define OO (1000000000)         // ToDo

#define EPS (1e-9)              // ToDo

#define MOD (1000000007)        // ToDo

#define all(v) ((v).begin()),((v).end())

#define DEBUG(x) cout<< #x <<" = "<<"\""<< (x) <<"\""<<endl

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void read_file(bool outToFile = true){

#ifdef LOCAL_TEST

    freopen("in.in", "rt", stdin);

    if(outToFile)

    freopen("out.out", "wt", stdout);

#endif

}

//

int n, nq;

#define nMax 200000+9

#define vMax 1000000+1+9

int A[nMax];

int cnt[vMax];

int sqrtn;

//

struct queryy{

    int l, r, i, b;

    queryy(int nl=0, int nr=0, int ni=0, int nb=0){

        l = nl, r = nr, i = ni, b = nb;

    }

    bool operator< (queryy oth) const{

        if(b != oth.b)

            return b < oth.b;

        

        if(b&1)

            return r < oth.r;

        else

            return r > oth.r;

    }

};

queryy Q[nMax];

ll ans[nMax];

ll curans;

//

void add(int idx){

//    curans -= 1LL * cnt[ A[idx] ] * cnt[ A[idx] ] * A[idx];

//    cnt[ A[idx] ]++;

//    curans += 1LL * cnt[ A[idx] ] * cnt[ A[idx] ] * A[idx];

    

    curans += (1 + 2 * cnt[ A[idx] ]) * 1LL * A[idx];

    cnt[A[idx]]++;

}

void del(int idx){

//    curans -= 1LL * cnt[ A[idx] ] * cnt[ A[idx] ] * A[idx];

//    cnt[ A[idx] ]--;

//    curans += 1LL * cnt[ A[idx] ] * cnt[ A[idx] ] * A[idx];

    

    curans += (1 - 2 * cnt[ A[idx] ]) * 1LL * A[idx];

    cnt[A[idx]]--;

}

//

int main()

{

    read_file();

    while(scanf("%d%d\n", &n, &nq)!=EOF)

    {

        sqrtn = 1;

        while(sqrtn * sqrtn <= n)

            sqrtn++;

        sqrtn--;

        

        for(int i=0; i<n; i++)

            scanf("%d", &A[i]);

        

        for(int i=0; i<nq; i++)

        {

            int l, r;

            scanf("%d%d", &l, &r);

            l--, r--;

            Q[i] = queryy(l, r, i, l / sqrtn);

        }

        sort(Q, Q+nq);

        

        

        int curl = 0, curr = -1;

        memset(cnt, 0, sizeof cnt);

        curans = 0;

        for(int i=0; i<nq; i++)

        {

            int l = Q[i].l, r = Q[i].r;

            

            while(curr < r)

            {

                curr++;

                add(curr);

            }

            

            while(curr > r)

            {

                del(curr);

                curr--;

            }

            

            while(curl < l)

            {

                del(curl);

                curl++;

            }

            

            while(curl > l)

            {

                curl--;

                add(curl);

            }

            

            ans[ Q[i].i ] = curans;

        }

        

        for(int i=0; i<nq; i++)

            printf("%lld\n", ans[i]);

    }

}