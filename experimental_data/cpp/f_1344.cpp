#include <bits/stdc++.h>



using namespace std;



#ifdef ONPC

mt19937 rng(228);

#else

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#endif



int rep(int x) {

	x %= 2;

	if (x < 0) {

		x += 2;

	}

	assert(0 <= x && x < 2);

	return x;

}



struct M22 {

	int x00, x01;

	int x10, x11;

};



M22 operator * (M22 a, M22 b) {

	M22 c;

	c.x00 = rep(a.x00 * b.x00 + a.x01 * b.x10);

	c.x01 = rep(a.x00 * b.x01 + a.x01 * b.x11);

	c.x10 = rep(a.x10 * b.x00 + a.x11 * b.x10);

	c.x11 = rep(a.x10 * b.x01 + a.x11 * b.x11);

	

	return c;

}



struct M12 {

	int x00, x01;

};



struct M12 operator * (M12 a, M22 b) {

	M12 c;

	c.x00 = rep(a.x00 * b.x00 + a.x01 * b.x10);

	c.x01 = rep(a.x00 * b.x01 + a.x01 * b.x11);

	

	return c;

}







signed main() {

#ifndef ONPC

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#endif



	if (0) {

		for (int i = 0; i < 1; i++) {

			for (int j = 0; j < 2; j++) {

				cout << "c.x" << i << j << " = rep(";

				for (int k = 0; k < 2; k++) {

					cout << "a.x" << i << k << " * b.x" << k << j;

					if (k == 0) {

						cout << " + ";

					}

				}

				cout << ");\n";

			}

		}

		exit(0);

	}	

	

	int n, k;

	cin >> n >> k;

	

	M22 IDENTITY22;

	IDENTITY22.x00 = IDENTITY22.x11 = 1;

	IDENTITY22.x01 = IDENTITY22.x10 = 0;

	

	vector<M22> mlt(n, IDENTITY22);

	

	vector<vector<int>> equations;

	

	for (int iq = 0; iq < k; iq++) {

		string s;

		cin >> s;

		/// RYB

		assert(s == "mix" || s == "RB" || s == "RY" || s == "YB");

		int k;

		cin >> k;

		vector<int> inds(k);

		for (auto &i : inds) {

			cin >> i;

			i--;

		}

		if (s == "mix") {

			/*

				c.x00 = rep(a.x00 * b.x00 + a.x01 * b.x10);

				c.x01 = rep(a.x00 * b.x01 + a.x01 * b.x11);

			*/

			cin >> s;

			assert(s == "R" || s == "Y" || s == "B" || s == "W");

			int x00 = 0, x01 = 0;

			if (s == "R") {	

				x00 = 1, x01 = 0;

			}

			if (s == "Y" ){

				x00 = 0, x01 = 1;

			}

			if (s == "B") {

				x00 = 1, x01 = 1;		

			}

			if (s == "W") {

				x00 = 0, x01 = 0;

			}

			{

				vector<int> equation(2 * n + 1, 0);

				for (auto &i : inds) {

					if (mlt[i].x00) {

						equation[i] = 1;

					}

					if (mlt[i].x10) {

						equation[i + n] = 1;

					}

				}

				equation[2 * n] = x00;

				equations.push_back(equation);

			}

			{

				vector<int> equation(2 * n + 1, 0);

				for (auto &i : inds) {

					if (mlt[i].x01) {

						equation[i] = 1;

					}

					if (mlt[i].x11) {

						equation[i + n] = 1;

					}

				}

				equation[2 * n] = x01;

				equations.push_back(equation);

			}

			continue;

		}	

		

		/// RYB

		M22 mltby;

		mltby.x00 = mltby.x01 = mltby.x10 = mltby.x11 = 0;

		if (s == "YB") {

			mltby.x00 = 1, mltby.x01 = 0;

			mltby.x10 = 1, mltby.x11 = 1;

		}

		if (s == "RB") {

			mltby.x00 = 1, mltby.x01 = 1;

			mltby.x10 = 0, mltby.x11 = 1;

		}		

		if (s == "RY") {

			mltby.x00 = 0, mltby.x01 = 1;

			mltby.x10 = 1, mltby.x11 = 0;

		}

		for (auto &i : inds) {

			mlt[i] = mlt[i] * mltby;

		}

	}



	k = (int) equations.size();

	

	int pz = 0;

	

	vector<bitset<2007>> q(k);

	for (int i = 0; i < k; i++) {

		for (int j = 0; j <= 2 * n; j++) {

			if (equations[i][j]) {

				q[i][j] = 1;

			}

		}

	}

	

	for (int col = 0; col < 2 * n && pz < k; col++) {

		bool f = 0;

		for (int i = pz; i < k; i++) {

			if (q[i][col]) {

				f = 1;

				swap(q[i], q[pz++]);

				break;

			}

		}

		if (f == 0) {

			continue;	

		}

		for (int i = pz; i < k; i++) {

			if (q[i][col]) {

				q[i] ^= q[pz - 1];

			

			}

		}

	}





	vector<int> sol(2 * n, -1);

	

	for (int i = k - 1; i >= 0; i--) {

		int cur = q[i][2 * n], f = -1;

		for (int j = 0; j < 2 * n; j++) {

			if (q[i][j]) {

				if (sol[j] == -1) {

					if (f == -1) {

						f = j;

					}

				} else {

					cur ^= sol[j];

				}			

			}	

		}

		if (f == -1 && cur == 1) {

			cout << "NO\n";

			exit(0);

		}

		if (f != -1) {

			sol[f] = cur;

		}

	}

	

	

	for (int i = 0; i < 2 * n; i++) {

		if (sol[i] == -1) {

			sol[i] = 0;

		}

	}

	

	cout << "YES\n";

	

	for (int i = 0; i < n; i++) {

		int x = sol[i], y = sol[i + n];

		if (x == 0 && y == 0) cout << ".";

		if (x == 1 && y == 0) cout << "R";

		if (x == 0 && y == 1) cout << "Y";

		if (x == 1 && y == 1) cout << "B";	

	}

	cout << "\n";

	

	return 0;

}

/* stuff you should look for

 * int overflow, array bounds

 * special cases (n=1?)

 * do smth instead of nothing and stay organized

 * WRITE STUFF DOWN

 * DON'T GET STUCK ON ONE APPROACH

 */