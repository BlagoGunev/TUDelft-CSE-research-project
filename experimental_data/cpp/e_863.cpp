// #include <bits/stdc++.h>

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<pair<pair<int,int>, int> > v;
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf(" %d %d", &l, &r);
		v.push_back(make_pair(make_pair(l, -r), i+1));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int l = v[i].first.first, r = -v[i].first.second, idx = v[i].second;
		int j;
		int far = r;
		for (j = i; j < v.size(); j++) {
			int l2 = v[j].first.first, r2 = -v[j].first.second, idx2 = v[j].second;
			if (l2 > r+1) break;
			far = max(far, r2);
		}
		if (j - i > 1) {
			for (int j = i; j < v.size(); j++) {
				int l2 = v[j].first.first, r2 = -v[j].first.second, idx2 = v[j].second;
				if (l2 > r+1) break;
				if (r2 < far && idx2 != idx) {
					printf("%d\n", idx2);
					return 0;
				}
				if (r2 == far) far++;
			}
		}
	}
	printf("-1\n");
	return 0;
}