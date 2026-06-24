#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,k,x;

vector<pair<int ,int> >f;

vector<int>yara;

int main(){

freopen ("input.txt","r",stdin);

freopen ("output.txt","w",stdout);

cin>>n>>k;

for(int i=0;i<n;i++){cin>>x;f.push_back(make_pair(x,i+1));}

   sort(f.begin(),f.end(),greater<pair<int,int> >());

     for(int i=0;i<k;i++){yara.push_back(f[i].second);if(i==k-1)cout<<f[i].first<<endl;}

         sort(yara.begin(),yara.end());

           for(int i=0;i<yara.size();i++)cout<<yara[i]<<" ";

             cout<<endl;

               return 0;

}