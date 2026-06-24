#include <bits/stdc++.h>



#define ll long long



#define SZ(x) (int)(x).size()

#define pb push_back



template<class T>inline void chkmax(T &x, const T &y) {if(x < y) x = y;}

template<class T>inline void chkmin(T &x, const T &y) {if(x > y) x = y;}



template<class T>

inline void read(T &x) {

    char c;int f = 1;x = 0;

    while(((c=getchar()) < '0' || c > '9') && c != '-');

    if(c == '-') f = -1;else x = c-'0';

    while((c=getchar()) >= '0' && c <= '9') x = x*10+c-'0';

    x *= f;

}

static int outn;

static char out[(int)2e7];

template<class T>

inline void write(T x) {

    if(x < 0) out[outn++] = '-', x = -x;

    if(x) {

        static int tmpn;

        static char tmp[20];

        tmpn = 0;

        while(x) tmp[tmpn++] = x%10+'0', x /= 10;

        while(tmpn) out[outn++] = tmp[--tmpn];

    }

    else out[outn++] = '0';

}



const int N = 5e5;



int n, k;

int c[N+9];

ll sum;



inline bool check1(int lim) {

    for(int i = 1, t = k; i <= n; ++i)

        if(c[i] < lim) {

            t -= lim-c[i];

            if(t < 0) return false;

        }

    return true;

}



inline bool check2(int lim) {

    for(int i = 1, t = k; i <= n; ++i)

        if(c[i] > lim) {

            t -= c[i]-lim;

            if(t < 0) return false;

        }

    return true;

}



int main() {

    read(n), read(k);

    for(int i = 1; i <= n; ++i)

        read(c[i]), sum += c[i];

    int a, b;

    int l = 1, r = 1e9;

    while(l < r) {

        int mid = (l+r+1)>>1;

        if(check1(mid)) l = mid;

        else r = mid-1;

    }

    a = l, l = 1, r = 1e9;

    while(l < r) {

        int mid = (l+r)>>1;

        if(check2(mid)) r = mid;

        else l = mid+1;

    }

    b = r;

    if(a < b) printf("%d\n", b-a);

    else printf("%d\n", sum%n > 0);

    return 0;

}