#include <iostream>

#include <vector>

#include <algorithm>

#include <fstream>

#include <tuple>

#include <cmath>

#include <string>

#include <deque>

#include <map>

#include <set>

#include <iomanip>

#include <stack>

using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int>p(n);

    for(int i = 0; i < n; i++) cin >> p[i];

    int maximum = 0;

    vector<pair<int, int>>ans; map<int, int>gavs;

    int i = 0;

    for(; i < n;){

        auto j = i;

        while(i < n - 1 && p[i] < p[i + 1]){

            i++;

        }

        maximum = max(maximum, i - j + 1); gavs[i - j + 1]++;

        if(i == n - 1){ ans.push_back({i - j + 1, 0}); break;}

        auto l = i - j + 1; j = i;

        while(i < n - 1 && p[i] > p[i + 1]){

            i++;

        }

        ans.push_back({l, i - j + 1});

        maximum = max(maximum, i - j + 1);

        gavs[i - j + 1]++;

    }

    int good = 0;

    for(auto val: ans){

        if(val.first == val.second && val.first == maximum && val.first % 2 == 1 && gavs[maximum] == 2){

            good++;

        }

    }

    cout << good;

}