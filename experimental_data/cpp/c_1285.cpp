/*----------------------------------

    //हरे कृष्ण - राधे राधे

    Author:    Arnab Ghosh

-----------------------------------*/

#pragma GCC optimize("O3,unroll-loops")



#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;





#define endl '\n'

#define sz(x) (int)(x).size()

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

const long long mod = 1000000007;

const long long mod1 = 998244353;







using ll = long long; 

using ld = long double;

template<class T> using minpq =  priority_queue<T, vector<T>, greater<T>>;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update >; 

// find_by_order(k)  returns iterator to kth element starting from 0

// order_of_key(k) returns count of elements strictly smaller than k //less for ascending //greater for decending   //less_equal/greater_equal stores duplicate elements.

//queue -> push, front, back, pop 

//deque -> push_back, push_front, pop_back, pop_front, front, back







template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>istream& operator >> (istream &is, T_container &v) {for(T &x : v) is >> x; return is;}

#ifdef __SIZEOF_INT128__

ostream& operator << (ostream &os, __int128 const& value){static char buffer[64];int index = 0;__uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;if (value < 0)     os << '-';else if (T == 0)    return os << '0';for(; T > 0; ++index){    buffer[index] = static_cast<char>('0' + (T % 10));    T /= 10;}    while(index > 0)    os << buffer[--index];return os;}

istream& operator >> (istream& is, __int128& T){static char buffer[64];is >> buffer;size_t len = strlen(buffer), index = 0;T = 0; int mul = 1;if (buffer[index] == '-')    ++index, mul *= -1;for(; index < len; ++index)    T = T * 10 + static_cast<int>(buffer[index] - '0');T *= mul;    return is;}

#endif

template<typename A, typename B> 

ostream& operator<<(ostream &os, const pair<A, B> &p){ return os << '(' << p.first << ", " << p.second << ')';}

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator << (ostream &os, const T_container &v) {for (const T &x : v) os<< x << " "; return os;}

template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){static priority_queue<P, Q, R> U;U = M;out << "{ ";while(!U.empty())    out << U.top() << " ", U.pop();return (out << "}");}

template<class P> ostream& operator << (ostream& out, queue<P> const& M){static queue<P> U;U = M;out << "{"; string sep;while(!U.empty()){    out << sep << U.front(); sep = ", "; U.pop();}return (out << "}");}

 

#ifndef ONLINE_JUDGE

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>

void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}

template <typename Arg1, typename... Args>

void __f(const char* names, Arg1&& arg1, Args&&... args){int count_open = 0, len = 1;for(int k = 1; ; ++k){   char cur = *(names + k);   count_open += (cur == '(' ? 1 : (cur == ')' ? -1: 0));   if (cur == ',' && count_open == 0){      const char* comma = names + k;      cerr.write(names, len) << " : " << arg1 << " | ";      __f(comma + 1, args...);      return;   }   len = (cur == ' ' ? len : k + 1);}}

#else

    #define debug(...) 1

#endif





template<typename... T>

void pr(T&&... args) {

    ((cout << args << " "), ...);

    cout << '\n';

}

template<typename... T>

void prln(T&&... args) {

    ((cout << args << '\n'), ...);

}



/*---------------------------------------------------------------------------------*/









void solve() {

    ll x;

    cin >> x;



    ll ans;

    for(ll i = 1; i * i <= x; i++) {

        if(x % i == 0 && lcm(i, x/i) == x) {

            ans = i;

        }

    }



    pr(ans, x / ans);

}



        

int main() 

{  

#ifndef ONLINE_JUDGE

    freopen("error.txt", "w", stderr);

#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1; 

    // cin >> tt;

    for(int tc = 1; tc <= tt; tc++) {

        solve();

        cerr << "-----------" << '\n';

    }

}