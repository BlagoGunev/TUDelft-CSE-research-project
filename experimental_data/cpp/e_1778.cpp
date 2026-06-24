//****************************Template Begins****************************//



// Header Files

#include<iostream>

#include<iomanip>

#include<algorithm>

#include<vector>

#include<utility>

#include<set>

#include<unordered_set>

#include<list>

#include<iterator>

#include<deque>

#include<queue>

#include<stack>

#include<set>

#include<bitset>

#include<random>

#include<map>

#include<unordered_map>

#include<stdio.h>

#include<complex>

#include<math.h>

#include<cstring>

#include<chrono>

#include<string>

#include "ext/pb_ds/assoc_container.hpp"

#include "ext/pb_ds/tree_policy.hpp"

// Header Files End



using namespace std;

using namespace __gnu_pbds;

template<class T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<typename T> 

using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;



template<class key, class value, class cmp = std::less<key>>

using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(k)  returns iterator to kth element starting from 0;

// order_of_key(k) returns count of elements strictly smaller than k;



#define DIVYA ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll int

#define umap unordered_map

#define uset unordered_set

#define lb lower_bound

#define ub upper_bound

#define fo(i,a,b) for(i=a;i<=b;i++)

#define all(v) (v).begin(),(v).end()

#define all1(v) (v).begin()+1,(v).end()

#define allr(v) (v).rbegin(),(v).rend()

#define allr1(v) (v).rbegin()+1,(v).rend()

#define sort0(v) sort(all(v))

typedef pair<int, int> pii;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef pair<ll, ll> pll;

#define sz(x) (ll)x.size()

#define pb push_back

#define ppb pop_back

#define mkp make_pair

#define inf 1000000000000000005

const ll mod = 1e9 + 7;



ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}



ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}



ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}



ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}



ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}



ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}

//****************************Template Ends*******************************//





//**************binary lifting begins**************

vector<vll>adj;

vector<vll>parent;

vll depth;

ll mx_pow = 20;// change this as required(max value is 2^(mx_pow-1), not 2^(mx_pow))

void assign_parent(ll curr_node, ll par)

{

    for (auto x : adj[curr_node])

    {

        if (x == par)continue;

        depth[x] = 1 + depth[curr_node];

        parent[x][0] = curr_node;

        assign_parent(x, curr_node);

    }

}

// call the following function in main :

void binary_lifting(ll n)

{

    ll i, j, temp;

    parent.assign(n + 1, vll(mx_pow, 0));

    depth.assign(n + 1, 0);

    assign_parent(1, -1);



    for (j = 1; j < mx_pow; j++)

    {

        for (i = 1; i <= n; i++)

        {

            temp = parent[i][j - 1];

            parent[i][j] = parent[temp][j - 1];

        }

    }



}

//resubmit

//****************binary lifting ends****************



//*******************lca begins**********************



// comment the following function if you only need binary lifting and not lca

ll get_lca(ll u, ll v)

{

    if (depth[u] < depth[v])swap(u, v);

    ll jump = depth[u] - depth[v];

    ll i, j;

    for (j = 0; j < mx_pow; j++)

    {

        if (jump & (1 << j))

        {

            u = parent[u][j];

        }

    }

    if (u == v)return u;

    for (j = mx_pow - 1; j >= 0; j--)

    {

        if (parent[u][j] != parent[v][j])

        {

            u = parent[u][j];

            v = parent[v][j];

        }

    }

    return parent[u][0];

}

//********************lca ends***********************



ll get_distance(ll u, ll v)

{

    ll lc = get_lca(u, v);

    return depth[u] + depth[v] - 2 * depth[lc];

}



ll get_parent(ll u, ll k)

{



    ll j;

    ll curr = u;

    for(j = mx_pow-1;j>=0;j--)

    {

        if((k&(1<<j)) > 0)

        {   

            curr = parent[curr][j];

        }

    }

    return curr;

}







ll N = 30;

void insert(vll &basis, ll mask)

{

    ll i,j;

    for(j = N-1;j>=0;j--)

    {

        if((mask&(1<<j)) == 0)continue;

        if(basis[j] == -1)

        {

            basis[j] = mask;

            return;

        }

        mask^=basis[j];

    }

}



vll in_time,out_time;

vector<vll>subtree_basis;

vll a;

ll timee;

vector<vll> prefix_basis,suffix_basis;

vll euler;



void dfs(ll u, ll par)

{

    in_time[u] = ++timee;

    euler.pb(u);

    insert(subtree_basis[u], a[u]);

    for(auto x : adj[u])

    {

        if(x == par)continue;

        dfs(x,u);

        ll j;

        for(j = N-1;j>=0;j--)

        {

            if(subtree_basis[x][j] != -1)

            {

                insert(subtree_basis[u], subtree_basis[x][j]);

            }

        }

    }

    out_time[u] = timee;

}



ll get_max(vll &basis)

{

    ll j;

    ll ans = 0;

    for(j = N-1;j>=0;j--)

    {

        if((ans&(1<<j)))

        {

            //nothing

        }

        else

        {

            if(basis[j] != -1)

            {

                ans^=basis[j];

            }

        }

    }

    return ans;

}





int main() {

    DIVYA;

    ll t, n, i, j, ans, temp, sum;

    string sans;

    t = 1;

    cin >> t;

    while (t--)

    {

        sans = "NO";

        ans = temp = sum = 0;

        cin >> n;

        timee = -1;

        a.assign(n+1,0);

        in_time.assign(n+1,0);

        out_time.assign(n+1,0);

        subtree_basis.assign(n+1,vll(N,-1));

        adj.assign(n+1,{});

        prefix_basis.assign(n+1,vll(N,-1));

        suffix_basis.assign(n+1,vll(N,-1));



        fo(i,1,n)

        {

            cin>>a[i];

        }

        fo(i,1,n-1)

        {

            ll u,v;

            cin>>u>>v;

            adj[u].pb(v);

            adj[v].pb(u);

        }

        binary_lifting(n);

        euler.clear();

        dfs(1,0);



        vll curr_basis(N,-1);



        fo(i,0,n-1)

        {

            insert(curr_basis, a[euler[i]]);

            prefix_basis[i] = curr_basis;

        }



        curr_basis.assign(N,-1);



        for(i = n-1;i>=0;i--)

        {

            insert(curr_basis, a[euler[i]]);

            suffix_basis[i] = curr_basis;

        }



        ll q;

        cin>>q;

        ll iter;

        fo(iter,1,q)

        {

            ll r,v;

            cin>>r>>v;

            if(r == v)

            {

                ans = get_max(prefix_basis[n-1]);

            }

            else

            {

                ll lc = get_lca(r,v);

                if(lc == v)

                {

                    ll diff = depth[r] - depth[v] - 1;



                    ll x = get_parent(r,diff);



                    ll pre,suff;

                    pre = in_time[x] - 1;



                    suff = out_time[x] + 1;



                    vll curr_basis = prefix_basis[pre];



                    for(j = N-1;j>=0;j--)

                    {

                        if(suffix_basis[suff][j] != -1)

                        {

                            insert(curr_basis, suffix_basis[suff][j]);

                        }

                    }



                    ans = get_max(curr_basis);



                }

                else

                {

                    ans = get_max(subtree_basis[v]);

                }

            }

            cout<<ans<<"\n";

        }



    }

    return 0;

}