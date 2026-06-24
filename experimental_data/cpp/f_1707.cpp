#include <bits/stdc++.h>



int main() {

	using namespace std;

	ios_base::sync_with_stdio(false), cin.tie(nullptr);



	int N, M, T, W; cin >> N >> M >> T >> W;

	T = std::min(T, 1 << __builtin_ctz(N));

	int L = 0;

	while ((1 << L) < N) L++;

	int S = (1 << L);

assert(T < S);



	std::vector<int> seg(2*S);

	for (int i = 0; i < S; i++) {

		seg[S+i] = i < N ? -1 : 0;

	}



	int num_extra = 0;

	int num_bad = 0;

	for (int l = L-1; l >= 0; l--) {

		for (int i = 0; i < (1 << l); i++) {

			int x = seg[(2 << l) + i];

			int y = seg[(3 << l) + i];

			if ((T >> l) & 1) {

				if (x == -1 || y == -1) {

					seg[(1 << l) + i] = x & y; // -1 and with anything to get anything

					// no extra, cause they're equal

				} else if (x == y) {

					seg[(1 << l) + i] = x;

				} else {

					seg[(1 << l) + i] = 0;

					num_bad++;

				}

			} else {

				if (x == -1 || y == -1) {

					seg[(1 << l) + i] = x | y;

					if (x == -1 && y == -1) {

						num_extra++;

					}

				} else {

					seg[(1 << l) + i] = x ^ y;

				}

			}

		}

	}



	auto set_val = [&](int pos, int val) -> void {

		for (int l = L-1; l >= 0; l--) {

			int i = pos & ((1 << l) - 1);

			int x = seg[(2 << l) + i];

			int y = seg[(3 << l) + i];

			if ((T >> l) & 1) {

				if (x == -1 || y == -1) {

					seg[(1 << l) + i] = x & y; // -1 and with anything to get anything

					// no extra, cause they're equal

				} else if (x == y) {

					seg[(1 << l) + i] = x;

				} else {

					seg[(1 << l) + i] = 0;

					num_bad--;

				}

			} else {

				if (x == -1 || y == -1) {

					seg[(1 << l) + i] = x | y;

					if (x == -1 && y == -1) {

						num_extra--;

					}

				} else {

					seg[(1 << l) + i] = x ^ y;

				}

			}

		}

		seg[S+pos] = val;

		for (int l = L-1; l >= 0; l--) {

			int i = pos & ((1 << l) - 1);

			int x = seg[(2 << l) + i];

			int y = seg[(3 << l) + i];

			if ((T >> l) & 1) {

				if (x == -1 || y == -1) {

					seg[(1 << l) + i] = x & y; // -1 and with anything to get anything

					// no extra, cause they're equal

				} else if (x == y) {

					seg[(1 << l) + i] = x;

				} else {

					seg[(1 << l) + i] = 0;

					num_bad++;

				}

			} else {

				if (x == -1 || y == -1) {

					seg[(1 << l) + i] = x | y;

					if (x == -1 && y == -1) {

						num_extra++;

					}

				} else {

					seg[(1 << l) + i] = x ^ y;

				}

			}

		}

	};



	for (int z = 0; z < M; z++) {

		int i; cin >> i; i--;

		int v; cin >> v;

		set_val(i, v);

	}





	int Q; cin >> Q;

	while (Q--) {

		int f, g, p; cin >> f >> g >> p;

		f--;

		set_val(f, g);



		if (num_bad > 0) {

			cout << 0 << '\n';

		} else {

			int e = (num_extra + (seg[1] == -1)) * W;

			int64_t r = 1;

			int64_t a = 2;

			for (; e; e >>= 1) {

				if (e & 1) { r *= a, r %= p; }

				a *= a, a %= p;

			}

			cout << r << '\n';

		}

	}



	return 0;

}