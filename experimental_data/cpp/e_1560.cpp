#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

bool used[26];
int cnt[26];

string del(string word, char rem){
    string s = "";
    for(int i = 0; i < word.size(); i++){
        if(word[i] != rem){
            s += word[i];
        }
    }
    
    return s;
}

bool check(string s, string key, string word){
    string result = "";
    for(int i = 0; i < key.size(); i++){
        result += word;
        word = del(word, key[i]);
    }
    return result == s;
}

void solve(){
    string s; cin >> s;
    string order = "";
    for(int i = s.size()-1; i >= 0; i--){
        if(!used[s[i]-'a']){
            order += s[i];
            used[s[i]-'a'] = true;
        }
    }

    reverse(order.begin(), order.end());

    for(int i = 0; i < s.size(); i++){
        cnt[s[i]-'a']++;
    }

    int length = 0;
    
    for(int i = 0; i < order.size(); i++){
        if((cnt[order[i]-'a'] % (i+1)) != 0){
            cout << -1 << endl;
            for(int i = 0 ; i < 26; i++){
                used[i] = false;
                cnt[i] = 0;
            }
            return;
        }
        else{
            length += cnt[order[i]-'a'] / (i+1);
        }
    }

    string result = s.substr(0, length);

    if(check(s, order, result)){
        cout << result << " " << order << endl;
    }
    else{
        cout << -1 << endl;
    }

    for(int i = 0 ; i < 26; i++){
        used[i] = false;
        cnt[i] = 0;
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1; cin >> n;
  while(n--){
    solve();
  }
}