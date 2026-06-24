#include <bits/stdc++.h>


#define f(i, a, b) for(int i = a; i <= b; i++)
#define fd(i, a, b) for(int i = a; i >=b;i--)
#define fin ""
#define fou ""
#define mp make_pair
#define fi first
#define se second
#define pb push_back

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n, k1, k2, s1[7010], s2[7010], f[7010][2], cnt[7010][2];

void dfs(int pos, int p, int v)
{
    //cout << pos << " " << p << " " << v << endl;
    f[pos][p] = v;
    if (v == 0)
    {
        if (p == 0)
        {
            f(i, 1, k2)
            {
                int x = pos - s2[i];
                if (x < 1) x += n;
                if (f[x][1] == -1 && x != 1) dfs(x, 1, 1);
            }
        } else
        {
            f(i, 1, k1)
            {
                int x = pos - s1[i];
                if (x < 1) x += n;
                if (f[x][0] == -1) dfs(x, 0, 1);
            }
        }
    } else
    {
        if (p == 0)
        {
            f(i, 1, k2)
            {
                int x = pos - s2[i];
                if (x < 1) x += n;
                cnt[x][1]++;
                if (cnt[x][1] == k2)
                    if (f[x][1] == -1) dfs(x, 1, 0);
            }
        } else
        {
            f(i, 1, k1)
            {
                int x = pos - s1[i];
                if (x < 1) x += n;
                cnt[x][0]++;
                if (cnt[x][0] == k1)
                    if (f[x][0] == -1) dfs(x, 0, 0);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> k1;
    f(i, 1, k1)
        cin >> s1[i];
    cin >> k2;
    f(i, 1, k2)
        cin >> s2[i];
    memset(f, 255, sizeof(f));
    dfs(1, 0, 0);
    if (f[1][1] == -1) dfs(1, 1, 0);
    f(i, 2, n)
    {
        if (f[i][0] == 0) cout << "Lose";
        if (f[i][0] == 1) cout << "Win";
        if (f[i][0] == -1) cout << "Loop";
        cout << " ";
    }
    cout << endl;
    f(i, 2, n)
    {
        if (f[i][1] == 0) cout << "Lose";
        if (f[i][1] == 1) cout << "Win";
        if (f[i][1] == -1) cout << "Loop";
        cout << " ";
    }
}