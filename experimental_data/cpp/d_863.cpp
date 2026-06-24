#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define se second
#define pi 2*acos(0)
#define PI 3.14159265358979323846264338

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const int N = 200010;
const int MX = 123456;
const int mod = (int)1e9 + 7;
const int base = 1023456789;
const ull BS1 = 10000019ULL;
const int INF = (1 << 29);

template < class T > inline void fastScan(T &x){
    register char c = getchar();
    int neg = 0; x = 0;
    for(   ; (c < 48 || c > 57) && (c != '-'); c = getchar());
    if(c == '-') { neg = 1; c = getchar(); }
    for(   ; c > 47 && c < 58; c = getchar()){
        x = (x << 1) + (x << 3) + c - 48;
    }
    if(neg) x = -x;
}

int x[N], y[N], z[N];

int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};

int inp[N];
int ans[N];

int main(){
    int n, q, m;
    fastScan(n); fastScan(q); fastScan(m);
    for(int i = 1; i <= n; i++){
        fastScan(inp[i]);
    }
    for(int i = 1; i <= q; i++){
        fastScan(x[i]); fastScan(y[i]); fastScan(z[i]);
    }
    for(int i = 1; i <= m; i++){
        int idx; fastScan(idx);
        for(int j = q; j >= 1; j--){
            if(y[j] <= idx && z[j] >= idx){
                if(x[j] == 1){
                    idx--;
                    if(idx < y[j]) idx = z[j];
                }else {
                    idx = z[j] - (idx - y[j]);
                }
            }
        }
        ans[i] = inp[idx];
    }
    for(int i = 1; i <= m; i++){
        printf("%d%c", ans[i], (i == n ? '\n' : ' '));
    }
}