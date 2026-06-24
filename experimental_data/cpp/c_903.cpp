#include<cstdio>
#include<algorithm>

using namespace std;

int s[5005] = {0};
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    sort(s, s + n);
    int mx = 1;
    int mxhere = 1;
    for(int i = 1; i < n; i++)
    {
        if(s[i] == s[i - 1])
            mxhere++;
        else
            mxhere = 1;
        mx = max(mxhere, mx);
    }
    printf("%d\n", mx);
    return 0;
}