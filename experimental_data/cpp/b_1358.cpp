#include <bits/stdc++.h>

using namespace std;

#pragma optimization_level 3

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")

// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

// Datatypes Begin

#define int long long int

#define double long double

#define longlong long long

#define __int64 int

// Datatypes End

// Constants Begin

#define PI 3.14159265358979323846264338327950288419716939937510l

const string PI_string = "314159265358979323846264338327950288419716939937510";

const int MAX_N = 1e5 + 5, MOD = 1e9 + 7, INF = 1e9, EPS = 1e-9;

// Constants End

// Definitions Begin

void fast_io() {

    ios::sync_with_stdio(false);

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin.tie(NULL);

    cout.tie(0);

    cout.tie(NULL);

}

#define all(a) a.begin(), a.end()

void fix_prec(int prec) {

    cout << fixed << setprecision(prec);

}

// Definitions End

// Custom Structs and Classes Begin

struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        // http://xorshift.di.unimi.it/splitmix64.c

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);

    }

    size_t operator()(uint64_t x) const {

        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + FIXED_RANDOM);

    }

};

// Custom Structs and Classes End

// Functions Begin

void open_file(string input, string output) {

    freopen(input.c_str(), "r", stdin);

    freopen(output.c_str(), "w", stdout);

}

void usaco(string filename) {

    freopen((filename + ".in").c_str(), "r", stdin);

    freopen((filename + ".out").c_str(), "w", stdout);

}

template <typename T> T gcd(T a, T b) {

    return (b ? __gcd(a, b) : a);

}

template <typename T> T lcm(T a, T b) {

    return (a * (b / gcd(a, b)));

}

unordered_map<int, int, custom_hash> factorials;

int factorial(int n) {

    if (n < 0)

        return 0;

    if (n <= 1)

        return 1;

    if (factorials.find(n) != factorials.end())

        return factorials[n];

    return factorials[n] = (n * factorial(n - 1));

}

int nCr(int n, int r) {

    return factorial(n) / (factorial(r) * factorial(n - r));

}

int nPr(int n, int r) {

    return factorial(n) / factorial(n - r);

}

template<typename T> T power(T a, T n, T mod) {

    T power = a, result = 1;

    while (n) {

        if (n & 1) {

            result = (result * power) % mod;

        }

        power = (power * power) % mod;

        n >>= 1;

    }

    return result;

}

template<typename T> bool witness(T a, T n) {

    int t, u, i;

    std::int64_t prev, curr;

    u = n / 2;

    t = 1;

    while (!(u & 1)) {

        u /= 2;

        ++t;

    }

    prev = power(a, u, n);

    for (i = 1; i <= t; ++i) {

        curr = (prev * prev) % n;

        if ((curr == 1) && (prev != 1) && (prev != n - 1)) {

            return true;

        }

        prev = curr;

    }

    if (curr != 1) {

        return true;

    }

    return false;

}

template<typename T> bool is_prime(T number) {

    if (((!(number & 1)) && number != 2) || (number < 2) || (number % 3 == 0 && number != 3))

        return false;

    if (number < 1373653) {

        for (int k = 1; 36 * k * k - 12 * k < number; ++k)

            if ((number % (6 * k + 1) == 0) || (number % (6 * k - 1) == 0))

                return false;

        return true;

    }

    if (number < 9080191) {

        if (witness(std::int64_t(31), number))

            return false;

        if (witness(std::int64_t(73), number))

            return false;

        return true;

    }

    if (witness(std::int64_t(2), number))

        return false;

    if (witness(std::int64_t(7), number))

        return false;

    if (witness(std::int64_t(61), number))

        return false;

    return true;

}

// GEO

template <typename T>

inline T PointDistanceHorVer(T x1, T y1, T x2, T y2) {

    return abs(x1 - x2) + abs(y1 - y2);

}

template <typename T > inline T PointDistanceDiagonally(T x1, T y1, T x2, T y2) {

    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

}

template <typename T > inline T PointDistanceMinimum(T x1, T y1, T x2, T y2) {

    T tmp1 = abs(x1 - x2), tmp2 = abs(y1 - y2), tmp3 = abs(tmp1 - tmp2), tmp4 = min(tmp1, tmp2);

    return tmp3 + tmp4;

}

template <typename T> inline T PointDistance3D(T x1, T y1, T z1, T x2, T y2, T z2) {

    return sqrt(square(x2 - x1) + square(y2 - y1) + square(z2 - z1));

}

template <typename T> inline T Cube(T a) {

    return a * a * a;

}

template <typename T> inline T RectengularPrism(T a, T b, T c) {

    return a * b * c;

}

template <typename T> inline T Pyramid(T base, T height) {

    return (1 / 3) * base * height;

}

template <typename T> inline T Ellipsoid(T r1, T r2, T r3) {

    return (4 / 3) * PI * r1 * r2 * r3;

}

template <typename T> inline T IrregualarPrism(T base, T height) {

    return base * height;

}

template <typename T> inline T Sphere(T radius) {

    return (4 / 3) * PI * radius * radius * radius;

}

template <typename T> inline T CylinderB(T base, T height) {

    return base * height;

}

template <typename T> inline T CylinderR(T radius, T height) {

    return PI * radius * radius * height;

}

template <typename T> inline T Cone(T radius, T base, T height) {

    return (1 / 3) * PI * radius * radius * height;

}

// Functions End

void solve(int tt = 0) {

    int n;

    cin >> n;

    vector<int> a(n);

    for (int &i : a)

        cin >> i;

    sort(all(a));

    for (int i = n - 1; i >= 0; i--)

        if (a[i] <= i + 1) {

            cout << i + 2 << endl;

            return;

        }

    cout << 1 << endl;

}

#define test_cases

int32_t main(void) {

    fast_io();

    #ifdef test_cases

        int tc = 1;

        cin >> tc;

        for (int t = 1; t <= tc; t++)

            solve(t);

    #else

        solve();

    #endif

}

/*

By Thamognya Kodi

                                      ▓▓▓▓▓▓  ▓▓▓▓▓▓

                                      ▓▓  ░░▓▓▓▓  ▓▓▓▓▓▓

                                ▓▓▓▓▓▓▓▓░░  ░░▓▓░░░░▓▓▓▓  ▓▓

                              ▒▒▓▓░░  ▓▓░░░░░░░░░░░░▓▓░░░░▓▓

                                  ▒▒░░  ░░░░░░░░░░░░░░░░▓▓▓▓▒▒

                                  ▓▓░░░░░░░░░░░░░░░░░░░░▓▓░░▓▓

                ██████████    ▒▒▓▓░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░▓▓

            ██████      ██████    ▓▓▓▓▓▓▓▓▓▓▓▓▒▒    ▒▒▒▒▒▒▓▓▓▓

          ████              ████████▓▓▓▓▓▓▓▓▓▓▒▒    ▒▒  ▒▒▓▓

        ████                  ██████░░  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓

                          ██████████░░  ░░░░░░██░░░░░░████

                    ██████████    ██░░░░░░░░░░▒▒░░░░░░▒▒██

              ██████████          ██░░░░░░░░░░░░░░░░░░░░██

        ██████████                  ████░░░░░░░░░░░░░░░░██

      ██████                          ████░░░░░░▒▒▒▒░░██

    ████                              ██▓▓██░░░░░░░░██

  ████                          ████████▓▓▓▓████████

  ██                          ████▓▓▓▓▓▓████████▓▓██████

  ██                        ████▓▓▓▓▓▓▓▓▓▓██████▓▓██▓▓▓▓██

                          ▓▓████▓▓▓▓██▓▓▓▓▓▓▓▓██▓▓██▓▓██▓▓▓▓

                        ████████▓▓▓▓██▓▓▓▓▓▓▓▓██▓▓██▓▓██▓▓██

                      ██▓▓▓▓▓▓▓▓████████████████▓▓██████▓▓██

                      ██▓▓██▓▓▓▓████▒▒░░░░  ░░░░▓▓██▒▒██▓▓██

                    ██▓▓▓▓██████████▒▒  ░░░░    ▓▓██▒▒██▓▓████

                    ██▓▓▓▓▓▓████  ██▒▒░░    ░░░░▓▓██▒▒▒▒██████

                  ██▓▓▓▓▓▓▓▓██    ██▒▒░░░░      ▓▓██▒▒▒▒██▓▓██

                  ██▓▓▓▓▓▓▓▓██    ██▒▒░░░░░░░░░░░░▓▓██▒▒██▓▓██

                ██▓▓▓▓████▓▓██    ████▒▒░░    ░░░░▓▓██▒▒██▓▓▓▓██

                ██▓▓██░░░░██        ████████▓▓▓▓▓▓▓▓████████▓▓▓▓████

                  ██░░░░████        ████████████████████████▓▓████░░████

                ██░░░░░░░░██        ██▒▒░░░░░░░░░░░░░░░░████▓▓██░░░░░░░░██

                ██░░░░░░░░░░██      ██░░    ░░░░░░░░░░░░░░░░████░░░░░░░░██

                ██░░░░░░░░░░██      ██▒▒░░░░    ░░░░██░░░░░░████░░░░░░██

                ██░░░░░░░░██      ██▒▒  ▒▒▒▒▒▒░░░░░░██░░░░░░░░████████

                  ████████        ██████    ▒▒▒▒████░░████░░░░██

                                  ██    ████▒▒██  ████▒▒▒▒▒▒▒▒░░██

                                ██░░░░░░  ▒▒▒▒██    ██▒▒▒▒▒▒▒▒░░░░██

                                ██░░░░░░▒▒▒▒██        ██▒▒▒▒▒▒▒▒░░██

                              ██░░░░░░▒▒▒▒▒▒██        ██▒▒▒▒▒▒▒▒░░██

                            ██░░░░░░░░▒▒▒▒██            ██▒▒▒▒▒▒▒▒░░██

                            ██░░░░░░▒▒▒▒▒▒██            ██▒▒▒▒▒▒▒▒░░██

                          ██░░░░░░▒▒▒▒▒▒██              ██▒▒▒▒▒▒░░░░██

                        ██░░░░░░▒▒▒▒▒▒██                ██▒▒▒▒▒▒▒▒░░██

                        ██░░░░░░▒▒▒▒▒▒██                ██▒▒▒▒▒▒▒▒░░██

                          ██░░▒▒▒▒▒▒██                    ████████████

                        ████████████                        ████████

                        ██▓▓▓▓████                          ██▓▓▓▓██

                      ████████████                        ██▓▓██████████

                    ██▓▓▓▓▓▓▓▓██                          ██▓▓▓▓▓▓▓▓▓▓▓▓████

                  ██▓▓▓▓▓▓▓▓▓▓██                          ██████▓▓▓▓▓▓░░░░░░██

                ██▓▓░░░░░░░░████                                ██████████████

                ██████████████

*/