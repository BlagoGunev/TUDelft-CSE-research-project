#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int tam = s.size();
    map<char, int> m;
    for(int i=0;i<tam;i++){
        m[s[i]]++;
    }

    cout << (m.size()%2 != 0 ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;

    return 0;
}