#include<bits/stdc++.h>

using namespace std;

int a,b;

vector<int>m;



int f(int k)

{ int sum=0,co=1; while(k!=0)

    {

if(k%10==4 || k%10==7)  {   sum+=co*(k%10);

co*=10;        }k/=10;

    }

return sum;

}



int main()

{ cin>>a>>b;

int x=a+1;



while(f(x)!=b)

{

    x++;



}

cout<<x<<endl;

}