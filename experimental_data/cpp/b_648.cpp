#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m);
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }
    int mid = sum / n;
    sort(a.begin(), a.end());
    while (n > 0)
    {
        cout << a[0] << " " << a[m - 1] << endl;
        a.erase(a.begin() + 0);
        a.erase(a.end() - 1);
        m = m - 2;
        n--;
    }
    
    return 0;
}