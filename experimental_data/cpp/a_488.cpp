#include <bits/stdc++.h>

using namespace std ;



bool a_to_r(long long a)

{

	a=abs(a) ;

	string r;

	while (a>0)

	{

		int c=(a%10);

		r+=c+'0';

		a/=10;

	}

	string r_asli;

	for (int i=0; i<r.size() ;i++)

		r_asli+= r[r.size()-i-1] ;	

	for (int i=0 ; i<r.size() ; i++)

		if (r_asli[i] == '8')

			return 1 ;

	return 0 ;

}



int main ()

{

	long long n , i=1;

	cin >> n ;

	while (true)

	{

		int a=n+i ;

		if (a_to_r(a) == 1)

		{

			cout << i<< endl;

			return 0;

		}

		i++;

	}

}