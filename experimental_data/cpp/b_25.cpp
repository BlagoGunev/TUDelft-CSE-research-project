/*
ID: harrymw1
LANG: C++
TASK: 
*/
 
#include <iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include <cstdio>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cctype>
#include<assert.h>
#include<numeric>
#include<ctime>
#include<iterator>
//#include<sstream>
using namespace std;

#define PI acos(-1.0)
#define fore(i,a) for(int i=0; i<(a); i++)
#define forv(i,a) for(typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pb push_back
#define all(x) x.begin(),x.end()
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
/*template<class T> string toString(T n){
    ostringstream ost;ost<<n;ost.flush();
    return ost.str();
}*/

//__builtin_popcount(int x);
int main()
{
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //clock_t start, finish;
    //double duration;
    //start = clock();
    int n;cin>>n;
    string s;cin>>s;
    string ret;
    int x = 0, y = 0;
    bool flag = true;
    for (int i = 0; i * 2 <= n && flag; i++)
    {
        for (int j = 0; j * 3 + i * 2 <= n && flag; j++)
        {
            if (j*3+i*2==n)
            {
                x = i; y = j;
                flag = false;
                break;
            }
        }
    }
    if (x) 
    {   ret += s.substr(0,2);
        int i, c;
        for (i = 2,c = 1; i <n && c < x; i+=2,  c++)
        {
            ret += "-" + s.substr(i,2);
        }
        if (y)
        {
            for (c = 0; c < y && i < n; c++, i+=3)
                ret += "-" + s.substr(i, 3);
        }
        cout<<ret<<endl;
    }
    else{
        int i, c;
        ret += s.substr(0, 3);
        for (i = 3, c = 1; i < n && c < y; i += 3,c++)
            ret += "-" + s.substr(i, 3);
        cout<<ret<<endl;
    }
    

    //finish = clock();
    //duration = (double)(finish - start) / CLOCKS_PER_SEC;
    //printf( "%f seconds\n", duration );
    return 0;
}