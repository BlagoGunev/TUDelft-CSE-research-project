#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define fi first
#define se second

void doRoutine()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

signed  main()
{
    doRoutine();
    int n;
    cin >> n;
    vector <int> us(1179);
    for (int i = 0; i < 1179; i++)
        us[i] = -1;
    vector <bool> ans(n);
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int x = a[i];
        if (us[x] > -1)
            ans[us[x]] = 0;
        us[x] = i;
        ans[i] = 1;
    }
    vector <int> ca;
    for (int i = 0; i < n; i++)
    {
        if (ans[i])
            ca.push_back(a[i]);
    }
    cout << ca.size() << endl;
    for (auto x : ca)
        cout << x << " ";
    cout << endl;
    return 0;
}