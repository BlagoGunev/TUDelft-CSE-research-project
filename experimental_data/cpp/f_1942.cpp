#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
#define int ll

using namespace std;

const int C = 277;
int n;
int a[200500];
int k;
int l;

int avg[200500];
const int D = 3;
int delta[200500][2*D+1];
int dp(int id, int k)
{
    if (k < avg[id] - D)
        return -1;
    else if (k <= avg[id] + D)
        return delta[id][k - avg[id] + D];
    return 4e18;
}

void calc(int id)
{
    double e = 0;
    for (int i=id*C; i<(id+1)*C; i++)
        e = sqrt(e + a[i]);
    int m  = int(e);
    avg[id] = m;
    for (int k0 = m-D; k0 <= m+D; k0++)
    {
        int k = k0;
        bool filled = false;
        for (int i=(id+1)*C-1; i>=id*C; i--)
        {
            k = k*k-a[i];
            if (k < 0)
            {
                delta[id][k0-m+D] = -1;
                filled = true;
                break;
            }
            if (k > 2e9)
            {
                delta[id][k0-m+D] = 4e18;
                filled = true;
                break;
            }
        }
        if (!filled)
            delta[id][k0-m+D] = k;
    }
}

void upd(int pos, int val)
{
    a[pos] = val;
    calc(pos/C);
}

bool geq(int x)
{
    for (int i=n-1; i>=l; i--)
    {
        if (x > 2e9)
            return false;
        x = x*x-a[i];
        if (x < 0)
            return true;
    }
    for (int i=k-1; i>=0; i--)
    {
        x = dp(i, x);
        if (x > 2e9)
            return false;
        if (x < 0)
            return true;
    }
    return (x == 0);

//    for (int i=n-1; i>=0; i--)
//    {
////        cout<<k<<" -> ";
//        if (k > 2e9)
//            return false;
//        k = k*k-a[i];
////        cout<<k<<"\n";
//        if (k < 0)
//            return true;
//    }
//    return (k==0);
}

int query()
{
    double e = 0;
    for (int i=max<int>(0, n-555); i<n; i++)
        e = sqrt(e + a[i]);
    int kx = int(e - 1e-3) + 1;
    if (geq(kx)) return kx;
    return kx-1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    k = n/C;
    l = k*C;
    int q;
    cin>>q;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<k; i++)
        calc(i);

    for (int i=0; i<q; i++)
    {
        int pos, val;
        cin>>pos>>val;
        upd(pos-1, val);
        cout<<query()<<"\n";
    }

}