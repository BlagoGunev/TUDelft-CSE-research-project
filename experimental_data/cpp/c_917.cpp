#include <bits/stdc++.h>

using namespace std;

const int L = 72;
typedef long long ll;
const ll inf = 1e18;

int x, n, m, k, pos, curr, i, j, piatra, e[L], code[1000];
vector<int> states, special;
ll M[30][L][L], aux[L][L], ans[L], aux2[L];
map<int,int> val;


void inm(ll a[L][L], ll b[L][L])
{
    int i, j, k;
    for(i=0; i<L; ++i)
        for(j=0; j<L; ++j)
        {
            aux[i][j] = inf;
            for(k=0; k<L; ++k)
                aux[i][j] = min(aux[i][j], a[i][k] + b[k][j]);
        }
    for(i=0; i<L; ++i)
        for(j=0; j<L; ++j)
            a[i][j] = aux[i][j];
}

void inm2(ll a[L], ll b[L][L])
{
    int i, j;
    for(i=0; i<L; ++i)
    {
        aux2[i] = inf;
        for(j=0; j<L; ++j)
            aux2[i] = min(aux2[i], a[j] + b[j][i]);
    }
    for(i=0; i<L; ++i) a[i] = aux2[i];
}

void move_state(int a, int b, int cost)
{
    M[0][code[a]][code[b]] = cost;
}

void create_states()
{
    int i, new_state;
    for(i=0; i < (1<<k); ++i)
        if(__builtin_popcount(i) == x)
        {
            code[i] = states.size();
            states.push_back(i);
        }

    for(auto state : states)
        if(state&1)
        {
            new_state = state>>1;
            for(i=0; i<k; ++i)
                if(!(new_state & (1<<i)))
                    move_state(state, new_state ^ (1<<i), e[i]);
        }
        else move_state(state, state>>1, 0);
}

void compute_powers()
{
    int i;
    for(i=1; i<=28; ++i)
    {
        memcpy(M[i], M[i-1], sizeof(M[i]));
        inm(M[i], M[i-1]);
    }
}

void advance(int p)
{
    for(int i=0; i<=29; ++i)
        if(p & (1<<i)) inm2(ans, M[i]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    cin.sync_with_stdio(false);

    cin >> x >> k >> n >> m;
    for(i=0; i<k; ++i) cin >> e[i];

    for(i=0; i<L; ++i)
        for(j=0; j<L; ++j)
            M[0][i][j] = inf;
    create_states();
    compute_powers();

    ll cnt = 0;
    for(i=1; i<=m; ++i)
    {
        int nr;
        cin >> piatra >> nr;
        val[piatra] = nr;
        if(piatra > n-x)
        {
            cnt += nr;
            continue;
        }
        special.push_back(piatra);
    }

    sort(special.begin(), special.end());
    special.erase( unique(special.begin(), special.end()), special.end() );

    for(i=0; i<L; ++i) ans[i] = inf;
    ans[code[(1<<x)-1]] = 0;

    pos = 1;
    for(auto curr : special)
    {
        advance(curr - pos);
        for(auto state : states)
            if(state & 1) ans[code[state]] += val[curr];
        pos = curr;
    }

    advance((n-x+1) - pos);
    cout << ans[code[(1<<x)-1]] + cnt << '\n';
    return 0;
}