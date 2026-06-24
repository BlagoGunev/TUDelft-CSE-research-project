#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<iterator>
#include<unordered_map>
#include<set>
//#include "utility.h"
using namespace std;
#define int long long
#define ll long long
#define all(v) v.begin(), v.end()
#define Rall(v) v.rbegin(), v.rend()
#define L '\n'
void YF12() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void IO(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
template <typename T = int>ostream& operator<<(ostream& out, const vector<T>& v) {
    for (const auto& x : v) {
        out << x << " ";
    }
    return out;
}


void doWork() {
    int n;cin>>n;
    string str;cin>>str;
    int last=1;
    for (int i = 0; i < str.size(); ++i) {
        char c;
        c=str[i];
        for (int j = 0; j < str.size(); ++j) {
            if (last){
                if (c == str[j]) {
                    str[j] = '0';
                }
            }
            else{
                if (c==str[j]){
                    str[j] = '1';
                }
            }
        }
        last=!last;
    }

    for (int i = 1; i < str.size(); ++i) {
        if (str[i]==str[i-1]){
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";

}


signed main() {
    YF12();
    IO();

    int t=1;
    cin>>t;
    while (t--) {
        doWork();
      cout<<"\n";
    }


}