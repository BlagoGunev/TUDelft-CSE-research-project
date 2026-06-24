#include <bits/stdc++.h>
using namespace std;
#define inout0 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using ll [[maybe_unused]] = long long;
using ld [[maybe_unused]] = long double;
using flag [[maybe_unused]] = bool;
template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &i: v)
        in >> i;
    return in;
}
template<typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
    if (is_same<T, pair<int, int>>::value) {
        for (auto &i: v)
            out << i << '\n';
    } else {
        for (auto &i: v)
            out << i << " ";
    }
    return out;
}

vector<pair<int, int>> heap;

void sift_down(int n) {
    if (heap.size() == (2 * n + 1)) {
        if (heap[n].first < heap[2 * n + 1].first) {
            return;
        }
        else {
            int tmp = heap[2 * n + 1].first;
            heap[2 * n + 1] = heap[n];
            heap[n].first = tmp;
            sift_down(2 * n + 1);
        }
    }
    else if (heap.size() >= (2 * n + 2)) {
        if (heap[n].first < heap[2 * n + 1].first && heap[n].first < heap[2 * n + 2].first) {
            return;
        } else {
            if (min(heap[2 * n + 1].first, heap[2 * n + 2].first) == heap[2 * n + 1].first) {
                int tmp = heap[2 * n + 1].first;
                heap[2 * n + 1] = heap[n];
                heap[n].first = tmp;
                sift_down(2 * n + 1);
            }
            else {
                int tmp = heap[2 * n + 2].first;
                heap[2 * n + 2] = heap[n];
                heap[n].first = tmp;
                sift_down(2 * n + 2);
            }
        }
    }
}

void sift_up(int n) {
    if (n != 0) {
        if (heap[n].first < heap[(n - 1) / 2].first) {
            int tmp = heap[(n - 1) / 2].first;
            heap[(n - 1) / 2] = heap[n];
            heap[n].first = tmp;
            sift_up((n - 1) / 2);
        }
    }
}

int my_find(int n) {
    for (int i = 0; i < heap.size(); ++i) {
        if (heap[i].second == n) {
            return i;
        }
    }
}

void prosto_remove(int n) {
    int tp = my_find(n);
    heap[tp] = heap[heap.size() - 1];
    heap.pop_back();
    sift_down(tp);
}

void insert(int num, int n) {
    heap.emplace_back(num, n);
    sift_up(heap.size() - 1);
}

void solve() {
    string str;
    cin >> str;
    int i_f = -1;
    int i_l = -1;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '1') {
            i_f = i;
            break;
        }
    }
    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] == '1') {
            i_l = i;
            break;
        }
    }
    ll ans = 0;
    for (int i = i_f; i <= i_l; ++i) {
        if (str[i] == '0') {
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    inout0;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}