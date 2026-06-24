#include<bits/stdc++.h>

using namespace std;

int main(){
   
    int p,a,x,b,y;
    
    cin>>p>>a>>x>>b>>y;

    int cnt = 0;

    while (++a , --b,++cnt) {
      if (a > p)    a = 1;
      if (b < 1)    b = p;

      if (a == b)
        return cout << "Yes" << endl, 0;
      if (a == x or b == y)break;
    }
    cout<<"No"<<endl;
    return 0;
}