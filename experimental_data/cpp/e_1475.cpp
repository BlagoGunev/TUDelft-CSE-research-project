#include <bits/stdc++.h>

using namespace std;

#define read(type) readInt<type>() // Fast read

#define ll long long

#define nL "\n"

#define pb push_back

#define mk make_pair

#define pii pair<int, int>

#define a first

#define b second

#define vi vector<int>

#define all(x) (x).begin(), (x).end()

#define umap unordered_map

#define uset unordered_set

#define mod 1000000007

#define imax INT_MAX

#define imin INT_MIN

#define exp 1e9

#define sz(x) (int((x).size()))

 int power(unsigned long long x, 

                                      int y, int p)

    {

        unsigned long long res = 1; // Initialize result

     

        x = x % p; // Update x if it is more than or

        // equal to p

     

        while (y > 0) 

        {

         

            // If y is odd, multiply x with result

            if (y & 1)

                res = (res * x) % p;

     

            // y must be even now

            y = y >> 1; // y = y/2

            x = (x * x) % p;

        }

        return res;

    }

int modInverse(unsigned long long n,

               int p)

{

    return power(n, p - 2, p);

}



int nCrModPFermat(unsigned long long n,

                  int r, int p)

{

    // If n<r, then nCr should return 0

    if (n < r)

        return 0;

    // Base case

    if (r == 0)

        return 1;



    // Fill factorial array so that we

    // can find all factorial of r, n

    // and n-r

    unsigned long long fac[n + 1];

    fac[0] = 1;

    for (int i = 1; i <= n; i++)

        fac[i] = (fac[i - 1] * i) % p;



    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int ttt;

    cin >> ttt;

    while (ttt--)

    {

        int n, k;

        cin >> n >> k;

        vector<ll> arr(n + 1);

        for (int i = 0; i < n; i++)

        {

            cin >> arr[i];

        }

        sort(arr.begin(), arr.end(), greater<ll>());

        int last_index = k - 1;

        int last_val = arr[last_index];

        int rr = 0;

        for (int i = 0; i <= last_index; i++)

        {

            if (last_val == arr[i])

            {

                rr++;

            }

        }

        int nn = 0;

        for (int i = 0; i < n; i++)

        {

            if (last_val == arr[i])

            {

                nn++;

            }

        }

       ll ans = nCrModPFermat(nn, rr, mod);

        cout << ans << "\n";

    }

    return 0;

}