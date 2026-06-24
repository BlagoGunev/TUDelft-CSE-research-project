#include <bits/stdc++.h>



using namespace std;



const int N = 100500;



int n, cnt, a[N], b[N];



int main() {

	scanf("%d", &n);



	for (int i = 1; i <= n; i++)

		scanf("%d", &a[i]), b[i] = a[i];



	sort(b + 1, b + 1 + n);



	for (int i = 1; i <= n; i++)

		cnt += (a[i] != b[i]);



	if (cnt <= 2)

		puts("Yes");

	else

		puts("No");



	return 0;

}