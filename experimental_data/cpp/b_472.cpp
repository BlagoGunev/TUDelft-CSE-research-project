#include<iostream>

#include<cstdio>

#include<vector>

#include<algorithm>

#define all(v) v.begin(),v.end()



using namespace std;



int main()

{

    int n,k,i,a,sum=0;

   vector<int>v;

   cin>>n>>k;

   for(i=0;i<n;i++)

   {

       cin>>a;

       v.push_back(a);

   }



   sort(all(v));



   for(i=n-1;i>=0;i-=k)

       sum+=(v[i]-1)*2;



   cout<<sum;

}