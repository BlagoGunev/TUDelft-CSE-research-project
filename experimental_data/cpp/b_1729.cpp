#include <bits/stdc++.h>
using  namespace std;
#define noor ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define e '\n'
#define yes cout << "YES"
#define no cout << "NO"
#define N 3


void solve(){
    //char a[] = "abcdefghijklmnopqrstuvwxyz";
    string s, res;
    int n, id;
    cin >> n;
    cin >> s;
    for (int i=n-1; i >= 0; i--){
        string t;
        if (s[i] == '0'){
            t+= s[i-2];
            t+= s[i-1];
            i-=2;
        }
        else{
            t+= s[i];
        }
        int x = stoi(t);
        x--;
        char c = (x+'a');
        res += c;
    }
    reverse(res.begin(), res.end());
    cout << res << e;
}

int main() {
    noor
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
}