#include <cstdio>
#include <cstring>
const int maxn = 100;
int crush[maxn + 5];
bool vst[maxn + 5];
int sc[maxn + 5];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int n;

int find_sc(int id)
{
	int count = 0, next_id = id;
	memset(vst, 0, sizeof(vst));
	vst[id] = 1;
	while (1) {
		next_id = crush[next_id];
		count++;
		if (vst[next_id]) {
			if (next_id == id) return (count % 2) ? count : (count / 2);
			else return -1;
		}
		vst[next_id] = 1;
	}
}

int find_exp(int p)
{
	int tmp, count, _max = 0;
	for (int i = 1; i <= n; i++) {
		tmp = sc[i];
		count = 0;
		while (tmp % p == 0) {count++; tmp /= p; }
		if (count > _max) _max = count;
	}
	return _max;
}

int main()
{
	int tmp;
	bool flag = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &crush[i]);
	for (int i = 1; i <= n; i++) {
		sc[i] = find_sc(i);
		if (sc[i] == -1) {flag = 0; break; }
	}

	if (flag) {
		long long lcm = 1;
		for (int i = 0; i <= 24; i++) {
			tmp = find_exp(prime[i]);
			while (tmp--) lcm *= prime[i];
		}
		printf("%I64d\n", lcm);
	}
	else printf("-1\n");
	return 0;
}