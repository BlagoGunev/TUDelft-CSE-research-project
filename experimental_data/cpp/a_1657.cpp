#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool is(pair<int,int>p1,pair<int,int>p2)
{
    if(p2.first<=p1.second)
        return true;
    return false;
}
bool overFF(int x,int y)
{
    if(LLONG_MAX/x<y)
        return true;
    return false;
}
bool is(int x)
{
    int t=sqrt(x);
    if(t*t==x)
        return true;
    return false;
}
int32_t main()
{

          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
        //  cout<<lcm(20,3)<<endl;
   int tt=1;      
   cin>>tt; 
   while(tt--)
   {

int x,y;
cin>>x>>y;
if(x==0&&y==0)
cout<<0<<"\n";
else if(is(x*x+y*y))
    cout<<1<<"\n";
else cout<<2<<"\n";



   

}
}