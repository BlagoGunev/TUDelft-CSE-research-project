#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//#pragma GCC target ("avx,tune=native")
//Use above if bruteforcing with lots of small operations. Or just use it anytime, there's no downside. AVX is better slightly
/*
TASK: hidden
LANG: C++11
*/
using namespace std;
typedef long long ll;
typedef pair<int, int> pair2;
typedef pair<int, pair<int, int> > pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 23
#define IINF 1000000000
#define INF 1000000000000000000LL
#define mp make_pair
#define pb push_back
#define remove pop

/*
Take a seat right over there, sat on the stairs
Stay or leave, the cabinets are bare and I'm unaware
Of just how we got into this mess, got so aggressive
I know we meant all good intentions
So pull me closer
Why don't you pull me close?
Why don't you come on over?
I can't just let you go
Oh baby, why don't you just meet me in the middle?
I'm losing my mind just a little
So why don't you just meet me in the middle?
In the middle
Baby, why don't you just meet me in the middle?
I'm losing my mind just a little
So why don't you just meet me in the middle?
In the middle, oh
Take a step back for a minute, into the kitchen
Floors are wet and taps are still running, dishes are broken
How did we get into this mess? Got so aggressive
I know we meant all good intentions
So pull me closer
Why don't you pull me close?
Why don't you come on over?
I can't just let you go, oh
Baby, why don't you just meet me in the middle?
I'm losing my mind just a little
So why don't you just meet me in the middle?
In the middle
Looking at you, I can't lie
Just pouring out admission
Regardless of my objection, oh
And it's not about my pride
I need you on my skin
Just come over, pull me in, just
Oh, baby, why don't you just meet me in the middle?
I'm losing my mind just a little
So why don't you just meet me in the middle?
In the middle, no no
Baby, why don't you just meet me in the middle? Oh Yeah
I'm losing my mind just a little
So why don't you just meet me in the middle? Oh
In the middle
Baby, why don't you just meet me in the middle, baby?
I'm losing my mind just a little
So why don't you just meet me in the middle, middle?
In the middle, middle
*/

int n, m;
ll k;
map<ll, ll> xorValues[MAXN][MAXN], xorValuesReverse[MAXN][MAXN];
ll grid[MAXN][MAXN];

int distance(int i, int j) {
	return i + j;//n - i - 1 + m - j - 1;
}
int main() {
	if (fopen("FILENAME.in", "r")) {
		freopen("FILENAME.in", "r", stdin);
		freopen("FILENAME.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}	

	int middleDistance = (n + m - 2) / 2;

	xorValues[0][0][grid[0][0]] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (distance(i, j) >= middleDistance) {
				continue;
			}

			for (pair<ll, ll> v : xorValues[i][j]) {
				if (i + 1 < n) {
					xorValues[i + 1][j][v.first ^ grid[i + 1][j]] += v.second;
				}
				if (j + 1 < m) {
					xorValues[i][j + 1][v.first ^ grid[i][j + 1]] += v.second;
				}

				//cout << "xorValues " << i << ' ' << j << " has " << v.first << endl;
			}
		}
	}

	xorValuesReverse[n - 1][m - 1][0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (distance(i, j) <= middleDistance) {
				continue;
			}

			for (pair<ll, ll> v : xorValuesReverse[i][j]) {
				if (i - 1 >= 0) {
					xorValuesReverse[i - 1][j][v.first ^ grid[i][j]] += v.second;
				}
				if (j - 1 >= 0) {
					xorValuesReverse[i][j - 1][v.first ^ grid[i][j]] += v.second;
				}

				//cout << "xorValuesReverse " << 
			}
		}
	}

	ll answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (distance(i, j) == middleDistance) {
				for (pair<ll, ll> v : xorValues[i][j]) {
					//cout << "xorValues " << i << ' ' << j << " has " << v.first << endl;
					ll desiredReverse = v.first ^ k;
					if (xorValuesReverse[i][j].find(desiredReverse) != xorValuesReverse[i][j].end()) {
						answer += v.second * xorValuesReverse[i][j][desiredReverse];
					}
				}/*
				for (pair<ll, ll> v : xorValuesReverse[i][j]) {
					cout << "xorValuesReverse " << i << ' ' << j << " has " << v.first << endl;
				}*/
			}
		}
	}
	cout << answer << endl;
}