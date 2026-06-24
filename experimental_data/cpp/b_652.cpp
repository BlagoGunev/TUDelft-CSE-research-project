#include <bits/stdc++.h>
#define Fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define all_r(x) (x).rbegin(), (x).rend()
#define mnEl(vec) *min_element(vec.begin(), vec.end())
#define mxEl(vec) *max_element(vec.begin(), vec.end())
#define yes cout << "YES"
#define no cout << "NO"
#define in(v) for (auto & x : v) cin >> x
#define out(v) for (auto & x : v) cout << x << ' '
#define inLL(v) for (ll & x : v) cin >> x
#define openIn(x) freopen(x, "r", stdin);
#define openOut(x) freopen(x, "w", stdout);

using namespace std;

void merge(int start, int mid, int end, vector<int> &v) {
    int p = start, q = mid + 1, size = end - start + 1, i = 0;
    vector<int> temp(size);

    for (; i < size; ++i) {
        // checks if p or q is out of bounds
        if (q > end || p > mid)
            break;

        // places the smaller element in the temp array
        if (v[p] > v[q])
            temp[i] = v[q++];
        else
            temp[i] = v[p++];
    }

    // copies what's left in 1st array to temp
    while (p <= mid)
        temp[i++] = v[p++];

    // copies what's left in 2nd array to temp
    while (q <= end)
        temp[i++] = v[q++];

    // copies temp array to original array
    i = 0;
    for (int j = start; j <= end; ++j)
        v[j] = temp[i++];
}

void mergeSort(int l, int r, vector<int> &v) {

    if (l >= r)
        return;

    int m = (l + r) / 2;
    mergeSort(l, m, v);
    mergeSort(m + 1, r, v);
    merge(l, m, r, v);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    deque<int> asc, desc;
    in(v);
    mergeSort(0, n - 1, v);
    if (n % 2) {
        for (int i = 0; i < n; ++i) {
            if (i <= n / 2)
                asc.push_back(v[i]);
            else
                desc.push_front(v[i]);
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (i < n / 2)
                asc.push_back(v[i]);
            else
                desc.push_front(v[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            cout << asc.front() << ' ';
            asc.pop_front();
        } else {
            cout << desc.front() << ' ';
            desc.pop_front();
        }
    }

}

int main() {
    Fast
//    int t;
//    cin >> t;
//    while (t--)
    solve();
    return 0;
}