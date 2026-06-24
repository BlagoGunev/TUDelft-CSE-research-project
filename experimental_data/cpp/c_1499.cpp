#include <bits/stdc++.h>

using namespace std;



#define int long long

#define double long double

int32_t N = 1e5 + 5;

int32_t mod = 1e9 + 7;



void solveCase()

{

    int n=0;

    cin >> n;

    vector<int> a(n);

    for(int &i:a)

        cin >> i;

    

    int ans = LLONG_MAX;

    int mn1=1e9, mn2=1e9;

    int cnt1=0, cnt2=0, s=0;

    

    for(int i=0; i<n; i++)

    {

        if(i%2 == 0)

        {

            mn1 = min(mn1, a[i]);

            cnt1++;

        }

        else

        {

            mn2 = min(mn2, a[i]);

            cnt2++;

        }

        

        s += a[i];

        int cost1 = mn1*(n-cnt1);

        int cost2 = mn2*(n-cnt2);

        ans = min(ans, s+cost1+cost2);

    }

    

    cout << ans << "\n";

}

 

int32_t main()

{

    ios::sync_with_stdio(false), cin.tie(NULL);

    int t = 0;

    cin >> t;

    while (t--)

        solveCase();

};