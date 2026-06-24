#include <bits/stdc++.h>
using namespace std;

#ifndef use_ios11
#define use_ios11
using namespace std;
struct ins
{
    int ans;
    ins() {
        ans = 1;
    }
    #define endl '\n'
    void read()
    {
    }
    void read1(char &s)
    {
        char c = getchar();
        for (; !isprint(c) || c == ' ' || c == '\n' || c == '\t'; c = getchar())
            ;
        s = c;
        if (c == EOF)
            ans = 0;
    }
    void read1(string &s)
    {
        s = "";
        char c = getchar();
        for (; !isprint(c) || c == ' ' || c == '\n' || c == '\t'; c = getchar())
            ;
        for (; isprint(c) && c != ' ' && c != '\n' && c != '\t'; c = getchar())
            s += c;
        if (c == EOF)
            ans = 0;
    }
    template <typename T>
    void read1(T &n)
    {
        T x = 0;
        int f = 1;
        char c = getchar();
        for (; !isdigit(c); c = getchar())
        {
            if (c == '-')
                f = -1;
            if (c == EOF)
            {
                ans = 0;
                return;
            }
        }
        for (; isdigit(c); c = getchar())
            x = x * 10 + c - 48;
        n = x * f;
        if (c == EOF)
            ans = 0;
        if (c != '.')
            return;
        T l = 0.1;
        while ((c = getchar()) <= '9' && c >= '0')
            x = x + (c & 15) * l, l *= 0.1;
        n = x * f;
        if (c == EOF)
            ans = 0;
    }
    void write() {}
    void write1(string s)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
            putchar(s[i]);
    }
    void write1(const char *s)
    {
        int n = strlen(s);
        for (int i = 0; i < n; i++)
            putchar(s[i]);
    }
    void write1(char s) {
        putchar(s);
    }
    void write1(float s, int x = 6)
    {
        char y[10001];
        sprintf(y, "%%.%df", x);
        printf(y, s);
    }
    void write1(double s, int x = 6)
    {
        char y[10001];
        sprintf(y, "%%.%dlf", x);
        printf(y, s);
    }
    void write1(long double s, int x = 6)
    {
        char y[10001];
        sprintf(y, "%%.%dLf", x);
        printf(y, s);
    }
    template <typename T>
    void write1(T n)
    {
        if (n < 0)
            n = -n, putchar('-');
        if (n > 9)
            write1(n / 10);
        putchar('0' + n % 10);
    }
    template <typename T>
    friend ins operator>>(ins x, T &n);
    template <typename T>
    friend ins operator<<(ins x, T n);
    operator bool() {
        return ans;
    }
};
template <typename T>
ins operator>>(ins x, T &n)
{
    if (!x.ans)
        return x;
    x.read1(n);
    return x;
}
template <typename T>
ins operator<<(ins x, T n)
{
    x.write1(n);
    return x;
}
ins yin;
ins yout;
#endif
int n;
string s;
vector<int> x, y;
int b[300001];
int main()
{
    int TTT;
    yin>>TTT;
    while (TTT--)
    {
        yin>>n>>s;
        int ans=0;x.clear();y.clear();
        for (int i=1;i<=n;i++)
        {
            if (s[i-1]=='0')
            {
                if (y.size())
                {
                    b[i]=y.back();
                    x.push_back(b[i]);
                    y.pop_back();
                }
                else
                {
                    b[i]=++ans;
                    x.push_back(b[i]);
                }
            }
            else
            {
                if (x.size())
                {
                    b[i]=x.back();
                    y.push_back(b[i]);
                    x.pop_back();
                }
                else
                {
                    b[i]=++ans;
                    y.push_back(b[i]);
                }
            }
            // yout<<x.size()<<" "<<y.size()<<endl;
        }
        yout<<ans<<endl;
        for (int i=1;i<=n;i++)yout<<b[i]<<" ";
        puts("");
    }
}