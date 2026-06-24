#include<bits/stdc++.h>

using namespace std;

#define ll long long



int main()

{

ios_base::sync_with_stdio(0);

cin.tie(0); cout.tie(0);

int t; cin>>t;

while(t--){

int n; cin>>n;

vector <int> v;

for (int i = 1; i <= n; i++)

{

    int x; cin>>x;

    v.push_back(x-i);

}

cout<<*max_element(v.begin(),v.end())<<endl;

}

return 0;

}