//Now playing: Mary J. Blidge - Good Morning Gorgeous
//vk - volezh
//tg - kalexina
//cf - splatjov
//супер ламповое место -> dshindov_chat
//ХУЙ ВОЙНЕ!

// #pragma GCC optimize(3)
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC target("avx","sse2")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wc++11-long-long"
#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <fstream>
#include <map>
 
using ll = long long;
using namespace std;
typedef pair <long long, long long > pii;

void solve()
{
    int n;
    int ans=0;
    cin>>n;
    string b;
    cin>>b;
    for (auto i='z'; i>='a'; i--)
    {
        for (int j=0; j<n; j++)
        {
            if (b[j]==char(i) and j-1>=0 and b[j-1]==char(i-1))
            {
                b=b.substr(0,j)+b.substr(j+1);
                n--;
                j--;
                ans++;
                i++;
                break;
            }
            if (b[j]==char(i) and j+1<=b.size()-1 and b[j+1]==char(i-1))
            {
                b=b.substr(0,j)+b.substr(j+1);
                n--;
                j--;
                ans++;
                i++;
                break;
            }
        }
    }
    cout<<ans<<endl;
}


signed main()
{
    long long t=1;
    // cin>>t;
    while (t) 
    {
        t--;
        solve();
    }
}