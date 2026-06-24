#include <iostream>
#include <vector>

using namespace std;

int c[27], d[27];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, i, j, k;
    vector<int> f;
    bool t = 0;
    string a, b;
    cin >> n >> a >> b;
    for (i = 0; i < n; i++)
    {
        c[a[i] - 97]++;
        d[b[i] - 97]++;
    }
    for (i = 0; i < 27; i++)
    {
        if (c[i] != d[i])
        {
            t = 1;
            break;
        }
    }
    if (t) cout << -1;
    else
    {
        for (i = 0; i < n; i++)
        {
            if (b[i] != a[i])
            {
                for (j = i + 1; j < n; j++)
                {
                    if (b[i] == a[j])
                    {
                        for (k = j; k > i; k--)
                        {
                            swap(a[k - 1], a[k]);
                            f.push_back(k);
                        }
                        break;
                    }
                }
            }
        }
        cout << f.size() << "\n";
        for (i = 0; i < f.size(); i++)
            cout << f[i] << " ";
    }
    return 0;
}