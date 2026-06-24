#include <bits/stdc++.h>

using namespace std;

#define S second

#define F first

#define MOD 1000000007

typedef long long llint;

typedef pair<int,int> pii;

int main()

{

   int N;

   cin>>N;

   vector<string> a(N);

   for(auto& e:a) cin>>e;

   int maxi = 0;

   for(char i='a';i<='z';++i)

        for(char j='a';j<='z';++j)

   {

       int now=0;

       if(i!=j)

       {

           for(string e:a)

           {

               if(count(e.begin(),e.end(),i)+count(begin(e),end(e),j)==e.size()) now+=e.size();

           }

       }

       else

       {

          for(string e:a)

           {

               if(count(e.begin(),e.end(),i)==e.size()) now+=e.size();

           }

       }

       maxi=max(maxi,now);

   }



    cout<<maxi;



return 0;

}