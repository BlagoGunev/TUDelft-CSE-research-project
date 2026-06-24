#include <iostream>

using namespace std;

int n,k,x,t,f;

int main(){cin>>t;while(t--){cin>>n>>k;f=0;for(int i=0;i<n;i++){cin>>x;f+=(i<k&&x>k);}cout<<f<<endl;}}