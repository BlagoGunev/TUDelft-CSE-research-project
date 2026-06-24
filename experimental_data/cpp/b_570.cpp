#include <iostream>

#include <vector>

#include <string>

#include <cmath>

#include <map>

#include <set>

using namespace std;

int n,m,x,y,a;

int main(){

cin>>n>>m;

x=abs(n-m);

y=abs(m-1);

if(x>y){cout<<m+1;}

else if(x<y){cout<<m-1;}

else if(n==1 && m==1){cout<<1;}

else cout<<n/2;

return 0;

}