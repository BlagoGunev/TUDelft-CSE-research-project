#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
int main()
{
    int n,k,t;
    cin>>n>>k>>t;
    int kolvo=0;
    long long minn=0,maxx=0,maxxx=0;
    for(int i=0;i<k;i++){
        minn+=pow(2,i);
    }
    minn+=n-k;
    for(int i=0;i<t;i++){
        maxx+=pow(2,i);
    }
    for(int i=0;i<n-t;i++){
        maxx+=pow(2,t-1);
    }
    cout<<minn<<" "<<maxx;
  return 0;
}