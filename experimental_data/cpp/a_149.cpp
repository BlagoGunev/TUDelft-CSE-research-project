#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int a[12];
int main(){
	int k;
	cin >> k;
	for (int i = 0;i < 12;++i)
		cin >> a[i];
	sort(a, a + 12);
	int ans = 0, id = 11;
	while (id >= 0 && ans < k){
		ans += a[id];
		--id;
	}
	if (id == -1 && ans < k) cout << -1 << endl;
	else cout << 11 - id << endl;
	return 0;
}