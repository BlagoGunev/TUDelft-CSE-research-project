#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<char>> grid(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        // Create the reduced grid
        vector<vector<char>> reducedGrid(n / k, vector<char>(n / k));
        for (int i = 0; i < n; i += k) {
            for (int j = 0; j < n; j += k) {
                reducedGrid[i / k][j / k] = grid[i][j];
            }
        }

        // Output the reduced grid
        for (int i = 0; i < n / k; ++i) {
            for (int j = 0; j < n / k; ++j) {
                cout << reducedGrid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}