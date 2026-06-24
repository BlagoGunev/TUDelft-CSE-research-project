#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValidOrder(vector<vector<int>>& decks, vector<int>& order) {
    int n = decks.size();
    int m = decks[0].size();
    vector<int> indices(n, 0);
    int topCard = -1;

    for (int round = 0; round < m; round++) {
        for (int i = 0; i < n; i++) {
            int cow = order[i];
            while (indices[cow] < m && decks[cow][indices[cow]] <= topCard) {
                indices[cow]++;
            }
            if (indices[cow] == m) {
                return false;
            }
            topCard = decks[cow][indices[cow]];
            indices[cow]++;
        }
    }
    return true;
}

vector<int> solve(int n, int m, vector<vector<int>>& decks) {
    vector<pair<int, int>> smallestCards;

    for (int i = 0; i < n; i++) {
        sort(decks[i].begin(), decks[i].end());
        smallestCards.push_back({decks[i][0], i});
    }

    sort(smallestCards.begin(), smallestCards.end());
    vector<int> order;
    for (auto& p : smallestCards) {
        order.push_back(p.second);
    }

    if (isValidOrder(decks, order)) {
        for (int i = 0; i < n; i++) {
            order[i]++;
        }
        return order;
    }

    return vector<int>{-1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> decks(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> decks[i][j];
            }
        }
        
        vector<int> result = solve(n, m, decks);
        if (result[0] == -1) {
            cout << -1 << "\n";
        } else {
            for (int x : result) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}