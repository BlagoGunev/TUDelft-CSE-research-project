#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, a;
int b[1000005], p[1000005];

bool cal(int x){
	if(x > min(n, m)) return false;

	long long res = 0;
	for(int i; i<x;i++) res += max(0, p[i] - b[n - x + i]);
	return (res <= a);
}

int main(){
	std::ios::sync_with_stdio(false);
	while(cin >> n >> m >> a){
            for(int i=0;i<n;i++)
            cin>>b[i];
		for(int i=0;i<m;i++)
            cin>>p[i];
		sort(b, b + n);
		sort(p, p + m);
		int l = 0, r = min(n, m) + 1, mid;
		while(l < r){
			mid = (l + r)/2;
			if(cal(mid)) l = mid + 1;
			else r = mid;
		}
		int num = l - 1;
		long long res = -a;
		for(int i=0;i<num;i++){
			res += p[i];
		}
		res = max(res, 0ll);
		cout << num << " " << res << endl;
	}
}