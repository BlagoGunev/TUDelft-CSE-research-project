/*
  * @file    :HL Tandem Repeats.cpp
  * @author  :legendcn
  * @date    :2024-03-22
*/
# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
# define int long long
# define rd(t) read <t> ()
# define mem(a, b) memset (a, b, sizeof (a))
# define fi first
# define se second
# define lc u << 1 
# define rc u << 1 | 1 
# define debug printf ("debug\n")

template <typename T> inline T read ()
{
    T s = 0, w = 1; int c = getchar ();
    for (; !isdigit (c); c = getchar ()) if (c == '-') w = -1;
    for (; isdigit (c); c = getchar ()) s = (s << 1) + (s << 3) + c - '0';
    return s * w;
}

int n;
string s;
signed main ()
{
    ios::sync_with_stdio (0);
    cin.tie (0);
    int T; cin >> T;
    while (T -- )
    {
        cin >> s; n = s.size (); s = " " + s;
        int ans = 0;
        for (int len = 1; len <= n; len ++ )
        {
            int cnt = 0; 
            for (int i = 1; i + len <= n; i ++ )
            {
                if (s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?')
                    cnt ++ ;
                else{
                    cnt=0;
                }
                if(cnt==len){
                    ans=max(ans,len);
                    break;
                }
            }
        }
        cout<<ans*2<<endl;
    }
	return 0;
}