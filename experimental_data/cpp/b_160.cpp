#include<bits/stdc++.h>

using namespace std ;

int main()

{

    int n ;

    cin >> n ;

    string s ;

    cin >> s ;

    string ss = s.substr(0,n) ;

    string ss2 = s.substr(n,2*n) ;

   // cout<<ss<<" "<<ss2<<endl ;

   sort(ss.begin(),ss.end()) ;

   sort(ss2.begin(),ss2.end() );

   int flag = 0 ;

   int count=0 ;

   for(int i=0;i<ss.size();i++)

   {

       int a = ss[i] - '0' ;

       int b = ss2[i] - '0' ;

       if(a>b)

       count++ ;

       else if(a<b) flag++ ;

   }

   if(flag==n||count==n)cout<<"YES"<<endl ;

   else cout<<"NO"<<endl ;



}