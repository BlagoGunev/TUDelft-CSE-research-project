#ifdef LOCAL

    #include "debug.h"

#else

    #define deb(x...)

#endif

// #define deb(x...)



#include <bits/stdc++.h>

using namespace std;



void single_test() {

    string s;

    cin >> s;



    int n = int(s.size());



    // dp?

    // if we append a zero, remove one more from the right or remove the entire string from the left

    // if we append a one, the answer is either to also remove this one or to not remove anything from the right



    vector<int> pre_num0(n + 1, 0);

    vector<int> pre_num1(n + 1, 0);

    for (int i = 0; i < n; i++) {

        if (s[i] == '0') {

            pre_num0[i + 1] = pre_num0[i] + 1;

            pre_num1[i + 1] = pre_num1[i];

        } else {

            pre_num0[i + 1] = pre_num0[i];

            pre_num1[i + 1] = pre_num1[i] + 1;

        }

    }



    int left = 0;

    int right = 0;



    int min_cost = pre_num0[n];



    while (left < n) {

        // cost of advancing right

        int cost_right = INT_MAX;

        if (right < n) {

            cost_right = max(pre_num0[right + 1] - pre_num0[left], pre_num1[n] - (pre_num1[right + 1] - pre_num1[left]));

        }



        // cost of advancing left

        int cost_left = max(pre_num0[right] - pre_num0[left + 1], pre_num1[n] - (pre_num1[right] - pre_num1[left + 1]));



        if (cost_left < cost_right) {

            left++;

        } else {

            right++;

        }



        min_cost = min(min_cost, min(cost_right, cost_left));

    }



    cout << min_cost << '\n';

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);



    int t = 1;

    cin >> t;



    for (int test = 0; test < t; test++) {

        single_test();

    }



    #ifdef LOCAL

        cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << " s\n";

    #endif



    return 0;

}