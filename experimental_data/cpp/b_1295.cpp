#include <bits/stdc++.h>

#define int long long int

#define endl "\n"

#define pb push_back

#define pf push_front

#define ff first

#define ss second

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);

#define cnt1(x) __builtin_popcountll(x)



using namespace std;



const int mod = 1e9 + 7;

const int N = 1e15;



signed main()

{

    fastio()



    int t;

    cin >> t;



    while (t--)

    {

        int n, x;

        cin >> n >> x;



        string s;

        cin >> s;



        vector<int> f0(n, 0), f1(n, 0);

        s[0] == '1' ? f1[0] = 1 : f0[0] = 1;

        for (int i = 1; i < n; i++) f0[i] = f0[i - 1] + (s[i] == '0' ? 1 : 0), f1[i] = f1[i - 1] + (s[i] == '1' ? 1 : 0);



        int ans = (x == 0 ? 1 : 0);

        for (int i = 0; i < n; i++)

        {

            if (x == f0[i] - f1[i] && f0[n - 1] == f1[n - 1]) ans = N;

            else if (f0[n - 1] != f1[n - 1])

            {

                int y = (x - f0[i] + f1[i]) / (f0[n - 1] - f1[n - 1]);

                if (y >= 0 && y * (f0[n - 1] - f1[n - 1]) == x - f0[i] + f1[i]) ans++;

            }

        }



        cout << (ans >= N ? -1 : ans) << endl;

    }



    return 0;

}