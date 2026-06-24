#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double pi=acos(-1.0);
const double eps=1e-6;
const int INF=1000000000;
const int maxn=110;
const int maxm=10010;
int luna[maxn];
int n;
bool checkp(int x)
{
    int sum=x;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }

    if(sum==n)return true;
    else return false;
    //return sum==n;
}
int main(int argc, char const *argv[])
{
    //int n;
    cin>>n;

    if(n<=82)
    {
        //int flag=0;
        int idx=0;
        for(int i=1;i<=n;i++)
        {
            if(checkp(i))
            {
                luna[idx++]=i;
            }
        }
        //for(int i=0;i<100;i++)cout<<luna[i];
        if(idx==0)cout<<0<<endl;
        else
        {
            sort(luna,luna+idx);
            cout<<idx<<endl;
            for(int i=0;i<idx;i++)
            {
                cout<<luna[i]<<endl;
            }
        }
    }
    else
    {
        int idx=0;
        for(int i=n-82;i<=n;i++)
        {
            if(checkp(i))
            {
                luna[idx++]=i;
            }
        }
        if(idx==0)cout<<0<<endl;
        else
        {
            sort(luna,luna+idx);
            cout<<idx<<endl;
            for(int i=0;i<idx;i++)
            {
                cout<<luna[i]<<endl;
            }
        }        
    }
    //system("pause");
    return 0;
}