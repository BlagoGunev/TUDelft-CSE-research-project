/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define PI              acos(-1.0)
#define eps             1e-6
#define mem(ara, val)   memset(ara, val, sizeof(ara))
const int MX = 100000;
const int MOD = 1000000007;
const int INF = (int)1e9;
bool good[30];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s, g, t;
    int len, q, n, star;
    while(cin>>g)
    {
        mem(good, 0);
        cin>>s;
        n = g.length();
        len = s.length();
        f(i, 0, n-1)
        {
            good[g[i] - 'a'] = 1;
        }
        star = -1;
        f(i, 0, len-1)
            if(s[i]=='*')
            {
                star = i;
                break;
            }
        cin>>q;
        while(q--)
        {
            cin>>t;
            bool yes = 1;
            n = t.length();
            if(n>=len)
            {
                if(star==-1 && n>len)
                {
                    yes = 0;
                    cout << "NO\n";
                    continue;
                }
                if(star!=-1)
                {
                    int need = n - len;
                    f(i, star, star+need)
                    {
                        if(yes==0)
                            break;
                        if(good[t[i] - 'a'])
                        {
                            yes = 0;
                            break;
                        }
                    }
                    f(i, 0, star-1)
                    {
                        if(yes==0)
                            break;
                        if(s[i]!='?' && s[i]!=t[i])
                        {
                            yes = 0;
                            break;
                        }
                        if(s[i]=='?' && good[t[i] - 'a']==0)
                        {
                            yes = 0;
                            break;
                        }
                    }
                    int j = n-1;
                    F(i, len-1, star+1)
                    {
                        if(yes==0)
                            break;
                        if(s[i]!='?' && s[i]!=t[j])
                        {
                            yes = 0;
                            break;
                        }
                        if(s[i]=='?' && good[t[j] - 'a']==0)
                        {
                            yes = 0;
                            break;
                        }
                        j--;
                    }
                }
                else
                {
                    f(i, 0, n-1)
                    {
                        if(yes==0)
                            break;
                        if(s[i]!='?' && s[i]!=t[i])
                        {
                            yes = 0;
                            break;
                        }
                        if(s[i]=='?' && good[t[i] - 'a']==0)
                        {
                            yes = 0;
                            break;
                        }
                    }
                }
                if(yes==0)
                    cout << "NO\n";
                else cout << "YES\n";
            }
            else if(n==len-1)
            {
                if(star==-1)
                    yes = 0;
                else
                {
                    f(i, 0, star-1)
                    {
                        if(yes==0)
                            break;
                        if(s[i]!='?' && s[i]!=t[i])
                        {
                            yes = 0;
                            break;
                        }
                        if(s[i]=='?' && good[t[i] - 'a']==0)
                        {
                            yes = 0;
                            break;
                        }
                    }
                    int j = n-1;
                    F(i, len-1, star+1)
                    {
                        if(yes==0)
                            break;
                        if(s[i]!='?' && s[i]!=t[j])
                        {
                            yes = 0;
                            break;
                        }
                        if(s[i]=='?' && good[t[j] - 'a']==0)
                        {
                            yes = 0;
                            break;
                        }
                        j--;
                    }
                }
                if(yes==0)
                    cout << "NO\n";
                else cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
    return 0;
}