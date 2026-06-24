#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


int n,m = 1e9,k;
vector <int> a;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        if( x < m )
            m = x;
    }
    long long ans  = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == m)
            ans++;
    }
    if(ans <= n/2)
        cout << "Alice";
    else
        cout << "Bob";
    return 0;
}