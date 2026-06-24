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

int n, m;

#define nMax 100000+9

//

struct seg{

    int l, r;

    int i;

    bool operator< (seg oth) const{

        if(r != oth.r)

            return r < oth.r;

        return i < oth.i;

    }

    seg(){

        

    }

    seg(int l, int r, int i): l(l), r(r), i(i){

        

    }

};

seg S[nMax];

//

bool byl(seg l, seg r){

    return l.l < r.l;

}

//

int main()

{

    read_file();

    while(scanf("%d%d", &n, &m)!=EOF)

    {

        for(int i=0; i<m; i++)

        {

            int x, y;

            scanf("%d%d", &x, &y);

            x--, y--;

            swap(x, y);

            S[i] = seg(n-1-y, x, i);

//            printf("%d %d\n", n-1-y, x);

        }

        

        sort(S, S+m, byl);

        

        set <seg> st;

        vi ans;

        int ptr = 0;

        for(int i=0; i<n; i++)

        {

            while(!st.empty() && st.begin()->r < i)

                st.erase( st.begin() );

            

            while(ptr < m && S[ptr].l <= i)

            {

                if(S[ptr].r >= i)

                {

                    st.insert( S[ptr] );

                }

                ptr++;

            }

            

            if(!st.empty())

            {

                ans.PB( st.begin()->i );

                st.erase( st.begin() );

            }

        }

        

        

        int sz = ans.size();

        printf("%d\n", sz);

        for(int i=0; i<sz; i++)

            printf("%d%c", ans[i]+1, " \n"[i == sz-1]);

    }

}