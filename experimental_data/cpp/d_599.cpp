#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    vector <pair <unsigned long long,unsigned long long> > v;
    unsigned long long n;
    cin>>n;
    unsigned long long z = 1;
    unsigned long long zp = 2;
    unsigned long long d = 0;
    unsigned long long dp = 0;
    for(unsigned long long i=1; i*i <= n; i++){
        if( (n+d) < i*z){
            //cout<<n+d<<" "<<i*z<<endl;
            break;
        }
        if( (n + d)%z ==0 ){
            v.push_back(make_pair(i,(n+d)/z));
            if(i != (n+d)/z)
                v.push_back(make_pair((n+d)/z,i));
        }
        z += zp;
        zp++;
        dp += i;
        d += dp;
    }
    sort(v.begin(),v.end());
    
    cout<<v.size()<<endl;
    for(unsigned long long i=0;i<v.size()-1;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<v[v.size()-1].first<<" "<<v[v.size()-1].second<<endl;
    
    
    return 0;
}