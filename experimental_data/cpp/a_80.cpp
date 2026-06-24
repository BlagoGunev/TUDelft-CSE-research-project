#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
bool prime(int n)
{
    for(int i = 2;i * i <= n;i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int a,b;
    cin >> a >> b;
    if(prime(a))
    {
        if(prime(b))
        {
        for(int i = a + 1;i < b;i++)
            if(prime(i))
            {
                cout << "NO";
                return 0;
            }
            cout << "YES";
            return 0;
        }
        cout << "NO";
        return 0;
    }
    cout << "NO";
    return 0;
}