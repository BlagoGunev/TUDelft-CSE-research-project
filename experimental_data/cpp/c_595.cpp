#include <cmath>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <algorithm>



using namespace std;



namespace WorkSpace {

	const int Inf = 2147483647;

	const int Max_N = 200010;

	void CheckMin(int &A, int B) {

		A > B ? A = B : 0;

	}

	int X[Max_N];

	void Main() {

		int N;

		scanf("%d", &N);

		int Ans = Inf;

		for (int i = 1; i <= N; ++ i) {

			scanf("%d", X + i);

		}

		sort(X + 1, X + N + 1);

		int len = N / 2;

		for (int i = 1; i + len <= N; ++ i) {

			CheckMin(Ans, X[i + len] - X[i]);

		}

		printf("%d", Ans);

		return ;

	}

}



int main() {

	WorkSpace :: Main();

	return 0;

}