#include <iostream>
using namespace std;

int main()
{
int n;
cin>>n;
int temp=0,sum=0,count=0;
for(int i=0;i<n;i++)
{
    cin>>temp;
    sum += temp;
}

if((sum+1)%(n+1) == 1 ) count++;
if((sum+2)%(n+1) == 1 ) count++;
if((sum+3)%(n+1) == 1 ) count++;
if((sum+4)%(n+1) == 1 ) count++;
if((sum+5)%(n+1) == 1 ) count++;

cout<<5-count;
return 0;
}