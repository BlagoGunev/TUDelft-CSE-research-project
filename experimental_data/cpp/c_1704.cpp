#include <bits/stdc++.h>

     

#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2,fma")

     

//#include <ext/pb_ds/assoc_container.hpp> //required

//#include <ext/pb_ds/tree_policy.hpp> //required

     

//using namespace __gnu_pbds; //required 

using namespace std;

//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

     

// ordered_set <int> s;

// s.find_by_order(k); returns the (k+1)th smallest element

// s.order_of_key(k); returns the nber of elements in s strictly less than k

     

#define FASTIO           ios_base::sync_with_stdio(false); cin.tie(NULL); 

#define MOD              (1000000000+7) // change as required

#define pb(x)            push_back(x)

#define mp(x,y)          make_pair(x,y)

#define all(x)           x.begin(), x.end()

#define print(vec,l,r)   for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;

#define input(vec,N)     for(int i = 0; i < (N); i++) cin >> vec[i];

#define debug(x)         cerr << #x << " = " << (x) << endl;

#define leftmost_bit(x)  (63-__builtin_clzll(x))

#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros

#define set_bits(x)      __builtin_popcountll(x) 

#define pow2(i)          (1LL << (i))

#define is_on(x, i)      ((x) & pow2(i)) // state of the ith bit in x

#define set_on(x, i)     ((x) | pow2(i)) // returns integer x with ith bit on

#define set_off(x, i)    ((x) & ~pow2(i)) // returns integer x with ith bit off

      

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

     

typedef long long int ll;

     

// highly risky #defines

#define int ll // disable when you want to make code a bit faster

#define endl '\n' // disable when dealing with interactive problem



int binpow(int a, int b) {

    if (b == 0)

        return 1;

    int res = binpow(a, b / 2);

    if (b % 2)

        return ((res * res)%MOD * a)%MOD;

    else

        return (res * res)%MOD;

} 



void solve()

{

    int n,m;

    cin >> n >> m;



    vector<int> a(m);



    for(auto &e:a)

        cin >> e;



    sort(all(a));



    vector<int> len;



    for(int i=1;i<m;i++)

    {

        len.push_back(a[i]-a[i-1]-1);

    }



    if(m > 1)

    {

        len.push_back((n-a[m-1]+(a[0]-1)));

    }

    else if(m == 1)

    {

        cout << 2 << endl;

        return;

    }



    sort(all(len),greater<int>());



    int ans = 0;



    //for(auto e:len)

        //cout <<e << " ";



   // cout << endl;



    for(int i=0;i<len.size();i++)

    {

        len[i] -= (i)*4;



        //cout << len[i] << " ";

        if(len[i] == 1) 

        {

            ans++;

        }

        else if(len[i] > 1)

        {

            len[i]--;

            ans += len[i];

        }

        //else break;



        //cout << len[i] << " ";

    }



    cout << n-ans << endl;



}

     

int32_t main()

{

     

    FASTIO

     

    int t=1;

    cin >> t;

     

    for(int i=1;i<=t;i++)

    {

        //cout << "Case #" <<  i << ": " ;

        solve();

    }

        

    return 0;

        

}