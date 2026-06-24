#include<bits/stdc++.h>
using namespace std;
int s[1000];
int main(){
    int a,ans=0;
    int sum=1; 
    cin>>a;
    while(a>0){//一位一位转成二进制
        s[sum++]=a%2;
        a/=2;
    }
    swap(s[1],s[5]);//交换
    swap(s[3],s[4]);
    for(int i=63;i>0;i--){//将新数从二进制转为十进制
        ans=ans*2+s[i];
    }
    cout<<ans;
    return 0;
}