/**

 * author: bose_aritra2003

 */



#pragma GCC optimize("Ofast,unroll-loops")

#pragma GCC target("avx,avx2,fma")



#include <algorithm>

#include <bitset>

#include <cmath>

#include <cstdlib>

#include <cstring>

#include <fstream>

#include <iomanip>

#include <iterator>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <utility>

#include <vector>



using namespace std;



//----------------------</SHORT-HAND>------------------------

#define all(x) (x).begin(),(x).end()

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);



//----------------------</CONSTANTS>-------------------------

#define PI 3.1415926535897932384626433832795l

#define MOD 1000000007



//----------------------</FUNCTIONS>-------------------------

#define gcd(a,b) __gcd(a,b)

#define lcm(a,b) (((a)*(b))/gcd(a,b))

#define search(v,x) binary_search(all(v), x)



// ----------------------</BITWISE>--------------------------

/* a=target variable, b=bit number to act upon 0-n */

#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))

#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))

#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))



// '!!' to make sure this returns 0 or 1

#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))



#define BITMASK_SET(x, mask) ((x) |= (mask))

#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))

#define BITMASK_FLIP(x, mask) ((x) ^= (mask))

#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))

#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))





class Problem {

private:

    int tc; //No. of testcases



    long ceiling(long a, long b) {

        return (a + b - 1) / b;

    }



    long long fastPow(long long base, long long power) {

        /**

         * @param base: base number

         * @param power: power to raise the base to

         * @return: base^power

         */

        long long res = 1;

        while (power > 0) {

            if (power & 1)

                res = res * base;

            base = base * base;

            power >>= 1;

        }

        return res;

    }



    string dec_to_bin(long long n) {

        /**

         * @param n: number to convert to binary

         * @return: binary representation of n

         */

        string s = bitset<64> (n).to_string();

        const auto loc1 = s.find('1');

        if(loc1 != string::npos)

            return s.substr(loc1);

        return "0";

    }



    long long bin_to_dec(string s) {

        /**

         * @param s: binary representation of n

         * @return: decimal representation of n

         */

        long long n = 0;

        for(int i = 0; i < s.size(); i++)

            n += (s[i] - '0') * fastPow(2, s.size() - i - 1);

        return n;

    }



    pair<long, long> farthestCell(auto N, auto M, auto I, auto J) {

        /**

         * @param N: number of rows

         * @param M: number of columns

         * @param I: row index of starting cell

         * @param J: column index of starting cell

         * @return: pair of row and column indices of farthest cell from starting cell

         */

        pair<long, long> p{};

        // From cell(N, M)

        int d1 = N + M - I - J;

        // From Cell(1, 1)

        int d2 = I + J - 2;

        // From cell(N, 1)

        int d3 = N - I + J - 1;

        // From cell(1, M)

        int d4 = M - J + I - 1;



        // Finding out maximum

        int maxDistance = max(d1,

                              max(d2,

                                  max(d3, d4)));



        if(maxDistance == d1) {

            p.first = N;

            p.second = M;

        }

        else if(maxDistance == d2) {

            p.first = 1;

            p.second = 1;

        }

        else if(maxDistance == d3) {

            p.first = N;

            p.second = 1;

        }

        else if(maxDistance == d4) {

            p.first = 1;

            p.second = M;

        }

        return p;

    }



    int sumOfDigits(long long n, long long val = 0) {

        /**

         * @param n: number to sum digits of

         * @param val: value to add to sum of digits

         * @return: sum of digits of n

         */

        if (n < 10) {

            val = val + n;

            return val;

        }

        return sumOfDigits(n / 10, (n % 10) + val);

    }



    long long factorial(long long n) {

        /**

         * @param n: number to find factorial of

         * @return: factorial of n

         */

         long long fact[21] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};

         return fact[n];

    }



    long long nCr(long long n, long long r) {

        /**

         * @param n: number of elements

         * @param r: number of elements to choose from

         * @return: nCr of n and r

         */

        return factorial(n) / (factorial(r) * factorial(n - r));

    }



    bool isPowerOfTwo(long long n) {

        /**

         * @param n: number to check if it is a power of two

         * @return: true if n is a power of two, false otherwise

         */

        return n && !(n & (n-1));

    }



    bool isPrime(long long n) {

        /**

         * @param n: number to check if it is a prime

         * @return: true if n is a prime, false otherwise

         */

        if (n == 1)

            return false;

        int i = 2;

        while (i*i <= n) {

            if (n % i == 0)

                return false;

            i += 1;

        }

        return true;

    }



    void rotateMatrix(vector<vector<char>>& matrix) {

        /**

         * @param matrix: matrix to rotate by 90 degrees

         */

        long n = matrix.size();

        for (int i = 0; i < n / 2; i++) {

            for (int j = i; j < n - i - 1; j++) {

                char temp = matrix[i][j];

                matrix[i][j] = matrix[n - j - 1][i];

                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];

                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];

                matrix[j][n - i - 1] = temp;

            }

        }

    }



    //Main code starts here

    void execute() {

        int n;

        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)

            cin >> a[i];

        if(n % 2 != 0) {

            cout << "NO" << '\n';

            return;

        }

        vector<int> res(n);

        sort(a.begin(), a.end());

        int i = 0, j = n/2, k = 0;

        while(i <= n/2-1 and j <= n-1) {

            res[k++] = a[i++];

            res[k++] = a[j++];

        }

        if(res[0] == res[n-1]) {

            cout << "NO" << '\n';

            return;

        }

        for(k = 0; k < n-1; k++) {

            if(res[k] == res[k+1]) {

                cout << "NO" << '\n';

                return;

            }

        }

        cout << "YES" << '\n';

        for(k = 0; k < n; k++)

            cout << res[k] << ' ';

        cout << '\n';

    }



public:

    explicit Problem(int t = 1): tc(t) {

        cin >> tc;

    }

    void solve() {

        while(tc--) {

            execute();

        }

    }

};



int main() {

    fast_io

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    Problem().solve();

    return 0;

}