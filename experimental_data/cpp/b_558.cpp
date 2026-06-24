#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int freq[1000006];

int main()
{
    int n, x;
    int maxi = -1;
    scanf("%d", &n);
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.push_back(make_pair(x, i));
        freq[x]++;
        if (freq[x] > maxi) {
            maxi = freq[x];
        }
    }
    stable_sort(v.begin(), v.end());
    int i = 0;
    int l = 0;
    int r = v.size()-1;
    while (i < v.size()) {
        while (i < v.size() && freq[v[i].first] < maxi) {
            i++;
        }
        int l1 = 0;
        int r1 = v.size()-1;
        if (i < v.size() && freq[v[i].first] == maxi) {
            l1 = v[i].second;
            i += maxi-1;
            r1 = v[i].second;
            if (l1 > r1) {
                int t = l1;
                l1 = r1;
                r1 = t;
            }
            i++;
            if (r1-l1 < (r-l+1)) {
                l = l1;
                r = r1;
            }
        }
    }
    cout << l+1 << " " << r+1 << endl;

    return 0;
}