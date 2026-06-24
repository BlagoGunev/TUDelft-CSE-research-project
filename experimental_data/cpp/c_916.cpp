#include<bits/stdc++.h>

#define PI 3.1415926535897932384626433832795
#define INF (1e9 + 7)
#define MOD (100000)
#define pii pair <int, int>
#define mp make_pair
#define ll long long
#define pb push_back



using namespace std;
typedef long double ld;

vector <vector <pii> > g;
int n, m;

int main()
{
// freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
 ios_base::sync_with_stdio(0);
 cin.tie(NULL);

    scanf("%d%d", &n, &m);
    if (m==1)
        return printf("100003 100003\n1 2 100003"), 0;
    printf("2 100003\n");
    printf("1 %d 2\n", n);
    for (int i=2; i<n-1; ++i)
        printf("1 %d 1\n", i);
    printf("1 %d %d\n", n-1, 100003-n+1);
    m-=(n-1);
    for (int i=2; i<n; ++i)
    {
        for (int j=i+1; j<=n; ++j)
        {
            if (!m)
                break;
            --m;
            printf("%d %d 100005\n", i, j);
        }
        if (!m)
            break;
    }


 return 0;

}