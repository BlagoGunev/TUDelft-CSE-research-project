#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>
#include <map>
#include <cmath>
#define mod 1000000007
#define lli long long
#define endl '\n'
#define pii pair<long long,long long>
//#define pii pair<int,int>
#define piii pair<pair<long long ,long long> ,long long>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    int n,ans=0;
    cin>>n;
    stack<int> s;
    int i,still=0,rtill=0;
    for(i=0;i<2*n;i++){
        string ss;
        cin>>ss;
        if(ss[0]=='a'){
            int no;cin>>no;
            s.push(no);
        }
        else{
            if(still==s.size())rtill++;
            else if(s.top()==(rtill+1))s.pop(),rtill++;
            else{
                ans++;still=s.size();rtill++;
            }
        }
    }
    cout<<ans;
}