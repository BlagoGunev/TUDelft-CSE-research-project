#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string result = "0000000000";
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            for(int j = 0; j < 10; j++){
                if(result[j] == '0'){
                    result[j] = '1';
                    break;
                }
            }
        }
        else if(s[i] == 'R'){
            for(int j = 9; j >= 0; j--){
                if(result[j] == '0'){
                    result[j] = '1';
                    break;
                }
            }
        }
        else{
            result[s[i]-'0'] = '0';
        }
    }
    cout << result;
    return 0;
}