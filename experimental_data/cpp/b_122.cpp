#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<sstream>
using namespace std;
 int main(){
       string s;
       cin>>s;
       int n=s.length();
       int c1=0,c2=0;
       for(int i=0; i<n; i++){
           if(s[i]=='4')
            c1++;
           };
      for(int i=0; i<n; i++){
           if(s[i]=='7')
            c2++;
           };
       if(c2>c1){printf("7\n");return 0;}
       if(c1!=0 || c2!=0){printf("4\n");return 0;}
       printf("-1\n");
       return 0;
}