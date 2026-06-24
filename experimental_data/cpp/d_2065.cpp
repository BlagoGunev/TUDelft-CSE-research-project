#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long calculateScore(const vector<vector<int>>& arrays, int n, int m) {
    vector<long long> sums(n);
    
    // Calculate the sum of each array
    for (int i = 0; i < n; i++) {
        sums[i] = 0;
        for (int j = 0; j < m; j++) {
            sums[i] += arrays[i][j];
        }
    }
    
    // Sort arrays by their sum in descending order
    vector<int> indices(n);
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }
    
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return sums[i] > sums[j];
    });
    
    // Now calculate the score for the optimal order
    long long totalScore = 0;
    long long prefixSum = 0;
    
    // Iterate through the sorted arrays
    for (int i = 0; i < n; i++) {
        int idx = indices[i];
        // Add the array's elements to the prefix sum
        for (int j = 0; j < m; j++) {
            prefixSum += arrays[idx][j];
            totalScore += prefixSum;
        }
    }
    
    return totalScore;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    
    while (t--) {
        int n, m;
        cin >> n >> m; // Number of arrays and length of each array
        
        vector<vector<int>> arrays(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arrays[i][j]; // Reading each array's elements
            }
        }
        
        // Calculate and print the maximum score for this test case
        cout << calculateScore(arrays, n, m) << endl;
    }
    
    return 0;
}