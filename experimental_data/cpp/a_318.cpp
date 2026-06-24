#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <limits.h>
using namespace std;

int main()
{
 //    freopen("C:\\Users\\jack\\Desktop\\in.txt","r",stdin);
   // freopen("C:\\Users\\jack\\Desktop\\out.txt","w",stdout);
    int test;
    long long int n,k,ans;
   // while(1)
{     cin>>n>>k;
     
     if(k<=((n/2)+n%2))
     {
         
         cout<<(k<<1)-1;
         
         }
     else
       {
           k=k-((n/2)+n%2);
           cout<<(k<<1);
           
           }




}



         }