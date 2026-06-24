#include<bits/stdc++.h>

using namespace std;

//#define mod 1000000007LL

#define ll long long

#define ii pair<int,int>

#define vi vector<int>

long long power(int x, int y, int mod)

{

	if(y == 0)

		return 1;

	if(y == 1)

		return x%mod;



	ll temp = power(x,y/2,mod);



	if(y&1)

		return (((temp*temp)%mod)*x)%mod;

	else

		return (temp*temp)%mod;

}



bool miillerTest(int d, int n)

{

    // Pick a random number in [2..n-2]

    // Corner cases make sure that n > 4

    int a = 2 + rand() % (n - 4);

 

    // Compute a^d % n

    int x = power(a, d,n);

 

    if (x == 1  || x == n-1)

       return true;

 

    // Keep squaring x while one of the following doesn't

    // happen

    // (i)   d does not reach n-1

    // (ii)  (x^2) % n is not 1

    // (iii) (x^2) % n is not n-1

    while (d != n-1)

    {

        x = (x * x) % n;

        d *= 2;

 

        if (x == 1)      return false;

        if (x == n-1)    return true;

    }

 

    // Return composite

    return false;

}

 

// It returns false if n is composite and returns true if n

// is probably prime.  k is an input parameter that determines

// accuracy level. Higher value of k indicates more accuracy.

bool isPrime(int n, int k)

{

    // Corner cases

    if (n <= 1 || n == 4)  return false;

    if (n <= 3) return true;

 

    // Find r such that n = 2^d * r + 1 for some r >= 1

    int d = n - 1;

    while (d % 2 == 0)

        d /= 2;

 

    // Iterate given nber of 'k' times

    for (int i = 0; i < k; i++)

         if (miillerTest(d, n) == false)

              return false;

 

    return true;

}



int main()

{

	int n;

	cin >> n;

	if(n == 3)

		cout << 1 << endl << 3 << endl;

	else if(n == 4)

		cout << 2 << endl << 2 << " " << 2 << endl;

	else if(n == 5)

		cout << 1 << endl << 5 << endl;

	else if(n == 6)

		cout << 2 << endl << 3 << " " << 3 << endl;



	else

	{

		int k = 4;

		cout << 3 << endl;

		int a = 1;

		while(1)

		{

			if(isPrime(a,k) && isPrime(n-3-a,k))

			{

				cout << 3 << " " << a << " " << n-3-a << endl;

				return 0;

			}

				a++;

		}	

	}

	return 0;

}