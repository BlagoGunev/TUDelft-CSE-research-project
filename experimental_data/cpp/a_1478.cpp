#include <iostream>
using namespace std;
int main()
{
	int t, n, a[107], i;
	scanf("%d", &t);
	while (t--){
		int cnt[107] = {0};
		int max = 0;
		scanf("%d", &n);
		for (i = 0 ; i < n; i++){
			scanf("%d", &a[i]);
			cnt[a[i]]++;
			if (cnt[a[i]] > max){
				max = cnt[a[i]];
			}
		}
		printf("%d\n", max);
	}
	return 0;
}