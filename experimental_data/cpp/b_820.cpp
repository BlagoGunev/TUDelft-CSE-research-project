#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
const int mod = 1e9+7;
const int _max = 1e6+6;
int main(){
    ios_base::sync_with_stdio(false);
    ll n,a;
    cin>>n>>a;
    ll intangle =(n-2)*180;
    double first = (double)intangle/(double)n;
    double _min = 1e9,sum,diff,other;
    ll cod;
    for(int i=3;i<=n;i++){
        sum = (i-2)*180;
        other = (sum - (i-2)*first)/2;
        diff = fabs(other-a);
        if(diff < _min){
            _min = diff;
            cod = 1 + (i-1);
        }
    }
    cout<<"1 "<<cod<<" "<<cod-1<<endl;
    return 0;
}