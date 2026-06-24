#include <cstdio>

#include <iostream>

#include <vector>

#include <string>

#include <map>



using namespace std;



int n, a[110], g, x, y, all;



int main()

{

    ios::sync_with_stdio(false);

    cin>>n;

    for(int i = 1 ; i <= n ; i++ )

        cin>>a[i], all += a[i];

    cin>>x>>y;

    for(int i = 1 ; i <= n ; i++ )

    {

        g += a[i];

        if( (x <= g and g <= y) and (x <= (all-g)and(all-g) <= y ) )

        {

            printf("%d\n", i+1);

            return 0;

        }

    }

    puts("0");

    return 0;

}