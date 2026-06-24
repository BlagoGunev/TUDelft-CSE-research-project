#include<bits/stdc++.h>
using namespace std;
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define pb             emplace_back
#define mp             make_pair
#define F              first
#define S              second
#define rep(i, x)      for (__typeof(x) i = 0; i < x; i ++)
#define repp(i, x, y)  for (__typeof(x) i = x; i < y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i--)
#define all(a)         (a).begin(),(a).end()
#define endl           '\n'
#define DB(x)          cerr << #x << " is " << x << endl;
typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>        vi;
typedef set<int>           si;

int main(){ _
    string c = "AHIMOoTUVvWwXxY";
    map<char, char> m= {{'b', 'd'}, {'d','b'}, {'p','q'}, {'q','p'}};
    string s; cin >> s;
    int l = s.size();

    if (l%2){
        if (c.find(s[l/2]) == string::npos){
            cout << "NIE"; return 0;
        }
    }

    for(int i=0;i<s.size();i++){
        if (c.find(s[i]) != string::npos){
            if (s[i] != s[l-i-1]) {cout << "NIE"; return 0;}
        } else if (m[s[i]]){
            if (s[l-i-1] != m[s[i]]) {cout << "NIE"; return 0;}
        } else {
            cout << "NIE"; return 0;
        }
    }
    cout << "TAK";
}