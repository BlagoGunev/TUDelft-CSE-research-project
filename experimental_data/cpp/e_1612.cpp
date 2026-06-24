#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);



	int n, m[200000], k[200000];

	cin >> n;

	for (int i = 0; i < n; i++)

		cin >> m[i] >> k[i];



	double Ans_E = 0;

	int Ans_K;

	pair<int, int> E[21][200001] = {};

	for (int K = 1; K <= 20; K++)

	{

		for (int v = 0; v <= 200000; v++)

			E[K][v].second = v;

		for (int i = 0; i < n; i++)

			E[K][m[i]].first += min(K, k[i]);



		sort(E[K], E[K] + 200001, greater<pair<int, int>>());

		double now_E = 0;

		for (int i = 0; i < K; i++)

			now_E += E[K][i].first;

		now_E /= K;

		if (now_E > Ans_E)

			Ans_E = now_E, Ans_K = K;

	}



	cout << Ans_K << '\n';

	for (int i = 0; i < Ans_K; i++)

		cout << E[Ans_K][i].second << ' ';

}