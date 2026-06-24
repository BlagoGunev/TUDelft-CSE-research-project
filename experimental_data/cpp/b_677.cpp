#include <iostream>

#include <cstdio>

#include <cmath>

#include <algorithm>

#include <set>

#include <map>

#include <vector>

#include <iomanip>

#include <ctime>

using namespace std;



template <typename T>

T next_int() {  

    T x = 0, p = 1;

    char ch;

    do { ch = getchar(); } while(ch <= ' ');

    if (ch == '-') {

        p = -1;

        ch = getchar();

    }

    while(ch >= '0' && ch <= '9') {

        x = x * 10 + (ch - '0');

        ch = getchar();

    }

    return x * p;

}



const int max_n = (int)1e6 + 227 + 1;

const int max_int = (int)1e9 + 227 + 1;



int main() {

//	freopen("input.txt", "r", stdin);

//    freopen(".out", "w", stdout);



	int n = next_int<int>();

	int m = next_int<int>();

	int k = next_int<int>();



	long long e = 0;

	long long ans = 0;

	for(int i = 0; i < n; i++) {

		long long a = next_int<int>();

	

		if(a + e <= m) {

			e += a;

		} else {

			long long temp = (a + e) - m;



			long long kek = temp / k + (bool)(temp % k);



			ans += kek;

			e = max(0LL, e - kek * k);

			e += a;

		}

	}



	cout << ans + e / k + (bool)(e % k) << "\n";

}