#include<iostream>

using namespace std;

int main()
{
    int n,k;
    while(cin >> n >> k)
    {
        int x = n*(n-1)/2;
        if(x<=k)
        {
            cout << "no solution" << endl;
            continue;
        }
        int i;
        int tmp = 0;
        int ini = 2001;
        for(i=0;i<n;i++)
        {
            cout << i << ' ' << tmp << endl;
            tmp += --ini;
        }
    }
    return 0;
}