#include<bits/stdc++.h>

using namespace std;



int main()



{

 int t;

 cin>>t;

 while (t--)

 {

    int n;

    cin>>n;

    vector<int>v;

    for (int i = 0; i < n; i++)

    {

        for (int j = 1; j<=n; j++)

        {if (i!=j-1)

        {

            v.push_back(j);

            i++;

            

        }

        }

        

    }

    v.push_back(1);

    for (auto value:v)

    {

        cout<<value<<" ";

    }

    

  cout<<endl;

 }

 

}