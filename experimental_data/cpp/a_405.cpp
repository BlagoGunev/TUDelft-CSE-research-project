#include <bits/stdc++.h>



using namespace std;



int main()

{

long long int i,n,element;

cin>>n;

vector<int> v;

for(i=0;i<n;i++)

{

	cin>>element;

	v.push_back(element);

}



sort(v.begin(),v.end());



for(i=0;i<v.size();i++)

cout<<v[i]<<" ";



return 0;

}