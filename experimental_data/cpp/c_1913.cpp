// 07
// Oh Hm Bhi Bna Lenge !!!
#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define FAST()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

int mod = 998244353;
int M = 1e9 + 7;

#define all(X) X.begin(), X.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(a, b, i) for (int i = a; i < b; i++)
#define repR(a, b, i) for (int i = a - 1; i >= b; i--)
#define inpt(A)                        \
    for (int i = 0; i < A.size(); i++) \
    cin >> A[i]

void solve()
{
    int q;
    cin >> q;
    vector<int> arr1(30, 0);
    while (q--)
    {
        int t, val;
        cin >> t >> val;
        if (t == 1) arr1[val]++;
        else
        {
            vector<int>curr(31,0);
            int flag=1;
            rep(0, 30, i)
            {
                curr[i]+=arr1[i];
                if((val & (1<<i))  && !curr[i]){
                    flag=0;
                    break;
                }
                curr[i]-=(bool)(val & (1<<i));
                curr[i+1]+=(curr[i]/2);
            }
            cout<<(flag?"YES":"NO");
            cout<<"\n";
        }
    }
}
int32_t main()
{
    FAST();
    // fileIo();
    cout << fixed << setprecision(9);
    int TEST = 1;
    // cin >> TEST;
    while (TEST--)
    {
        solve();
        // cout << "\n";
    }
}