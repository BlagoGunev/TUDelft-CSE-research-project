#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	int n;
	int v[5];
	for (int i = 0; i < 5; i++)
		v[i] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x;
		scanf ("%d", &x);
		v[x]++;
	}
	int cnt = v[4];
	int tmp = min(v[1], v[3]);
	cnt += tmp;
	v[1] -= tmp;
	v[3] -= tmp;
	cnt += v[2]/2;
	v[2] %= 2;
	cnt += v[3];
	if(v[2] > 0){
		cnt++;
		v[1] = max(0, v[1]-2);
	}
	if(v[1] > 0){
		cnt += (v[1]-1)/4 + 1;
	}
	printf("%d\n", cnt);
	return 0;
}