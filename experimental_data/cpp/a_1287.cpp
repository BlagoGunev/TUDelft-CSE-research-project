#include<bits/stdc++.h>
using namespace std;
int A,B,C,W;
string s;
int main()
{
cin>>A;
while(A--)
{
cin>>B>>s;C=W=0;
while(B--)
{
if(s[B]=='P')C++;
else W=max(C,W),C=0;
}
cout<<W<<endl;
}}