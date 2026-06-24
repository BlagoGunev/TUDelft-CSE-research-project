#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    string s;
    int idx=0;
    int score=0;
    vector<string> used;
    cin >> n >> k;
    cin >> s;
    used.push_back(s);
    while(used.size() < k){
        if(idx >= used.size()){
            score = -1;
            break;
        }
        string ss = used[idx];
        for(int i=0;i<ss.size();++i){
            string sss = ss.substr(0, i) + ss.substr(i+1, ss.size()-(i+1));
            if(find(used.begin(), used.end(), sss) != used.end()){
                continue;
            }
            used.push_back(sss);
            score += n - sss.size();
            if(used.size() >= k){
                break;
            }
        }
        idx++;
    }
    cout << score << endl;
    return 0;
}