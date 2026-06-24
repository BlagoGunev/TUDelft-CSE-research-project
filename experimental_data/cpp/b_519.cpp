//!
///

/** ========================================**
 ** @Author: A Asif Khan Chowdhury
 ** @Category:
/** ========================================**/


/**................ Headers ................**/
#include <bits/stdc++.h>

using namespace std;

/**................ Macros ................**/
#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pi 3.141592653589793
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case %d: ", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("E:/a.txt", "r", stdin);
#define write freopen("E:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 1000000007
#define mx 100010
#define gc getchar
//Fast Reader
template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};
int gcd(int a, int b) {
    return b?gcd(b,a%b):a;
}
int n, arr1[mx],arr2[mx],arr3[mx];
int main() {
//  open
    read(n);
    for(int i=0;i<n;i++)
        read(arr1[i]);
    for(int i=0;i<n-1;i++)
        read(arr2[i]);
    for(int i=0;i<n-2;i++)
        read(arr3[i]);

    sort(arr1,arr1+n);
    sort(arr2,arr2+n-1);
    sort(arr3,arr3+n-2);

    for(int i=0;i<n;i++){
        if(arr1[i]!=arr2[i]){
            printf("%d\n",arr1[i]);
            break;
        }
    }
    for(int i=0;i<n-1;i++){
        if(arr2[i]!=arr3[i]){
            printf("%d\n",arr2[i]);
            break;
        }
    }
    return 0;
}