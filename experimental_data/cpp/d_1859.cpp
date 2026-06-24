#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#define PII pair<int, int>
using namespace std;

class Compare
{

public:
    bool operator()(PII a, PII b)
    {
        return a.second < b.second;
    }
};

priority_queue<PII, vector<PII>, Compare> pq;
unordered_map<int,int>mp, ans;
unordered_set<int>norms;
vector<int>norm;
const int nmax = 2e6 + 7;
int l[nmax], r[nmax], a[nmax], b[nmax];
int v[nmax], dp[nmax];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,i,q;
        cin >> n;
        for(i=1; i<=n; i++)
        {
            cin >> l[i] >> r[i] >> a[i] >> b[i];
            norms.insert(l[i]);
            norms.insert(r[i]);
            norms.insert(a[i]);
            norms.insert(b[i]);
        }
        cin >> q;
        for(i=1; i<=q; i++)
        {
            cin >> v[i];
            norms.insert(v[i]);
        }
        for(auto it:norms)
            norm.push_back(it);
        sort(norm.begin(), norm.end());
        for(i = 0; i < norm.size(); i++)
            mp[norm[i]] = i;
        for(i = 1; i <= n; i++)
            pq.push({mp[l[i]], mp[b [i]]});
        for(i = norm.size() - 1; i >= 0; i--)
        {
            dp[i] = i;
            if(pq.size())
            {
                dp[i] = max(i, dp[pq.top().second]);
            }
            while(pq.size() && pq.top().first >= i)
                pq.pop();
            ans[norm[i]] = norm[dp[i]];
        }
        for(i=1; i<=q; i++)
            cout << ans[v[i]] << " ";
        cout << '\n';
        for(i = 0; i < norm.size(); i++)
            dp[i] = 0;
        while(pq.size())
            pq.pop();
        mp.clear(),ans.clear();
        norms.clear(), norm.clear();
        norm.resize(0);
    }
    return 0;
}