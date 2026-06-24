#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

#ifdef imtiyazrasool92
#include "algos/debug.h"
#else
#define dbg(...) 92
#endif

void run_case() {
    int N; string S;
    cin >> N >> S;

    vector<int> A(N);
    vector<int> B(N);

    iota(A.begin(), A.end(), 1);
    iota(B.begin(), B.end(), 1);

    reverse(A.begin(), A.end());

    for (int i = 0; i < N - 1;) {
        int end = i;
        while (end + 1 < N - 1 && S[end] == S[end + 1])
            end++;

        if (S[i] == '<')
            reverse(A.begin() + i, A.begin() + end + 2);
        else
            reverse(B.begin() + i, B.begin() + end + 2);

        i = end + 1;
    }

    for (auto &a : A)
        cout << a << ' ';

    cout << '\n';
    for (auto &b : B)
        cout << b << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifndef imtiyazrasool92
    cin.tie(nullptr);
#endif

    int tests = 1;
    cin >> tests;

    while (tests--) {
        run_case();
        cout << '\n';
    }

    return 0;
}