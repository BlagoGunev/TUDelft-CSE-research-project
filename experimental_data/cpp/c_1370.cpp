#include <iostream> 
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <iomanip>
#include <set>
#include <queue>
#include <stdlib.h>

using namespace std;

//bool isPrime(long long Number)
//{
//    if (Number <= 1)
//        return 0;
//
//    for (long long i = 2; i <= sqrt(Number); i++)
//        if (Number % i == 0)
//            return 0;
//
//    return 1;
//}
//long long Factorial(int Number)
//{
//	if (Number > 1)
//	{
//		return Number * Factorial(Number - 1);
//	}
//	else
//	{
//		return 1;
//	}
//}

bool isPrime(long long n) {
	// Corner case
	if (n <= 1)
		return 0;

	// Check from 2 to sqrt(n)
	for (long long i = 2; i <= sqrt(n); i++) 
		if (n % i == 0)
			return false;

	return true;
}


#define     fast                   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     exit                   return 0
#define     ld                     long double
#define     ll                     long long
#define     ull                    unsigned long long
#define     str                    string
#define     pii                    pair<int, int>
#define     pll                    pair<long, long>
#define     MP                     make_pair
#define     all(v)                 v.begin(),v.end()
#define     rall(v)                v.rbegin(),v.rend()
#define     loop(i, a, b)          for(int i=a;i<b;++i)
#define     endl                   '\n'


const double pi = 3.14159265358979323846264338327;

// most value to long long is 2 power 32 and 4 * 10 power 18

// next_permutation        prev_permutation
// return void(order); if fun is void

// scanf("%d%d%d"    printf("%s\n"   typedef long long ll;

//#define vfor(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
 //#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
 //#define all(x) (x).begin(),(x).end()
 //#define fr(i,a,b) for (ll i = a; i < b; ++i)
 //#define rf(i,a,b) for(ll i=(b)-1;i>=(a); --i)
 //#define format(n) fixed<<setprecision(n)
 //#define mod 1000000007
 //#define N 1000000
 //#define mid (l+r)/2
 //#define INF LLONG_MAX
 //#define PI acos(-1)

//ll mul(ll a, ll b, ll m)
//{
//	return ((a % m) * (b % m)) % m;
//}
//ll modularExpoontentation(ll Number, ll Power, ll M)
//{
//	int Result = 1;
//	while (Power > 0)
//	{
//		if (Power % 2 == 1)
//		{
//			Result = (Result * Number) % M;
//		}
//		mul(Number, Number, M);
//		Power /= 2;
//	}
//	return Result;
//}
//int Fast_Power(int Number, int Power) // binaryExpoontentation
//{
//	int Result = 1;
//	while (Power > 0)
//	{
//		if (Power % 2 == 1)
//		{
//			Result *= Number;
//		}
//		Number *= Number;
//		Power /= 2;
//	}
//	return Result;
//}

ll Binary_Search(vector<int> Matrix, int Size, int SearchValue, map<int, int> Count)
{
	int Counter = 0;
	int Left = 0;
	int Right = Size - 1;
	int Mid = -1;
	while (Left <= Right)
	{
		Mid = (Right + Left) / 2;
		if (SearchValue == Matrix[Mid])
		{
			return Mid;
		}
		else if (SearchValue > Matrix[Mid])
		{
			Left = Mid + 1;
		}
		else
		{
			Right = Mid - 1;
		}
	}
	return -1;
}

ll gcd(ll FirstNumber, ll SecondNumber)
{
	while (SecondNumber)
	{
		ll Result = FirstNumber;
		FirstNumber = SecondNumber;
		SecondNumber = Result % SecondNumber;
	}
	return FirstNumber;
}

ll lcm(ll FirstNumber, ll SecondNumber)
{
	return FirstNumber / gcd(FirstNumber, SecondNumber) * SecondNumber;
}

ll log_a_to_base_b(ll a, ll b)
{
	return log2(a) / log2(b);
}

void solve()
{
	ll Number;
	bool flag = true;
	cin >> Number;
	while (Number > 1)
	{
		vector<int> Matrix;
		if (Number % 2 != 0)
		{
			Matrix.emplace_back(Number);
		}
		else
		{
			for (int i = 3; i * i <= Number; i++)
			{
				if (Number % i == 0)
				{
					if (i % 2 != 0)
					{
						Matrix.emplace_back(i);
					}
					if ((Number / i) % 2 != 0)
					{
						Matrix.emplace_back(Number / i);
					}
				}
			}
		}
		sort(all(Matrix));
		if (Matrix.size() > 0)
		{
			Number /= Matrix[Matrix.size() - 1];
			if (flag)
			{
				flag = false;
			}
			else
			{
				flag = true;
			}
		}
		else
		{
			Number--;
			if (flag)
			{
				flag = false;
			}
			else
			{
				flag = true;
			}
		}
	}
	if (flag)
	{
		cout << "FastestFinger" << endl;
	}
	else
	{
		cout << "Ashishgup" << endl;
	}
}
int main()
{
	fast
	ll TestCase = 1;
	cin >> TestCase;
	while (TestCase--)
	{
		solve();
	}
}
// 	fill(all(Matrix), true);
// hyrmony squance == > log(log(n))
//result.first = *(std::next( searchSet.begin(), index));

// #include <iomanip> setprecition
/*int i;
	char buffer[33];
	printf("Enter a number: ");
	scanf("%d", &i);
	itoa(i, buffer, 10);
	printf("decimal: %s\n", buffer);
	itoa(i, buffer, 16);
	printf("hexadecimal: %s\n", buffer);
	itoa(i, buffer, 2);
	printf("binary: %s\n", buffer);*/

// (pow(2, Power) - 1) * pow(2, Power - 1) in binary divisor num of ones - num of zeros = 1 
// Euclidean algorithm. ==> gcd(a,b) = gcd(b,a % b) bse case B = 0 

	
//for (int i = 1; i * i <= Size; i++) i <= sqrt(n) ==> i * i <= n
			//{
			//	if (Size % i == 0)
			//	{
			//		Limits.insert(i);
			//		Limits.insert(Size / i);
			//	}
			//}

/*
			ios_base::sync_with_stdio(0);
			cin.tie(0);
			cout.tie(0);

			 ios_base::sync_with_stdio(false);
				cin.tie(NULL);

			to make your code more faster at cin() and cout() operations
			*/