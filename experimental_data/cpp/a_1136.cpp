#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[105][2];
    int n,k;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i][0] >> a[i][1];
    cin >> k;
    for(int i=1;i<=n;i++)
    {
        if(k>=a[i][0]&&k<=a[i][1])
            {cout << n-i+1 << endl;
            break;
            }


    }
}