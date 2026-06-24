#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const int MOD = 1'000'000'007;

int pow(int a, int n) {
	int r = 1;
	for (; n; n >>= 1, a = 1LL * a * a % MOD )
		if ( n & 1 )
			r = 1LL * r * a % MOD;
	return r;
}

void proc() {
	
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for ( int i = 0; i < n; i++ )
		std::cin >> a[i];
	
	std::sort(&a[0], &a[n]);
	
	int t = 0;
	
	while ( n-- ) {
		
		t += 1LL * a[0] * pow(2, n) % MOD;
		t %= MOD;
		for ( int i = n+1; i--; )
			a[i] -= a[0];
		
		std::map<int, std::vector<std::pair<int, int>>> m;
		for ( int i = 0; i < n; i++ )
			m[a[i]+a[i+1]].push_back({i,i+1});
		
		std::vector<int> b;
		for ( int k = n; k--; ) {
			auto p = m.begin();
			b.push_back(p->first);
			int i = p->second.back().first;
			int j = p->second.back().second;
			if ( p->second.size() == 1 )
				m.erase(p);
			else
				p->second.pop_back();
			if ( j < n )
				m[a[i]+a[j+1]].push_back({i,j+1});
		}
		std::swap(a,b);
	}
	
	std::cout << t << std::endl;
	
}

int main() {
	
	std::cin.tie(0);
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);
	
	int t = 1;
	// std::cin >> t;
	
	while ( t-- )
		proc();
	
	return 0;
}