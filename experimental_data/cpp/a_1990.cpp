// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

// #define _GLIBCXX_DEBUG
// #define _GLIBCXX_DEBUG_PEDANTIC

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <queue>
#include <deque>
#include <bitset>
#include <cmath>
#include <climits>
#include <unordered_map>

#define int long long
#define itn int
#define double long double
//#define endl '\n'
#define p_b push_back
#define fi first
#define se second
#define pii std::pair<int, int>
#define oo LLONG_MAX
#define big INT_MAX
#define elif else if

using namespace std;

const double pi=3.14159265359;
const int mod=998244353;
//const int mod=1000000007;

int input()
{
    int x;
    cin>>x;
    return x;
}

void solve()
{

    int n;
    cin>>n;
    map<int, int>cnt;
    for(int i=0;i<n;i++)
    {
        cnt[input()]++;
    }
    for(auto [x, y]:cnt)
    {
        if(y%2)
        {
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";

}

int32_t main()
{

//    srand(time(0));

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//        freopen("network.in", "r", stdin);
//        freopen("out", "w", stdout);

    int t=1;
    cin>>t;
    while(t--)
    {

        solve();

        cout<<endl;
        //cout<<endl;
    }


}