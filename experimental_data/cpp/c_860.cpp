#include <bits/stdc++.h>

using namespace std;

enum {MOD0 = 1000000000, MOD7 = 1000000007, MOD9 = 1000000009};
typedef unsigned short ushort;typedef unsigned int uint;typedef long long ll;typedef unsigned long long ull;
template <typename T> ostream &operator<<(ostream &cout, vector<T> &a){for(size_t i = 0; i < a.size(); ++i) cout << a[i] << " "; return cout;}
template <typename T> ostream &operator<<(ostream &cout, vector<vector<T> > &a){for(size_t i = 0; i < a.size(); ++i) cout << a[i] << endl; return cout;}
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

enum {MAX_N = 100000};

string s[MAX_N];
int type[MAX_N];
int used[MAX_N + 1];

int to_number(string &s){
    int ret = 0;
    if(s[0] == '0')
        return -1;
    for(int i = 0; i < s.size(); ++i){
        if(!isdigit(s[i]))
            return -1;
        ret *= 10;
        ret += s[i] - '0';
        if(ret > MAX_N)
            return -1;
    }
    return ret;
}

void move_cmd(int a, int b){
    cout << "move " << a << " " << b << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        cin >> s[i] >> type[i];
        if(type[i] == 1){
            ++cnt;
        }
    }
    int cur;
    for(int i = 0; i < n; ++i){
        cur = to_number(s[i]);
        if(cur <= 0 || cur > n)
            continue;
        used[cur] = ((type[i] == 0) ^ (cur <= cnt)) + 1;
    }
    cur = 0;
    int count_2 = 0;
    for(int i = 1; i <= n; ++i){
        if(used[i] == 0 && !cur){
            cur = i;
        }else if(used[i] == 2){
            count_2++;
        }
    }
    if(cur == 0){
        if(count_2 == n){
            cout << 0 << endl;
            return 0;
        }else{
            cout << n + 1 - count_2 << endl;
            for(int i = 1; i <= n; ++i){
                if(used[i] == 1){
                    cout << "move " << i << " tmp" << endl;
                    used[i] = 0;
                    for(int k = 0; k < n; ++k){
                        if(to_number(s[k]) == i){
                            s[k] = "tmp";
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }else{
        cout << n - count_2 << endl;
    }
    priority_queue<int> c[2][2];
    for(int i = 1; i <= n; ++i){
        if(used[i] == 2)
            continue;
        c[i > cnt][used[i]].push(i);
    }
    while(!c[0][1].empty() || !c[1][1].empty()){
        if(!c[0][1].empty() && !c[1][0].empty()){
            move_cmd(c[0][1].top(), c[1][0].top());
            c[1][0].pop();
            c[0][0].push(c[0][1].top());
            c[0][1].pop();
        }else if(!c[1][1].empty() && !c[0][0].empty()){
            move_cmd(c[1][1].top(), c[0][0].top());
            c[0][0].pop();
            c[1][0].push(c[1][1].top());
            c[1][1].pop();
        }
    }
    for(int i = 0; i < n; ++i){
        cur = to_number(s[i]);
        if(cur >= 1 && cur <= n){
            continue;
        }
        if(type[i] == 1){
            cout << "move " << s[i] << " " << c[0][0].top() << endl;
            c[0][0].pop();
        }else{
            cout << "move " << s[i] << " " << c[1][0].top() << endl;
            c[1][0].pop();
        }
    }
    return 0;
}