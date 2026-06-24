#include <bits/stdc++.h>
#define lld long long int
#define M 1000000007
using namespace std;

struct points
{
    int x;
    int y;
    int idx;
};

bool compare1(points p1, points p2)
{
    if(p1.x < p2.x) return true;
    else if(p1.x > p2.x) return false;
    else return p1.y < p2.y;
}

bool compare2(points p1, points p2)
{
    if(p1.x < p2.x) return true;
    else if(p1.x > p2.x) return false;
    else return p1.y > p2.y;
}

bool compare3(points p1, points p2)
{
    if(p1.y < p2.y) return true;
    else if(p1.y > p2.y) return false;
    else return p1.x < p2.x;
}

bool compare4(points p1, points p2)
{
    if(p1.y < p2.y) return true;
    else if(p1.y > p2.y) return false;
    else return p1.x > p2.x;
}

int n, a[200005], X[200005], Y[200005];
points p[200005];

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    scanf("%d", &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
        p[i].idx = i;
    }

    sort(p, p+n, compare1);
    a[p[0].idx] = 1;
    X[p[0].idx] = p[0].x;
    Y[p[0].idx] = p[0].y-1;
    for(int i=1 ; i<n ; i++)
    {
        if(p[i-1].x != p[i].x || p[i-1].y != p[i].y-1)
        {
            a[p[i].idx] = 1;
            X[p[i].idx] = p[i].x;
            Y[p[i].idx] = p[i].y-1;
        }
        else
        {
            if(!a[p[i].idx] || (a[p[i].idx] > a[p[i-1].idx]+1))
            {
                a[p[i].idx] = a[p[i-1].idx]+1;
                X[p[i].idx] = X[p[i-1].idx];
                Y[p[i].idx] = Y[p[i-1].idx];
            }
        }
    }

    sort(p, p+n, compare2);
    a[p[0].idx] = 1;
    X[p[0].idx] = p[0].x;
    Y[p[0].idx] = p[0].y+1;
    for(int i=1 ; i<n ; i++)
    {
        if(p[i-1].x != p[i].x || p[i-1].y != p[i].y+1)
        {
            a[p[i].idx] = 1;
            X[p[i].idx] = p[i].x;
            Y[p[i].idx] = p[i].y+1;
        }
        else
        {
            if(!a[p[i].idx] || (a[p[i].idx] > a[p[i-1].idx]+1))
            {
                a[p[i].idx] = a[p[i-1].idx]+1;
                X[p[i].idx] = X[p[i-1].idx];
                Y[p[i].idx] = Y[p[i-1].idx];
            }
        }
    }

    sort(p, p+n, compare3);
    a[p[0].idx] = 1;
    X[p[0].idx] = p[0].x-1;
    Y[p[0].idx] = p[0].y;
    for(int i=1 ; i<n ; i++)
    {
        if(p[i-1].y != p[i].y || p[i-1].x != p[i].x-1)
        {
            a[p[i].idx] = 1;
            X[p[i].idx] = p[i].x-1;
            Y[p[i].idx] = p[i].y;
        }
        else
        {
            if(!a[p[i].idx] || (a[p[i].idx] > a[p[i-1].idx]+1))
            {
                a[p[i].idx] = a[p[i-1].idx]+1;
                X[p[i].idx] = X[p[i-1].idx];
                Y[p[i].idx] = Y[p[i-1].idx];
            }
        }
    }

    sort(p, p+n, compare4);
    a[p[0].idx] = 1;
    X[p[0].idx] = p[0].x+1;
    Y[p[0].idx] = p[0].y;
    for(int i=1 ; i<n ; i++)
    {
        if(p[i-1].y != p[i].y || p[i-1].x != p[i].x+1)
        {
            a[p[i].idx] = 1;
            X[p[i].idx] = p[i].x+1;
            Y[p[i].idx] = p[i].y;
        }
        else
        {
            if(!a[p[i].idx] || (a[p[i].idx] > a[p[i-1].idx]+1))
            {
                a[p[i].idx] = a[p[i-1].idx]+1;
                X[p[i].idx] = X[p[i-1].idx];
                Y[p[i].idx] = Y[p[i-1].idx];
            }
        }
    }

    for(int i=0 ; i<n ; i++) printf("%d %d\n", X[i], Y[i]);

    return 0;

}