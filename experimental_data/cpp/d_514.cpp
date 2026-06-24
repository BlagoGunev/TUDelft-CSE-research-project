//============================================================================

// Name        : 514D.cpp

// Author      : Hamed O.Khaled

// Version     :

// Copyright   : Your copyright notice

// Description : Hello World in C++, Ansi-style

//============================================================================

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

int matrix[maxn][5];

int ans[5];

deque<int> deq[5];



int main() {

	int n, m, k, p1 = 0, p2 = 0, ansSz = 0;

	bool p2_f = true;

	scanf("%d%d%d", &n, &m, &k);

	for(int i = 0;i < n;i++)

		for(int j = 0;j < m;j++)

				scanf("%d", &matrix[i][j]);

	for(int i = 0;i < m;i++) deq[i].push_back(matrix[0][i]);

	while(p1 <= p2 && p1 < n && p2 <n){



		long long sum = 0;

		p2_f = false;



		for(int i = 0;i < m;i++) sum += deq[i].front();

		if(sum <=k) p2_f = true;

		if(sum <= k && (p2-p1+1 > ansSz)){

			memset(ans, 0, sizeof(ans));

				for(int j = 0;j < m;j++)

					ans[j] = deq[j].front();

			ansSz = p2-p1+1;





		}



		if(p2_f || p1 == p2){

			p2++;

			for(int i = 0;i < m && p2 < n;i++){

				while(!deq[i].empty() && deq[i].back() <= matrix[p2][i]) deq[i].pop_back();

				deq[i].push_back(matrix[p2][i]);

			}

		}

		else{

			for(int i = 0;i < m;i++){

				if(deq[i].front() == matrix[p1][i]) deq[i].pop_front();

			}

			p1++;

		}



	}

	for(int i = 0;i < m;i++)

		printf("%d ", ans[i]);

	puts("\n");





	return 0;

}