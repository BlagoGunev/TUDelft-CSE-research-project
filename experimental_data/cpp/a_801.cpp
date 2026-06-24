#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string s;
    string m="VK";
    int c=0;
    int flag=1;

    cin>>s;


    if(s.size()==1)
    {
         cout<<"0"<<endl;
         return 0;
    }

    else
    {
    if(s==m)
       {
         c++;

       }
    else{
      for(int i=0;i<=(s.size()-1);)
      {

        if(s[i]==m[0]&&s[i+1]==m[1])
        {
            c++;
            i+=2;
            //cout<<s[i]<<" : "<<c;
        }
        else if(s[i]==s[i+1]&&flag!=0)
        {
            if((s[i]==m[0]&&s[i+2]!=m[1])||(s[i]==m[1]))
            {
                c++;
                i+=2;
                flag=0;

                //cout<<"flag: "<<s[i]<<": "<<c;
            }
            else
                i++;
        }
        else
            i++;
      }
    }
     cout<<c<<endl;
    }
}