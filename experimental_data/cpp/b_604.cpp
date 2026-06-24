#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
#define pc(x) putchar(x);

using namespace std;

inline void fastRead_int(int &x) {
    register int c = getchar();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar());

    if(c=='-') {
    	neg = 1;
    	c = getchar();
    }

    for(; c>47 && c<58 ; c = getchar()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}

int ans(int s[], int p)
{
    int fr, rr;
    fr = 0;
    rr = 2*p-1;
    int max_sum = 0;
    while(fr < rr)
    {
        max_sum = max(max_sum, s[fr] + s[rr]);
        fr++;
        rr--;
    }
    return max_sum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int s[n];

    for (int i = 0; i < n; ++i)
    {
        fastRead_int(s[i]);
    }

    if (n > k) cout << max(ans(s, n-k),s[n-1]) << endl;
    else cout << s[n-1] << endl;
}