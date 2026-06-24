#include <stdio.h>

#include <bits/stdc++.h>

using namespace std;



int v[1005];

vector <int> vc;

int gcd(int x, int y) {

	if (y == 0) return x;

	else return gcd(y, x%y);

}

int main()

{

	int n, aux, ans = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)

		scanf("%d", &v[i]);



	for (int i = 1; i < n; i++) {

		vc.push_back(v[i-1]);

		aux = gcd(v[i-1], v[i]);

		if (aux != 1) {

			vc.push_back(1);

			ans++;

		}

	}

	vc.push_back(v[n-1]);

	printf("%d\n", ans);

	for (int a : vc)

		printf("%d ", a);

	printf("\n");

	return 0;

}