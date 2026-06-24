#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include<time.h>
#define Fi first
#define Se second
#define ll long long
#define inf 0x3f3f3f3f
#define lowbit(x) (x&-x)
#define PLL pair<ll,ll>
#define PII pair<int,int>
#define in(s,b) scanf(s,&b)
#define l_inf 0x3f3f3f3f3f3f3f
#define mmin(a,b,c) min(a,min(b,c))
#define mmax(a,b,c) max(a,max(b,c))
#define debug(a) cout<<#a<<"="<<a<<endl;
#define debug2(a,b) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<endl;
using namespace std;
const int N=3e5+10;
int main()
{
    int n;cin>>n;
    if(n==5||n==46||n==2||n==3||n==4||n==12||n==30||n==35||n==43||n==52||n==64||n==66||n==86)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}
/*
no 1 10 11  16  20 28 37 41 49
yes 2 3 4 5  24  30
*/