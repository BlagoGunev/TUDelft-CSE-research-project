#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef double ld;

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

int n, m;

const int mMax = 50+9;

const int nMax = 50+1+9;

int A[mMax];

ld memo[nMax][mMax][nMax];

//

ld rec1(int i, int j, int score){

    

    if(j == m-1)

    {

        return max(score, (i + A[j] - 1) / A[j] );

    }

    

    ld &ret = memo[i][j][score];

    if(ret == ret) return ret;

    ret = 0;

    

    ld cnt = 1;

    for(int k=0; k<=i; k++)

    {

        if(k != 0)

        {

            cnt *= i+1-k;

            cnt /= k;

        }

        

        ret += rec1(i-k, j+1, max(score, (k + A[j] - 1) / A[j] ) ) * cnt;

    }

    

    return ret;

}

ld rec(int i, int j, int score){

    

//    if(j == m) return i == 0? score : 0;

    

    if(j == m-1)

    {

        return max(score, (i + A[j] - 1) / A[j] );

    }

    

    ld &ret = memo[i][j][score];

    if(ret == ret) return ret;

    ret = 0;

    

    

    

    ld prob = pow( 1.0 * (m-1-j)/(m-j) , i );

    for(int k=0; k<=i; k++)

    {

        if(k != 0)

        {

            prob *= (i-k+1);

            prob /= k;

            prob /= m-1-j;

        }

        

        ret += rec(i-k, j+1, max(score, (k + A[j] - 1) / A[j] ) ) * prob;

    }

    

    return ret;

}

//

int main()

{

    read_file();

    while(scanf("%d%d", &n, &m)!=EOF)

    {

        for(int i=0; i<m; i++)

            scanf("%d", &A[i]);

        

        memset(memo, -1, sizeof memo);

        

//        ld ans = rec(n, 0, 0);

//        cout<< setprecision(25) << fixed << ans <<endl;

        

        ld ans = rec1(n, 0, 0) / pow(m, n);

        cout<< setprecision(12) << fixed << ans <<endl;

    }

}