#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int h, n;
        cin >> h >> n;
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
        vector<long long int> damage(n), cool(n);
        for (long long int i = 0; i < n; i++)
        {
            cin >> damage[i];
        }
        for (long long int i = 0; i < n; i++)
        {
            cin >> cool[i];
        }
        for (long long int i = 0; i < n; i++)
        {
            pq.push({0, i});
        }

        long long int turn = 0;
        while (h > 0 && !pq.empty())
        {

            if (pq.top().first > turn)
            {
                turn = pq.top().first;
            }

            while (!pq.empty() && pq.top().first <= turn)
            {
                auto po = pq.top();
                pq.pop();
                h -= damage[po.second];
                if (h <= 0)
                    break;
                pq.push({turn + cool[po.second], po.second});
            }
            turn++;
        }
        cout << turn << endl;
    }
    return 0;
}