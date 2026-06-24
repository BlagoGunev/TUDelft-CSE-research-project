#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100 + 8;

int N;
int a[maxn];

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);

	int i = 0;
	for (i = 0; i < N; i++)
		if (a[i] >= a[i + 1])
			break;
	for (; i < N; i++)
		if (a[i] != a[i + 1])
			break;
	for (; i < N; i++)
		if (a[i] <= a[i + 1])
			break;
	if (i == N)
		puts("YES");
	else
		puts("NO");


	return 0;
}