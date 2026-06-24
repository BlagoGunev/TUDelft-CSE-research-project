#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
//stringvalues = "125 320 512 750 333";
 // istringstream iss (stringvalues,istringstream::in);
vector< pair<int,pii > > a;
//vi a;
int main(){
    int d,sum,x,y,s1,s2;
    s1=s2=0;
    cin>>d>>sum;
    REP(i,d){
        cin>>x>>y;
        
        a.pb(pair<int ,pii >( y-x, pii(x,y)));
        s1+=x;
        s2+=y;
    }
    if(!(sum>=s1 && sum<=s2)){
        cout<<"NO"<<endl;
        return 0;
    }
    sum-=s1;
    cout<<"YES"<<endl;
    REP(i,d-1){
        if(sum-a[i].first>=0){
            cout<<a[i].first+a[i].second.first<<' ';
            sum-=a[i].first;
        }
        else{
            cout<<a[i].second.first+sum<<' ';
            sum=0;
        }
    }
    if(sum-a[a.size()-1].first>=0){
            cout<<a[a.size()-1].first+a[a.size()-1].second.first<<endl;
            sum-=a[a.size()-1].first;
            //cout<<"ajab";
        }
        else{
            cout<<a[a.size()-1].second.first+sum<<endl;
        }
        return 0;
}