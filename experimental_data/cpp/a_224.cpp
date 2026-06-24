#include<iostream>
#define all(c) c.begin(),c.end()
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    vector<int> x(3);
    for(int i=0;i<3;i++){
        cin>>x[i];
    }
    int a,b,c;
    c=x[1]*x[2]/x[0];
    
    for(int i=1;i<=c;i++){
        if(i*i==c){
            c=i;
            break;
        }
    }
    
    a=x[2]/c;
    b=x[0]/a;
    cout<<(a+b+c)*4<<endl;
    
    
    return 0;
}