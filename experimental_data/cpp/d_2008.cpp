#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    vector<int> F(n, 0);
    vector<bool> visited(n, false);
    string s;
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--; // Convert to 0-indexed
    }
    
    cin >> s;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> cycle;
            int current = i;
            int black_count = 0;
            
            // Trace the cycle
            while (!visited[current]) {
                visited[current] = true;
                cycle.push_back(current);
                if (s[current] == '0') {
                    black_count++;
                }
                current = p[current];
            }
            
            // Assign the black count to all elements in this cycle
            for (int index : cycle) {
                F[index] = black_count;
            }
        }
    }
    
    // Output the result
    for (int i = 0; i < n; ++i) {
        cout << F[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}