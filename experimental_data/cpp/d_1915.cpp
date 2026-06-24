#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
   int n,index1=0;
   string s;
   cin>>n>>s;
   while(index1<n){
       if(s[index1]!='a' and s[index1]!='e'){
           if(index1!=0){
               cout<<".";
           }
           cout<<s[index1];
       }
       else {
           if((s[index1+2]=='a' or s[index1+2]=='e' && index1+2<n )or index1==n-1){
               cout<<s[index1];
           }
           else {
               cout<<s[index1]<<s[index1+1];
               index1++;
           }
       }
   index1++;
   }
   cout<<"\n";
    }
}