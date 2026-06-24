#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll a[1444];

char s[1004];

int visit[12];

vector<ll>v,x;

int vis[5];



ll ans=999999999999999;



ll fun(int pos,int cur,int bit)

{

   // cout<<pos<<" "<<po<<" "<<mul<

   ll f,ff;

   if(pos==2)

   {



       for(int i=0;i<cur;i++)

       {

           for(int j=i+1;j<cur;j++)

           {

               if(((bit&(1<<i))==0)&&((bit&(1<<j))==0))

               {

                  // cout<<" xdfgd "<<endl;

                   if(s[pos]=='*')

                    return a[i]*a[j];

                   else

                    return a[i]+a[j];

               }

           }

       }

   }

   ll r=ans;

   {



      for(int i=0;i<cur;i++)

      {

                for(int j=i+1;j<cur;j++)

          {

              //cout<<i<<" "<<j<<" "<<endl;

              if(((bit&(1<<i))==0)&&((bit&(1<<j))==0))

              {

                  //cout<<" s "<<endl;

                  f=a[i];

                  ff=a[j];

                  if(s[pos]=='*')

                  {

                      a[cur]=f*ff;



                  }

                  else



                       {

                      a[cur]=f+ff;



                       }

                       ll lbit=bit;

                       lbit=lbit|(1<<i);

                       lbit=lbit|(1<<j);

                      r=min(r, fun(pos+1,cur+1,lbit));





              }

          }



          }

      }

      return r;

   }







int main()

{

    int n;



    for(int i=0; i<4; i++)

    {

        cin>>a[i];



    }

    int mul=0,pos=0;

    for(int i=0; i<3; i++)

        {cin>>s[i];

          if(s[i]=='*')

            mul++;

            else

                pos++;

        }

        //cout<<mul<<" "<<pos<<endl;



    cout<<fun(0,4,0)<<endl;

//    cout<<ans<<endl;



}