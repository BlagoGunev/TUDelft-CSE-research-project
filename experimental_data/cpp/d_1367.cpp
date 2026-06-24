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
    string S;
    cin >> S;

    map<char, int> K;
    for (auto &s : S)
        K[s]++;

    int M;
    cin >> M;

    vector<int> A(M);
    for (auto &a : A)
        cin >> a;

    string out(M, '?');

    auto current = K.end();
    while (true) {
        assert(current != K.begin());
        current--;

        int zeros = count(A.begin(), A.end(), 0);
        while (current->second < zeros) {
            assert(current != K.begin());
            current--;
        }

        for (int i = 0; i < M; i++)
            if (A[i] == 0)
                out[i] = current->first;
            else if (A[i] == -1)
                A[i] = -1e9;

        for (auto &a : A)
            if (a == 0)
                a = -1;

        for (int i = 0; i < M; i++)
            if (A[i] > 0) {
                int score = 0;
                for (int j = 0; j < M; j++)
                    if (A[j] == -1)
                        score += abs(i - j);
                A[i] -= score;
            }

        if (current == K.begin())
            break;
    }

    cout << out;
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