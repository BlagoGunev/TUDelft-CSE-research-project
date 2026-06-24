#define RAGHAV_PATEL ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);



#include <bits/stdc++.h>

#include <algorithm>

using namespace std;



#define int long long int

void solve()

{

    int n;

    cin >> n;

    vector<int> v(n);

    vector<int> fv((2 * n) + 1);

    for (int i = 0; i < n; i++)

    {

        cin >> v[i];

        fv[v[i]] = 1;

    }

    vector<int> pq;



    for (int i = 1; i <= 2 * n; i++)

    {

        if (fv[i] == 0)

            pq.push_back(i);

    }

    vector<int> ans;

    int flag = 0;

    for (int i = 0; i < n; i++)

    {

        ans.push_back(v[i]);

        int temp = v[i];

        while (true)

        {

            int x = upper_bound(pq.begin(), pq.end(), temp) - pq.begin();

            if (x == pq.size())

            {

                cout << -1 << "\n";

                return;

            }

            else if (fv[pq[x]] == 1)

                temp=pq[x];

            else

            {

                ans.push_back(pq[x]);

                fv[pq[x]] = 1;

                break;

            }

        }

    }



    for (int i = 0; i < ans.size(); i++)

        cout << ans[i] << " ";

    cout << "\n";

}



signed main()

{

    RAGHAV_PATEL

    int t, i;

    cin >> t;

    // t = 1;



    while (t)

    {

        solve();

        t--;

    }

}



/*

 int l = ans.size();

            while(l>=0&&ans[l]==0)

                l--;

*/