#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a1,a2,b1,b2,c1,c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
   	long long p = (a1-b1)*(a1-b1); p+= (a2-b2)*(a2-b2);
   	long long q = (b1-c1)*(b1-c1); q+= (b2-c2)*(b2-c2);
   	long long r = (a1-c1)*(a1-c1); r+= (a2-c2)*(a2-c2);
   	if(p==q && (a1*(b2-c2) + b1*(c2-a2) + c1*(a2-b2) != 0)) cout << "Yes"<<endl;
   	else {cout << "No"<<endl;}
    return 0;
}