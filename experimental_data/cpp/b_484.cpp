#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x <0) {
        putchar('-');
        x = -x;
    }
    if (x>9) pt(x / 10);
    putchar(x % 10 + '0');
}
using namespace std;
typedef long long ll;
const int N = 200002;
#define Lson(x) (x<<1)
#define Rson(x) (x<<1|1)
#define L(x) tree[x].l
#define R(x) tree[x].r

int n, a[N];
int work(){
    int ans = 0;
    for(int i = n; i ; i--)
    {
        if(a[i] <= ans)break;
        for(int j = 1; j < a[i]; j++)
        {
            int tmp = a[i]/(j+1);
            while(a[i]/tmp > j)tmp++;
            if(tmp <= ans)break;
            int id = lower_bound(a+1, a+1+n, tmp) - a;
            if(id == i)continue;
            ans = max(ans, a[i]%a[id]);
            if(ans == a[i]-1)return ans;
        }
    }
    return ans;
}
int main(){
    while (cin>>n){
        for(int i = 1; i <= n; i++){
            rd(a[i]);
            if(a[i] == 1)n--, i--;
        }
        if(n == 0){puts("0"); continue;}
        sort(a+1, a+1+n);
        n = unique(a+1, a+n+1) - a-1;
   //     for(int i = 1; i <= n; i++)pt(a[i]),putchar(' ');puts("");
        cout<<work()<<endl;
    }
    return 0;
}