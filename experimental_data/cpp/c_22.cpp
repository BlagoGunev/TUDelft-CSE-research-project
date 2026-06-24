#include <bits/stdc++.h>

#define maxn 100005

#define MOD 1000000007

using namespace std;

typedef long long ll;



int num[maxn];

int main(){

	

//	freopen("in.txt", "r", stdin);

	int n, m, v;

	

	scanf("%d%d%d", &n, &m, &v);

	if(m < n - 1 || m > (ll)(n - 2) * (n - 1) / 2 + 1){

		puts("-1");

		return 0;

	}

	for(int i = 1; i <= n; i++){

		num[i] = i;

	}

	if(v != 2){

		swap(num[2], num[v]);

	}

	for(int i = 1; i < n; i++){

		printf("%d %d\n", num[i], num[i+1]);

	}

	m -= n - 1;

	for(int i = 2; i < n; i++){

		for(int j = i+2; j <= n; j++){

			if(m == 0)

			 return 0;

			printf("%d %d\n", num[i], num[j]);

			m--;

		}

	}

	return 0;

}