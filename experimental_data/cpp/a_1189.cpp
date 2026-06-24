#include<bits/stdc++.h>
using namespace std;
int main (){
char s[200];
int i,j,n,zero=0,one=0,z1=0,on1=0;
cin>>n>>s;
for(i=0;i<n;i++){
    if(s[i]=='0')
        zero++;
    else
        one++;
}
if(zero>one||one>zero){
    cout<<1<<endl<<s;
    return 0;
}
cout<<2<<endl<<s[0]<<" ";
for(i=1;i<n;i++){
    cout<<s[i];
}
return 0;
}