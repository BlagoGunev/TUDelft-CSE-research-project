#include<bits/stdc++.h> 

using namespace std;



typedef long long LL;

const int maxn = 2e5 + 5;

int n, k;

int a[maxn];

LL c1, c5;



int main(){

	scanf("%d%d%I64d%I64d", &n, &k, &c5, &c1);

	c5 = min(c5, c1*5);

	for(int i = 1; i <= n; i++){

		scanf("%d", &a[i]); a[i] += 1e9;

	}

	sort(a + 1, a + 1 + n);

	LL ans = 4e17;

	for(int mod = 0; mod < 5; mod++){

		priority_queue<LL> que;

		LL sum = 0;

		for(int i = 1; i <= n; i++){

			int aim = (a[i] + 4) / 5 * 5;

			LL cost = (aim - a[i]) * c1 - aim / 5 * c5;

			sum += cost;

			que.push(cost);

			if(que.size() == k){

				ans = min(ans, sum + aim / 5 * c5 * k);

				sum -= que.top();

				que.pop();

			}

		}

		for(int i = 1; i <= n; i++) a[i]++;

	}

	printf("%I64d\n", ans);

	return 0;

}