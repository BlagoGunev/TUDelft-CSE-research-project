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

#define MOD (1000000009)        // ToDo

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

#define nMax 100000+9

//

// UF stuff begin

//

int rep[nMax];

void init(){

    for(int i=0; i<n; i++)

        rep[i] = i;

}

int find_rep(int i){

    if(i == rep[i])

        return i;

    else

        return rep[i] = find_rep( rep[i] );

}

bool join(int i, int j){

    i = find_rep(i);

    j = find_rep(j);

    

    if(i == j) return false;

    

    rep[j] = i;

    return true;

}

//

// UF stuff end

//

int main()

{

    read_file();

    while(scanf("%d%d", &n, &m)!=EOF)

    {

        init();

        

        int ans = 1;

        for(int itr=0; itr<m; itr++)

        {

            int u, v;

            scanf("%d%d", &u, &v);

            u--, v--;

            

            if(!join(u, v))

                ans = ans + ans, ans %= MOD;

            

            printf("%d\n", ans - 1);

        }

    }

}