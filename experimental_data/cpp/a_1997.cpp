#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the typing time of a given string
int calculateTypingTime(const string& str) {
    int time = 2; // time for the first character
    for (size_t i = 1; i < str.size(); ++i) {
        if (str[i] == str[i - 1])
            time += 1;
        else
            time += 2;
    }
    return time;
}

int main() {
    int t;
    cin >> t;
    vector<string> results;

    while (t--) {
        string s;
        cin >> s;
        int maxTime = 0;
        string bestString;

        // Try inserting each letter from 'a' to 'z' at every possible position
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            for (size_t i = 0; i <= s.size(); ++i) {
                string newString = s.substr(0, i) + ch + s.substr(i);
                int currentTime = calculateTypingTime(newString);
                if (currentTime > maxTime) {
                    maxTime = currentTime;
                    bestString = newString;
                }
            }
        }
        results.push_back(bestString);
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}