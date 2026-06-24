#include <bits/stdc++.h>

using namespace std;



int n = 101;

const int mod = 1e9 + 7;



// matrix starts

template <typename Type = int>

class Matrix {

public:

	int n, m;

	vector <vector <Type>> array;

// 	int mod;



	Matrix(int _n = 0, int _m = 0) {

		n = _n, m = _m;

		array.assign(n, vector <Type> (m));

	}

	

	void print() {

		cerr << "size {" << n << ", " << m << "}" << endl;

		for(int i = 0; i < n; i++) {

			for(int j = 0; j < m; j++)

				cerr << array[i][j] << " ";

			cerr << endl;

		}

	}

	

	void identity() {

		for(int i = 0; i < n; i++)

			for(int j = 0; j < m; j++)

				array[i][j] = i == j;

	}

	

		void assign(int n, int m) {

		array.assign(n, vector<Type>(m));

	}

	

	Matrix operator *(Matrix &M) {

		assert(m == M.n);

		Matrix result(n, M.m);

		for(int i = 0; i < n; i++) {

			for(int j = 0; j < M.m; j++) {

				result[i][j] = 0;

			}

		}

		if(is_same<Type, double> :: value)

			for(int i = 0; i < n; i++) 

				for(int k = 0; k < M.n; k++) 

					for(int j = 0; j < M.m; j++)

						result[i][j] = (result[i][j] + array[i][k] * M[k][j]);

		else if(is_same<Type, int> :: value || is_same<Type, long long> :: value)

			for(int i = 0; i < n; i++) 

				for(int k = 0; k < M.n; k++) 

					for(int j = 0; j < M.m; j++)

						result[i][j] = (long long)((long long)result[i][j] + (long long)array[i][k] * M[k][j]) % mod;

		return result;

	}

	

	void operator =(Matrix M) {

		assign(M.n, M.m);

		for(int i = 0; i < n; i++)

			for(int j = 0; j < m; j++)

				array[i][j] = M[i][j];

	}

	

	void operator *=(Matrix &M) {

		*this = (*this) * (M);

	}

	

	Matrix operator ^(long long k) {

		Matrix ans(n, m);

		ans.identity();

		Matrix temp = *this;

		while(k) {

			if(k % 2) ans *= temp;

			temp *= temp;

			k /= 2;

		}

		return ans;

	}

	

	void operator ^= (int k) {

		*this = (*this) ^ k;

	}



	

	vector <Type>& operator [](int i) {

		return array[i];

	}

};

// matrix ends





int main() {

    ios_base::sync_with_stdio(0);

    Matrix <int> R(101, 101);

    R[0][100] = R[100][100] = 1;

    for(int i = 99; i > 0; i--)

        R[i][i - 1] = 1;

    int N, x;

    cin >> N >> x;

    for(int i = 0; i < N; i++) {

        int d;

        cin >> d;

        R[0][d - 1]++;

    }

    R ^= (x + 1);

    cout << R[0][100] << endl;

}