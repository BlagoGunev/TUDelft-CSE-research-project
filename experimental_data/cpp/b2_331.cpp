#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <utility>
#include <ctime>
#include <memory.h>
#include <cctype>
#include <cstdlib>
#include <limits>

using namespace std;

#pragma comment (linker, "/STACK:64000000")

#define y0 qwertyuiop
#define y1 asdfghjkl
#define forn(j, n) for(j=1; j<=n; j++)
#define sz size()
#define pb push_back
#define fors(w, s) for(map <int, int> :: iterator w=s.begin(); w!=s.end(); w++)
#define pii pair<int, int>
#define uns unsigned
#define vi vector <int>
#define vvi vector <vi>
#define inf 2000000000
#define o 1000000007
#define ll long long
#define maxint 2147483648
#define maxull 18446744073709551615

int j, n, l, i, h, t, mn, a[300500], f[300500], q1, q2, p1, p2, k, d[300500], m;
bool b[300500];

void tg ()
{
    freopen ("output.txt","r",stdin); freopen ("input.txt","w",stdout);
    
}

int sum (int p)
{
    if (p<1)
    {
        return 0;
    }
    return f[p]+sum((p&(p+1))-1);
}

int sum (int l, int r)
{
    return sum(r)-sum(l);
}

void inc (int p)
{
    for (; p<=n; p|=(p+1))
    {
        f[p]++;
    }
}

void dec (int p)
{
    for (; p<=n; p|=(p+1))
    {
        f[p]--;
    }
}

int main()
{
    //tg (); return 0;
    //freopen ("input.txt","r",stdin); freopen ("output.txt","w",stdout);
    //freopen ("smith.in","r",stdin); freopen ("smith.out","w",stdout);
    scanf ("%d", &n);
    forn (j, n)
    {
        scanf ("%d", &a[j]);
        d[a[j]]=j;
    }
    for (j=2; j<=n; j++)
    {
        if (d[j-1]>d[j])
        {
            inc (j);
            b[j]=1;
        }
    }
    scanf ("%d", &m);
    forn (j, m)
    {
        scanf ("%d%d%d", &t, &q1, &q2);
        if (t==2)
        {
            swap (a[q1], a[q2]);
            swap (d[a[q1]], d[a[q2]]);
            q1=a[q1];
            q2=a[q2];
            if (q1)
            {
                if (d[q1-1]>d[q1] && !b[q1])
                {
                    b[q1]=1;
                    inc (q1);
                }
                if (d[q1-1]<d[q1] && b[q1])
                {
                    b[q1]=0;
                    dec (q1);
                }
            }
            if (q1<n)
            {
                if (d[q1]>d[q1+1] && !b[q1+1])
                {
                    b[q1+1]=1;
                    inc (q1+1);
                }
                if (d[q1]<d[q1+1] && b[q1+1])
                {
                    b[q1+1]=0;
                    dec (q1+1);
                }
            }
            if (q2)
            {
                if (d[q2-1]>d[q2] && !b[q2])
                {
                    b[q2]=1;
                    inc (q2);
                }
                if (d[q2-1]<d[q2] && b[q2])
                {
                    b[q2]=0;
                    dec (q2);
                }
            }
            if (q2<n)
            {
                if (d[q2]>d[q2+1] && !b[q2+1])
                {
                    b[q2+1]=1;
                    inc (q2+1);
                }
                if (d[q2]<d[q2+1] && b[q2+1])
                {
                    b[q2+1]=0;
                    dec (q2+1);
                }
            }
        }
        else
        {
            if (q1>q2)
            {
                swap (q1, q2);
            }
            printf ("%d\n", sum(q1, q2)+1);
        }
    }
    return 0;
}