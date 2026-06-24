#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define codefor int test;cin>>test;while(test--)
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define vector2d(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define vector3d(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
using namespace std;
using ll = long long;
template<class T> using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T> istream& operator>>(istream& is, vector<T>& vec) {for(T& x : vec)is >> x;return is;}
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {if(vec.empty())return os;os << vec[0];for(auto it = vec.begin(); ++it!= vec.end();)os << ' ' << *it;return os;}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){cin >> head;in(tail...);}
void out(){cout << '\n';}
template<class T>void out(const T& a){cout << a << '\n';}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){cout << head << ' ';out(tail...);}
const int INF = 1 << 30;
const long long INF2 = 1ll << 60;
template<class T> void chmax(T &a,const T b){if(b>a)a=b;}
template<class T> void chmin(T &a,const T b){if(b<a)a=b;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    codefor{
        string s;
        cin >> s;
        set<int> S;
        for(int i = 0; i + 4 <= s.size(); i++){
            if(s.substr(i, 4) == "1100") S.insert(i);
        }
        auto update = [&](int p){
            if(p < 0 || p + 4 > s.size()) return;
            if(S.count(p)) S.erase(p);
            if(s.substr(p, 4) == "1100") S.insert(p);
        };
        codefor{
            int p;
            char c;
            cin >> p >> c;
            p--;
            s[p] = c;
            for(int i = 0; i < 4; i++){
                update(p - i);
            }
            out(S.size() ? "YES" : "NO");
        }
    }
}