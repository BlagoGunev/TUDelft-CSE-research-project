#include<bits/stdc++.h>



using namespace std;



int main()

{

    string s;



    int i;



    char j;



    vector < char > v,temp,vv;



    cin>>s;



    for(i=0; i<s.size(); i++)

    {

        v.push_back(s[i]);

    }



    vv=v;



    vector < char > :: iterator it;



    for(i=0; i<=s.size(); i++)

    {

        for(j='a'; j<='z'; j=j+1)

        {

            it=v.begin()+i;



            v.insert(it,j);



            temp=v;



            reverse(temp.begin(),temp.end());



            if(temp==v)

            {

                for(i=0; i<v.size(); i++)

                {

                    cout<<v[i];

                }



                return 0;

            }



            /*for(i=0; i<v.size(); i++)

            {

                cout<<v[i];

            }



            cout<<endl;*/



            v=vv;









        }

    }



    cout<<"NA"<<endl;



    return 0;



}