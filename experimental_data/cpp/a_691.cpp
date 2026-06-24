#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> ar;
    int n;
    cin >> n;
    int z;
    int b1{0},b2{0};
    for (int i=0;i<n;i++)
    {
        cin >> z;
        if (z == 0)
            b1++;
        else b2++;

    }
    if (n==1 and b1 == 1)
        cout << "NO";
    else if (n==1 and b1!=1)
        cout << "YES";
    else if (b1 == 1)
        cout << "YES";
    else cout << "NO";
    return 0;
}