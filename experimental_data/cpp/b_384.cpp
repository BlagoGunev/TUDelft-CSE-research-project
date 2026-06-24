#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;


int main()
{
    int n, m, col = 0, t;
    cin >> n >> m >> t;
    cout <<(m * (m - 1)) / 2  << endl;
    if ( t == 0)
    {
        for ( int j = m - 1; j > -1; j--)
            for ( int i = 0; i < j; i++)
            {
                printf("%d %d\n", i + 1, i + 2);
                col++;
            }
    }
    else
    {
        for ( int j = 0; j < m; j++)
            for ( int i = 0; i < m - j - 1; i++)
        
            {
                printf("%d %d\n", i + 2, i + 1);
                col++;
            }
    }
    
    //cout << col << endl;

    return 0;
}