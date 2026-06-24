#include <bits/stdc++.h>

#include <ext/random>

using namespace std;



mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define ld long double

#define int long long

#define nl "\n"

#define F first

#define S second

#define Fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

#define no cout << "NO" << endl

#define yes cout << "YES" << endl

#define pb push_back

#define all(m) m.begin(), m.end()

#define rep(i, ct, xx) for (int i = ct; i < xx; i++)

#define in(a) for(int i = 0; i<a.size(); i++) cin>>a[i];

#define out(a) for(int i = 0; i<a.size(); i++) cout<<a[i]<<" ";

#define fin(a) cout<<a<<"\n"; return

const int N = 1e5 + 10;



vector<string> vec_splitter(string ans)

{

    ans += ',';

    vector<string> res;

    while (!ans.empty())

    {

        res.push_back(ans.substr(0, ans.find(',')));

        ans = ans.substr(ans.find(',') + 1);

    }

    return res;

}

void debug_out(vector<string> __attribute__((unused)) args,__attribute__((unused)) int in,__attribute__((unused)) int LINE_NUM)

{

    cerr << endl;

}

template <typename Head, typename... Tail>

void debug_out(vector<string> args, int in, int LINE_NUM, Head H, Tail... T)

{

    if (in > 0)

        cerr << ", ";

    else

    cerr << "Line(" << LINE_NUM << ") ";

    stringstream ss;

    ss << H;

    cerr << args[in] << " = " << ss.str();

    debug_out(args, in + 1, LINE_NUM, T...);

}

#ifndef ONLINE_JUDGE

#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)

#else

#define debug(...) 42

#endif

void Solve();

int32_t main()

{

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    auto begin = std::chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);

    cin.tie(0); cout.tie(0); 

    // int T;

    // cin>>T;

    // while(T--)

    // {

        Solve();

    // }

    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms\n";

}



void Solve(){

    

    int n;

    cin>>n;

    int a[n];

    rep(i,0,n)cin>>a[i];

    int x=1e10;

    int gc = a[0];

    rep(i,0,n-1)

    {

        int lc = (a[i] * a[i+1]) / (__gcd(a[i],a[i+1]));

        x = min(lc,x);

    }

    int suffgc[n];

    suffgc[n-1]=a[n-1];

    for(int i=n-2;i>=0;i--)

    {

        suffgc[i] = __gcd(suffgc[i+1],a[i]);

    }

    int ans = (a[0]*a[1])/(__gcd(a[0],a[1]));

    rep(i,0,n-1)

    {

        ans = __gcd(ans,(a[i]*suffgc[i+1])/(__gcd(a[i],suffgc[i+1])));

    }

    cout<<ans<<endl;    

   

}