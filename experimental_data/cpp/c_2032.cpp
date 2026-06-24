#include <bits/stdc++.h>
using namespace std;

int n,c,d,k,a[200005];
typedef long long ll;


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

int t;
cin>>t;
while(t--)
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
   cin>>a[i];
   }
   sort(a,a+n);
   int j=0;
   d=0;
   for(int i=0;i<n-1;i++)
   {
   	while(a[j]<a[i]+a[i+1]&&j<n)j++;
   	d=max(d,j-i);
   }
   cout<<n-d<<"\n";
}


  return 0;
}