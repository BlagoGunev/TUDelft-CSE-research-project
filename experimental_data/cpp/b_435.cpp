#include<bits/stdc++.h>

using namespace std;

int main()

{

      long long n,i=0,k,j,m=0,a[101],t;

      char ch[101];

      cin>>ch>>k;

      if(!k)

      {

            cout<<ch;

            return 0;

      }

      for(i=0;ch[i];i++)

      {

            a[i+1]=ch[i]-'0';

      }

      //cout<<i<<a[i];

      int y=i;

      int d;

      for(j=1;j<i;j++)

      {

            if(k){

            int v=0;

            if(k<i-j+1)

            d=k+j;

            else

            d=i;

            m=0;

          //  cout<<i-j+1<<" "<<d<<" "<<k;

            for(int r=j;r<=d;r++)

            {

                if(m<a[r])

                {

                      m=a[r];

                      v=r;

                }

            }

            if(j==v)

            continue;

            else if(v)

            {

                  for(int u=v;u>j;u--)

                  {

                        a[u]=a[u-1];

                        k--;

                        //cout<<a[u]<<" ";

                  }

                  a[j]=m;

                  //cout<<a[j]<<"\n";

            }

            }

            /*for(int l=1;l<=i;l++)

            cout<<a[l];

           cout<<"\n";*/

      }

      for(int p=1;p<=i;p++)

      cout<<a[p];

}