// Author : jb

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
int main()
{   
    IOS;
  int n , m , b  ;
  cin>>n;
  b = n ;
  if(n%2==0)
  n = n + 1 ;
  m = (n+1)/2;
  cout<<m<<endl;
	 for(int i = 1; i < m+1&&b!=0 ; i++,b--)
     {
	 	cout<<"1"<<" "<<i<<endl;
	 }
	 for(int i = 2 ; i<m+1&&b!=0; i++,b--)
	 {
	 	cout<<i<<" "<<m<<endl;
	 }
	 	

}