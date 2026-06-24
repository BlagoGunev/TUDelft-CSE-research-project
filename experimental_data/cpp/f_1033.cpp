#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include<bitset>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

#define nd second
#define st first
#define mp make_pair
#define pb push_back
#define orta (((bas)+(son))/2)
#define sol (k+k)
#define sag (k+k+1)

const int N = 1e6 + 5;;
const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
const int logN = 17;

int a[N], w, n, m, mx, dp[N * 10], H[N], P[N], P1[N], P2[N],  F[N];
char str[123];

int f(int x) {
	int &r = dp[x];
	if(r != -1) return r;
	r = 0;
	int cur = x;
	for(int i = w - 1; i >= 0; i--) {
		if(P[i] * 2 <= cur) {
			return r = (f(x - P[i]) + f(x - 2 * P[i]));;
		}
		else if(P[i] <= cur)
			cur -= P[i];
	} return r = H[F[x]];;
}

int main() {

	scanf("%d %d %d", &w, &n, &m);

	P[0] = 1;

	memset(dp, -1, sizeof dp);

	mx = (1 << w);

	for(int i = 1; i <= 12; i++)
		P[i] = P[i - 1] * 3;

	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		H[a[i]]++;
	}

	for(int i = 1; i < mx; i++) {
		int num = 0;
		for(int j = 0; j < w; j++) {
			if(i & (1 << j))
				num += P[j];
		}
		P1[i] = num;
		F[num] = i;
		P2[i] = 2 * num;
	}

	mx = (1 << w);

	for(int i = 1; i <= m; i++) {
		scanf("%s", str + 1);
		reverse(str + 1, str + w + 1);
		int ans = 0;
		int _and = 0, _notand = 0, _xor = 0, _notxor = 0, _or = 0, _notor = 0;
		for(int j = 1; j <= w; j++) {
			if(str[j] == 'A') _and += (1 << (j - 1));
			if(str[j] == 'O') _or += (1 << (j - 1));
			if(str[j] == 'X') _xor += (1 << (j - 1));
			if(str[j] == 'a') _notand += (1 << (j - 1));
			if(str[j] == 'o') _notor += (1 << (j - 1));
			if(str[j] == 'x') _notxor += (1 << (j - 1));
		} 
		for(int j = 0; j < mx; j++)
			if(H[j]) {
				int zeros = ((j ^ _or) & _or) + (((j ^ _xor) & _xor)) +  ((j & _and)) +  ((j & _notxor));
				int ones = (j & (_notand)) + (j & (_xor)) + ((j ^ _notor) & _notor) + ((j ^ _notxor) & _notxor);
				int oneszeros = ((j ^ _and) & _and) + (j & _notor);
				if(zeros + ones + oneszeros == mx - 1) {
					ans += f(P1[ones] + P2[oneszeros]) * H[j];
					//if((ones & j) == ones && (zeros & j) == 0) {
					//	ans += H[j];
					//}
				}
				else {
				//	cout << zeros << ' ' << ones << ' ' << oneszeros << ' ' << j << endl;
				}
			}
		printf("%d\n", ans); 
	} 

	return 0;
}