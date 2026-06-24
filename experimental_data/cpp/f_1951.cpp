#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second
#define pb push_back

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n=0;

    void reset(int n)
    {
        this->n=n;
        bit.assign(n,0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

FenwickTree fen;

int inv(const vector<int>&p)
{
    fen.reset(p.size());
    int res=0;
    for(int i=sz(p)-1;i>=0;i--)
    {
        res+=fen.sum(p[i]-1);
        fen.add(p[i],1);
    }
    return res;
}

vector<int> mul(const vector<int>&q,const vector<int>&p)
{
    vector<int> res(p.size());
    for(int i=0;i<p.size();i++)
        res[i]=q[p[i]];
    return res;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> p(n);
        for(int i=0;i<n;i++)
            cin>>p[i],p[i]--;
        int lo=0,hi=n*(n-1)/2;
        auto gen=[&](int mi)
        {
            vector<int> q(n);
            int left=mi;
            for(int i=0;i<n;i++)
            {
                if(left>=n-i-1)
                    q[i]=n-i-1,
                            left-=n-i-1;
                else
                {
                    q[i]=left;
                    i++;
                    for(int cur=0;i<n;i++,cur++)
                    {
                        if(cur==left)
                            cur++;
                        q[i]=cur;
                    }
                }
            }
//            assert(inv(q)==mi);
            return q;
        };
        while(lo<hi)
        {
            int mi=(lo+hi)/2;
            auto q=gen(mi);
            if(inv(q)+inv(mul(q,p))<k)
                lo=mi+1;
            else
                hi=mi;
        }
        auto q=gen(lo);
        if(inv(q)+inv(mul(q,p))==k)
        {
            cout<<"YES\n";
            for(int x:q)
                cout<<x+1<<" ";
            cout<<"\n";
        }
        else
            cout<<"NO\n";
    }
}