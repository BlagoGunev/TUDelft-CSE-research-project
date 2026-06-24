#include <iostream>

using namespace std;



int main()

{

    int n, k, t;

    

    cin >> n >> k >> t;

    

    int left = 0, mid = 0, comp = t*n*k;

    

    for (int i = 0; i <= n; i++)

    {

        for (int j = 0; j <= k; j++)

        {

            if ((i*k+j)*100<=comp&&(i*k+j+1)*100>comp)

            {

                left = i;

                mid = j;

            }

        }

    }

    

    for (int i = 1; i <= left; i++)

        cout << k << " ";

    if (left < n)

    {

        cout << mid << " ";

        for (int i = 1; i <= n-left-1; i++)

            cout << 0 << " ";

    }

    

    return 0;

}