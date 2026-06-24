#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 800003;

int n;

pair<LL, LL> p[N];

priority_queue<LL> pq1, pq2;

LL ans;

int main(){

	ios::sync_with_stdio(0);

	cin >> n;

	for(int i = 1;i <= n;++ i){

		cin >> p[i].first >> p[i].second;

		p[i].first += p[i].second;

	}

	sort(p + 1, p + n + 1);

	pq1.push(p[1].second);

	pq2.push(p[1].first - p[1].second);

	for(int i = 2;i <= n;++ i){

		int now = p[i].first, pos = p[i].second;

		if(pos >= pq1.top() && pos <= now - pq2.top()){

			pq1.push(pos); pq2.push(now - pos);

		} else if(pos < pq1.top()){

			ans += pq1.top() - pos;

			pq2.push(now - pq1.top());

			pq1.pop(); pq1.push(pos); pq1.push(pos);

		} else {

			ans += pos - now + pq2.top();

			pq1.push(now - pq2.top());

			pq2.pop(); pq2.push(now - pos); pq2.push(now - pos);

		}

	}

	printf("%lld\n", ans);

}