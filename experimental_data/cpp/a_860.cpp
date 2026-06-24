#include <bits/stdc++.h>
#define A first
#define B second
#define endl '\n'
#define T double
#define pb emplace_back
using namespace std;
typedef pair<int, int> PII;
typedef vector<int> VI;
int dp[3001]; //dp stores the fewest number of words need to have the first i characters covered
bool vowel[26];
int main(){
    string s; cin >> s;
    memset(vowel, 0, sizeof(vowel));
    vowel['a' - 'a'] = true;
    vowel['e' - 'a'] = true;
    vowel['i' - 'a'] = true;
    vowel['o' - 'a'] = true;
    vowel['u' - 'a'] = true;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= s.size(); i++){
        dp[i] = 9000;
        char ch = s[i - 1];
        int endlen = (1 - vowel[ch - 'a']);
        bool distinct = false;
        char common = ch;
        for (int j = i - 2; j >= 0; j--){
            if (vowel[s[j] - 'a']){
                distinct = false;
                common = 'a';
                endlen = 0;
            }
            else{
                endlen++;
                if (endlen > 1){
                    if (s[j] != common){
                        distinct = true;
                    }
                }
                if (endlen == 1){
                    common = s[j];
                    distinct = false;
                }
            }
            if (distinct && (endlen >= 3)){
                break;
            }
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    for (int i = 1; i < s.size(); i++){
        cout << s[i - 1];
        if (dp[i] != dp[i + 1]){
            cout << ' ';
        }
    }
    cout << s[s.size() - 1] << endl;
}