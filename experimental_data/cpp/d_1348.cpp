#include <iostream>



using namespace std;



const int nmax = 1000;



long long arr[nmax],prefix[nmax];



int main()

{

    long long tc;

    cin >> tc;

    while(tc--)

    {

        int n;

        cin >> n;

        long long k = 0, p = 1;

        while(p <= n)

        {

            p = p * 2;

            k++;

        }

        arr[0] = 1;

        prefix[0] = 1;

        for(long long i = 1; i < k; i++)

        {

            arr[i] = min((1LL << i),(n - prefix[i-1])/(k-i));

            prefix[i] = prefix[i-1] + arr[i];

        }

        cout << k - 1 << endl;

        for(long long i = 0; i < k - 1; i++)

            cout << arr[i+1] - arr[i] << " ";

        cout << endl;

    }

    return 0;

}