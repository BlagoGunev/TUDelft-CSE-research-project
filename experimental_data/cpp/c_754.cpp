#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll int

const int N = 110;

using namespace std;

int n;
int m;
string a[N];
string s[N];
string ans[N];
vector < string > g[N];

bool tr(int x)
{
    if(x == 0 || s[x][0] != '?')
        return true;
    for(string y: g[x]){
        if(ans[x - 1] != y && ans[x] != y && ans[x + 1] != y){
            ans[x] = y;
            return true;
        }
    }
    ans[x] = "";
    tr(x - 1);
    for(string y: g[x]){
        if(ans[x - 1] != y && ans[x] != y && ans[x + 1] != y){
            ans[x] = y;
            return true;
        }
    }
    return false;
}

void solve()
{
    cin >> n;
    vector < int > v;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 0; i <= m; i++)
       getline(cin, s[i]);
    for(int i = 1; i <= m; i++){
        g[i].clear();
        if(s[i][0] == '?'){
            v.pb(i);
            map < string, bool > used;
            for(int j = 2; j < s[i].size(); j++){
                if(!('a' <= s[i][j] && s[i][j] <= 'z' || 'A' <= s[i][j] && s[i][j] <= 'Z' || '0' <= s[i][j] && s[i][j] <= '9'))
                    continue;
                string t = "";
                while(j < s[i].size() && ('a' <= s[i][j] && s[i][j] <= 'z' || 'A' <= s[i][j] && s[i][j] <= 'Z' || '0' <= s[i][j] && s[i][j] <= '9')){
                    t += s[i][j];
                    j++;
                }
                if(t.size() <= 10)
                    used[t] = true;
            }
            for(int j = 1; j <= n; j++)
                if(used.find(a[j]) == used.end())
                    g[i].pb(a[j]);
        }
        else{
            string t = "";
            for(int j = 0; s[i][j] != ':'; j++)
                t += s[i][j];
            ans[i] = t;
        }
    }
    for(int x: v){
        if(tr(x) == false){
            cout << "Impossible" << endl;
            return;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i];
        int j = 0;
        while(s[i][j] != ':')
            j++;
        for(; j < s[i].size(); j++)
            cout << s[i][j];
        cout << endl;
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("contest.in");
    //fout("contest.out");
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
        solve();
}