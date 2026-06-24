#include<cstdio>
#include<algorithm>
#include<cassert>
#include<map>
#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<cmath>
#include<iostream>
#include<fstream>
#include<sstream>
#include<queue>
using namespace std;

#define DBG false
#define out(x) cout << #x << ":  " << x << "   in line :   " << __LINE__ << endl;

typedef long long int64;

inline int Rint(){int x; scanf("%d", &x); return x;}

int v;
int in;
int a[11];

int f(int cur){
    int len = cur / in;
    if(len <= 0)
        return 0;
    cur -= (len - 1) * in;
    for(int i = 9; i >= 1; -- i)
        if(a[i] <= cur)
            return i;
    return 0;
}
int main(){
    while(cin >> v){
        for(int i = 1; i <= 9; ++ i)
            a[i] = Rint();
        in = *min_element(a + 1, a + 10);
        if(v < in){
            puts("-1");
            continue;
        }
        int cur;
        while(cur = f(v)){
            putchar('0' + cur);
            v -= a[cur];
        }
        puts("");
    }
    return 0;
}