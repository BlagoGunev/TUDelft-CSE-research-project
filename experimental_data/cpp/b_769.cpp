#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[105];
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if(a[0] == 0 || s < n - 1)
    {
        cout << "-1";
        exit(0);
    }
    cout << n - 1 << endl;
    bool b[105];
    for(int i = 0; i < n; i++)
    {
        b[i] = 0;
    }
    b[0] = 1;
    for(int i = 0; i < n; i++)
    {
        if(b[i])
        {
            //int k = a[i];
            for(int j = i; j < n && a[i]; j++)
            {
                if(b[j] == 0 && a[j] != 0)
                {
                    //k--;
                    a[i]--;
                    b[j] = 1;
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }
    }
    for(int i = n - 1; i >= 0; i--)
    {
        if(b[i])
        {
            for(int j = 0; j < n && a[i]; j++)
            {
                if(b[j] == 0)
                {
                    //k--;
                    a[i]--;
                    b[j] = 1;
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }
    }
    return 0;
}