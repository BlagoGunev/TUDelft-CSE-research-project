#include <set>

#include <map>

#include <queue>

#include <stack>

#include <math.h>

#include <vector>

#include <stdio.h>

#include <fstream>

#include <iostream>

#include <string.h>

#include <limits.h>

#include <algorithm>

//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>

//#include <bits/stdc++.h>



#define ff first

#define ss second

#define ll long long

#define pb push_back

#define mp make_pair

#define inf 1000000007

#define mod 1000000007

#define pii pair <int, int>

#define all(x) x.begin(), x.end()

#define FOR(i, x, y) for (int i = x; i <= y; i++)

//#define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)



//using namespace __gnu_pbds;



using namespace std;



//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int k, a, b, n, F[202];



char s[202];



int main()

{

	scanf("%d%d%d", &k, &a, &b);

	scanf("%s", s);

	

	n = strlen(s);

	

	int now = b, sz = k-1;

	for (int i = 1; i <= k; i++) {

		if (sz == 0) {

			if (n < a || n > b) {

				printf("No solution");

				return 0;

			}

			F[i] = n;

			break;

		}

		

		while (now > a && n-now < 0)

			now--;

			

		while (now > a && ((n-now)/sz < a || (n-now)/sz+((n-now)%sz!=0) > b))

			now--;

		

		if (((n-now)/sz < a || (n-now)/sz+((n-now)%sz!=0) > b)) {

			printf("No solution");

			return 0;

		}

		

		F[i] = now, n -= now, sz--;

	}

	

	now = 0;

	for (int i = 1; i <= k; i++) {

		for (int h = now; h < now+F[i]; h++)

			printf("%c", s[h]);

		printf("\n");

		now += F[i];

	}

}