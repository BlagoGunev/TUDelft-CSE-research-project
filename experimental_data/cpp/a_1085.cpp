#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    string s,n;
    cin>>s;
    int eletemp=floor((s.size()-1)/2);
    for (int i=0;i<s.size();i++){
        eletemp+=i*pow(-1,i+1);
        n+=s[eletemp];
    }
    cout<<n;
    return 0;
}