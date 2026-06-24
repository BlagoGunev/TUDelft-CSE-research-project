#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

/*x: consists of digits 8−9

This is so, because if x contains digits 0−7

, which in their binary notation are shorter than digits 8−9

, then the number k written on the board, and therefore the number r

(obtained by removing the last n digits of the number k) 

will be shorter than if you use only the digits 8 and 9, 

which means it will not be the maximum possible.

The number of digits 8 in the number x of length n is equal to ⌈n/4⌉ = ⌊(n+3)/4⌋

*/

int main()

{

	int t;

	cin>>t;

	while(t--)

	{

		int n;

		cin>>n;

		int x = (n+3)/4; // no. of digit that is going to be removed from decimal

		for (int i = 0; i < n - x; i++)

		{

			cout<<9;

		}

		for (int i = 0; i < x; i++)

		{

			cout<<8;

		}

		cout<<endl;

	}

	return 0;

}