#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
#define enter putchar('\n')
#define space putchar(' ')
template <class T>
void read(T &x){
    char c;
    bool op = 0;
    while(c = getchar(), c > '9' || c < '0')
	if(c == '-') op = 1;
    x = c - '0';
    while(c = getchar(), c >= '0' && c <= '9')
	x = x * 10 + c - '0';
    if(op) x = -x;
}
template <class T>
void write(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 100005, INF = 0x3f3f3f3f;
int n, a[N], minn = INF, ans = INF;

int main(){

    read(n);
    for(int i = 1; i <= n; i++) {
        read(a[i]);
        minn = min(minn, a[i]);
    }
    for(int i = 1, last = -INF; i <= n; i++)
        if(a[i] == minn){
            ans = min(ans, i - last);
            last = i;
        }
    write(ans), enter;;
    

    return 0;
}