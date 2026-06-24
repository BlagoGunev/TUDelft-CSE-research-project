#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const int N = 3e5 + 10;

int a[N], n;

int main()
{
    int T;
    cin >> T;
    while(T -- )
    {
        vector<int> p;
        cin >> n;
        for(int i = 0; i < n; i ++ ) cin >> a[i];
        sort(a, a + n);
        
        int l = 0, r = n - 1;
        LL sum = 0;
        LL t = a[n - 1] - a[0];
        while(l <= r)
        {
            if(sum + a[r] < t)
            {
                sum += a[r];
                p.push_back(a[r --]);
            }
            else if(sum + a[l] < t)
            {
                sum += a[l];
                p.push_back(a[l ++]);
            }
            else break;
        }
        if(p.size() != n) puts("No");
        else
        {
            puts("Yes");
            for(int i = 0; i < p.size(); i ++ )
                cout << p[i] << " ";
            cout << endl;
        }
    }
    return 0;
}