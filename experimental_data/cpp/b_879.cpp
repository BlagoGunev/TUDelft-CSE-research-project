#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FILE ""

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(FILE".in", "r", stdin);
    //freopen(FILE".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    long long n,k;
    cin>>n>>k;
    /*
    while (1)
    {
       int cnt = 0;
       while (x > q.front())
       {
           int y = q.front();
           q.pop();
           q.push(y);
           cnt++;
           if (cnt >= k)
           {
               cout << x;
               return 0;
           }
       }
       q.push(x);
       x = q.front();
       q.pop();
    }
    */
    int ans = 0;
    queue <int> o;
    for (int i = 0; i < n; i++ )
    {
        int x;
        /*
        while (1)
        {
        int cnt = 0;
        while (x > q.front())
        {
           int y = q.front();
           q.pop();
           q.push(y);
           cnt++;
           if (cnt >= k)
           {
               cout << x;
               return 0;
           }
        }
        q.push(x);
        x = q.front();
        q.pop();
        }
        */
        cin>>x;
        o.push(x);
        ans = max( ans, x );
    }
    int cnt = 0;
    int x = o.front();
    /*
    while (1)
    {
       int cnt = 0;
       while (x > q.front())
       {
           int y = q.front();
           q.pop();
           q.push(y);
           cnt++;
           if (cnt >= k)
           {
               cout << x;
               return 0;
           }
       }
       q.push(x);
       x = q.front();
       q.pop();
    }
    */
    o.pop();
    while (!o.empty() && x != ans )
    {
        int y = o.front();
        if (x > y)
        {
            /*
            while (1)
            {
            int cnt = 0;
            while (x > q.front())
            {
            int y = q.front();
            q.pop();
            q.push(y);
            cnt++;
            if (cnt >= k)
            {
               cout << x;
               return 0;
            }
            }
            q.push(x);
            x = q.front();
            q.pop();
            }
            */
            cnt++;
            if ( cnt >= k )
            {
                cout << x;
                return 0;
            }
            o.pop();
            /*
            while (1)
            {
            int cnt = 0;
            while (x > q.front())
            {
            int y = q.front();
            q.pop();
            q.push(y);
            cnt++;
            if (cnt >= k)
            {
               cout << x;
               return 0;
            }
            }
            q.push(x);
            x = q.front();
            q.pop();
            }
            */
            o.push(y);
        }
        else
        {
            if (cnt >= k)
            {
                /*
                while (1)
                {
                int cnt = 0;
                while (x > q.front())
                {
                int y = q.front();
                q.pop();
                q.push(y);
                cnt++;
                if (cnt >= k)
                {
                cout << x;
                return 0;
                }
                }
                q.push(x);
                x = q.front();
                q.pop();
                }
                */
                cout<<x;
                return 0;
            }
            cnt = 1;
            o.push(x);
            /*
            while (1)
            {
            int cnt = 0;
            while (x > q.front())
            {
            int y = q.front();
            q.pop();
            q.push(y);
            cnt++;
            if (cnt >= k)
            {
               cout << x;
               return 0;
            }
            }
            q.push(x);
            x = q.front();
            q.pop();
            }
            */
            x = y;
            o.pop();
        }
        /*
        while (1)
        {
        int cnt = 0;
        while (x > q.front())
        {
           int y = q.front();
           q.pop();
           q.push(y);
           cnt++;
           if (cnt >= k)
           {
               cout << x;
               return 0;
           }
        }
        q.push(x);
        x = q.front();
        q.pop();
        }
        */
    }
    cout<<ans;
    /*
    while (1)
    {
       int cnt = 0;
       while (x > q.front())
       {
           int y = q.front();
           q.pop();
           q.push(y);
           cnt++;
           if (cnt >= k)
           {
               cout << x;
               return 0;
           }
       }
       q.push(x);
       x = q.front();
       q.pop();
    }
    */
    return 0;
}