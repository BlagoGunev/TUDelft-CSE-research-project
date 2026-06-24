#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll N; cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    vector<ll> aite(N, 0);
    for (int i = 0; i < N; ++i)
    {
        ll b = A[i] / 2;
        assert(0 <= i - b || i + b < N);
        
        if (i + b < N) aite[i] = i+b;
        else if (i - b >= 0) aite[i] = i-b;
    }
    
    cout << "YES" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << i+1 << " " << i+1 << endl;
    }
    for (int i = 0; i < N; ++i)
    {
        cout << aite[i] + 1 << " ";
    }
    cout << endl;
    
    return;
}

int main()
{
    solve();
    
    return 0;
}