#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <random>
#include <cfloat>
#include <chrono>
#include <bitset>
#include <complex>
#include <functional>
#include <immintrin.h>
#include <memory>

struct Node {
    std::pair<int32_t, int32_t> min;
    std::pair<int32_t, int32_t> max;
};

Node* segtree;

void build(int32_t node, int32_t left, int32_t right, int32_t* arr) {
    if(right - left == 1) {
        segtree[node] = {{0, arr[left]}, {1, arr[left]}};
        return;
    }
    int32_t m = (left + right) / 2;
    build(node * 2 + 1, left, m, arr);
    build(node * 2 + 2, m, right, arr);
    segtree[node] = {std::min(segtree[node * 2 + 1].min, segtree[node * 2 + 2].min), std::max(segtree[node * 2 + 1].max, segtree[node * 2 + 2].max)};
}

void update(int32_t node, int32_t left, int32_t right, int32_t ind, Node val) {
    if(right - left == 1) {
        segtree[node] = val;
        return;
    }
    int32_t m = (left + right) / 2;
    if(ind >= m)
        update(node * 2 + 2, m, right, ind, val);
    else
        update(node * 2 + 1, left, m, ind, val);
    segtree[node] = {std::min(segtree[node * 2 + 1].min, segtree[node * 2 + 2].min), std::max(segtree[node * 2 + 1].max, segtree[node * 2 + 2].max)};
}

Node query(int32_t node, int32_t left, int32_t right, int32_t query_left, int32_t query_right) {
    if(left >= query_left && right <= query_right)
        return segtree[node];
    if(left >= query_right || right <= query_left)
        return {{1, 0}, {0, 0}};
    int32_t m = (left + right) / 2;
    Node res_left = query(node * 2 + 1, left, m, query_left, query_right);
    Node res_right = query(node * 2 + 2, m, right, query_left, query_right);
    return {std::min(res_left.min, res_right.min), std::max(res_left.max, res_right.max)};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int32_t num_tests;
    std::cin >> num_tests;

    for(int32_t t = 0; t < num_tests; t++) {
        int32_t n;
        std::cin >> n;

        int32_t* arr = new int32_t[n];
        for(int32_t i = 0; i < n; i++)
            std::cin >> arr[i];

        segtree = new Node[4 * n];
        build(0, 0, n, arr);

        std::map<int32_t, std::vector<int32_t>> occ;
        for(int32_t i = 0; i < n; i++)
            occ[arr[i]].push_back(i);

        std::set<std::pair<int32_t, int32_t>> alive;
        for(auto it = occ.begin(); it != occ.end(); it++)
            alive.emplace(it->second.back(), it->first);

        int32_t start = 0;
        std::vector<int32_t> ans;
        while(!alive.empty()) {
            int32_t right = alive.begin()->first;

            int32_t next_num;
            if(ans.size() % 2 == 0)
                next_num = query(0, 0, n, start, right + 1).max.second;
            else
                next_num = query(0, 0, n, start, right + 1).min.second;

            ans.push_back(next_num);
            start = (*std::lower_bound(occ[next_num].begin(), occ[next_num].end(), start)) + 1;
            alive.erase({occ[next_num].back(), next_num});

            for(int32_t pos : occ[next_num])
                update(0, 0, n, pos, {{1, 0}, {0, 0}});
        }

        std::cout << ans.size() << "\n";
        for(int32_t i = 0; i < ans.size(); i++)
            std::cout << ans[i] << " ";
        std::cout << "\n";
    }
}