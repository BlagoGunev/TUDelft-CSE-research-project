#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
using namespace std;

typedef long long ll;
const int MAXN = 100010;

inline int read(){
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9'){if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9'){x = x * 10 + (c - '0'); c = getchar();}
    return x * f;
}

int n, ans[MAXN];
pair<int, pair<int, int> > seg[MAXN];

int main(){
    int T = read();
    while(T --){
        n = read();
        for(int i = 1; i <= n; i ++){
            seg[i].first = read();
            seg[i].second.first = read();
            seg[i].second.second = i;
        }
        sort(seg + 1, seg + n + 1);
        int r = seg[1].second.first, pos = -1;
        for(int i = 1; i <= n; i ++){
            if(seg[i].first > r){
                pos = i;
                break;
            }
            r = max(r, seg[i].second.first);
        }
        if(~pos){
            for(int i = 1; i < pos; i ++)
                ans[seg[i].second.second] = 1;
            for(int i = pos; i <= n; i ++)
                ans[seg[i].second.second] = 2;
            for(int i = 1; i <= n; i ++)
                printf("%d ", ans[i]);
            puts("");
        }
        else
            puts("-1");
    }
    return 0;
}