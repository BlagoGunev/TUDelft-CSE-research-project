#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	int n, r;
	scanf("%d%d", &n, &r);

	vector<pair<int, int> > positives;
	vector<pair<int, int> > negatives;
	int negativeDifferenceSum = 0;

	for(int i = 0 ; i < n ; ++i) {
		int ratingNeeded, ratingDifference;
		scanf("%d%d", &ratingNeeded, &ratingDifference);
		if(ratingDifference >= 0) {
			positives.push_back(make_pair(ratingNeeded, ratingDifference));
		}
		else {
			negatives.push_back(make_pair(ratingNeeded, ratingDifference));
			negativeDifferenceSum += ratingDifference;
		}
	}

	sort(positives.begin(), positives.end());

	for(int i = 0 ; i < positives.size() ; ++i) {
		if(positives[i].first <= r) {
			r += positives[i].second;
		}
		else {
			printf("NO");
			return 0;
		}
	}

	if(negativeDifferenceSum * -1 > r) {
		printf("NO");
		return 0;
	}

	int remainingNegatives = negatives.size();
	int iteration = 1;
	bool used[remainingNegatives];
	memset(used, false, sizeof(used));

	while(remainingNegatives) {
		if(iteration == 0) {
			printf("NO");
			return 0;
		}
		iteration = 0;
		for(int i = 0 ; i < negatives.size() ; ++i) {
			if(used[i])
				continue;
			//printf("ITERATING %d. R = %d, nDS = %d, second = %d, first = %d\n", i, r, negativeDifferenceSum, negatives[i].second, negatives[i].first);
			if(r + negativeDifferenceSum - negatives[i].second >= negatives[i].first) {
				iteration++;
				remainingNegatives--;
				used[i] = true;
				negativeDifferenceSum -= negatives[i].second;
			}
		}
	}

	printf("YES");

	return 0;
}