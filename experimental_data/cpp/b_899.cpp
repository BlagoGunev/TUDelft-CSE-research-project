#include<bits/stdc++.h>
using namespace std;
int month[117] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a[27];
inline bool check(int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(a[i]!=month[k+i-1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, ans = 0;
    for(int i = 1; i <= 36; i++)
    {
        month[i+36] = month[i];
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= 36; i++)
    {
        if(check(i, n))
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
	return 0;
}