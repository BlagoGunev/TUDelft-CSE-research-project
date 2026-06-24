/********   All Required Header Files ********/

#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <sstream>

#include <queue>

#include <deque>

#include <bitset>

#include <iterator>

#include <list>

#include <stack>

#include <map>

#include <set>

#include <functional>

#include <numeric>

#include <utility>

#include <limits>

#include <time.h>

#include <math.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <assert.h>

/***pre processors ***/

using namespace std;

#define gcd(a,b) __gcd(a,b)

#define TEST int t;cin>>t;while(t--)

const long long int mod = 1e9+7;

typedef long long int ll;

ll fexpo(ll a,ll b)

{

    if(b==0)

        return 1LL;

    if(b==1)

        return a;

    if(b==2)

        return a*a;

    if(b%2==0)

        return fexpo(fexpo(a,b/2),2);

    else

        return a*fexpo(fexpo(a,(b-1)/2),2);

}

int previous (int n)

{

	return log2(n);

}

int main() {



ios::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	int n , B , p;

	cin >> n >> B >> p;

	int b  =  0;

	b = 2* B + 1;

	int N = n;



	int countt = 0 ;

	while(true)

	{

		if(n == 1)

			break;

		int l = log2(n);

		int x = n - (fexpo(2,l));

		//cout <<"l and x " << l << " " << x << endl;

		countt += (fexpo(2 , l) / 2);

		n = (fexpo(2 , l) / 2) + x;

		if(n == 1)

			break;

	}

cout << countt * b << " " << p * N << endl;









}