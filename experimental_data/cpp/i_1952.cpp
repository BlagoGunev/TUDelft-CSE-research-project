#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    char ch;
    char space;
    cin>>a>>ch>>b;
    cout<<a+b+((a*a+b*b)+(a-b)+abs(a)*2*b-((a*b)+2))<<endl;
    return 0;
}