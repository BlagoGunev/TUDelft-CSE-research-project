#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1000000007;

const int N = 1e6 + 10;

#define pb push_back



//#define int ll

#define vi vector<int>

#define vll vector<ll>

#define all(a) a.begin(), a.end()

#define loop(a, k, n) for (long long a = k; a < n; a++)

template <typename T>

void input(vector<T> &arr, int n)

{

    loop(i, 0, n) cin >> arr[i];

}

template <typename T>

void input(T *arr, int n)

{

    loop(i, 0, n) cin >> arr[i];

}

template <typename T>

void show(T *arr, int n)

{

    for (int i = 0; i < n; i++)

    {

        cout << arr[i] << " ";

    }

    cout << "\n";

}

template <typename T>

void show(vector<T> &arr, int n)

{

    for (int i = 0; i < n; i++)

    {

        cout << arr[i] << " ";

    }

    cout << "\n";

}

unsigned countBits(unsigned int number)

{



    // log function in base 2

    // take only integer part

    return (int)log2(number) + 1;

}



int lowerbound(vector<ll> nums, int target)

{

    int l = 0, r = nums.size() - 1, m = 0;

    while (l < r)

    {

        m = (l + r) / 2;

        if (nums[m] < target)

            l = m + 1;

        else

            r = m;

    }

    // if (nums[r] <= target)

    //     return r;

    // else

    //     return r - 1;

    return r;

}



// Size of integer

ll intsize(ll a)

{

    return trunc(log10(a)) + 1;

}



bool p2(int x)

{

    /* First x in the below expression is for the case when x is 0 */

    return x && (!(x & (x - 1)));

}

/////////////////////////////////////////////////////



int power(int x, int y)

{



    int res = 1;



    while (y)

    {



        if (y % 2 == 1)

            res = (res * x) % mod;



        y = y >> 1;



        x = (x * x) % mod;

    }

    return res % mod;

}



int leftmost(int n)

{



    // Initializing the position bit to 1

    int pos = 0;

    while (n > 0)

    {

        n = n >> 1;

        pos++;

    }

    return pos;

}

// bool prime[N];

// // unordered_map<ll,int> p;

// vector<int> P;

// void sieve()

// {



//     for (int i = 2; i * i < N; i++)

//     {

//         if (prime[N] == 0)

//         {

//             for (int j = i * i; j < N; j += i)

//             {

//                 prime[j] = 1;

//             }

//         }

//     }

//     for (ll i = 2; i < N; i++)

//     {

//         if (prime[i] == 0)

//         {

//             P.pb(i);

//         }

//     }

// }

void subtree_count(int src, int par, vector<int> &cnt, vector<vector<int>> &graph)

{

    for (auto i : graph[src])

    {

        if (i != par)

        {



            subtree_count(i, src, cnt, graph);

            cnt[src] += cnt[i];

        }

    }

}



bool vowel(char c)

{

    string vow = "aeiou";

    for (int i = 0; i < 5; i++)

    {

        if (c == vow[i])

            return true;

    }

    return false;

}



bool bipartite(int src, int p, vi &color, vi *graph)

{

    if (color[src] == -1)

        color[src] = 1;



    for (auto i : graph[src])

    {

        if (i == p)

            continue;

        if (color[i] == -1)

        {

            color[i] = 1 - color[src];

            if (!bipartite(i, src, color, graph))

                return false;

        }

        else if (color[i] == color[src])

        {

            return false;

        }

    }



    return true;

}

const int T = 2e5 + 10;

int treeX[T], treeY[T];

int n, q;

int lobit(int i)

{

    return i & -i;

}

int query_fenwick_tree(int x, int *tree)

{

    int ans = 0;

    for (int i = x; i; i -= lobit(i))

    {

        ans += tree[i];

    }

    return ans;

}

void update_fenwick_tree(int x, int val, int *tree)

{

    for (int i = x; i <= n; i += lobit(i))

    {

        tree[i] += val;

    }

}

int binaryexpo(int a, int b)

{

    int ans = 1;

    while (b > 0)

    {

        if (b & 1)

            ans = (ans * a);



        a = a * a;

        b >>= 1;

    }

    return ans;

}



ll get_sqr(int n)

{

    ll x = sqrt(n);

    if (x*x== n)

        return n;

    else

        return (x+ 1) * (x+ 1);

}

void f(vll &ans, ll n)

{

    if (n == 0)

        return;

   ll x = get_sqr(n - 1);

   ll y = x - (n - 1);

   ll cnt = n;

    for (ll i = y; i < n; i++)

    {

        ans[i] = --cnt;

    }

    f(ans, y);

}

void solve()

{

    ll n;

    cin >> n;

    vector<ll> ans(n, -1);

    f(ans, n);



   show(ans, n);

}

int main()

{



    // generatePalindromes(N);

    // sort(pal.begin(), pal.end());

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t = 1;

    // sieve();

    

    cin >> t;



    while (t--)

    {

        solve();

    }

    return 0;

}