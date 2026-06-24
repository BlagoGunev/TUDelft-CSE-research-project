/**Bismillahir Rahmanir Rahim

   In the name of ALLAH, most gracious, most merciful */



#include<bits/stdc++.h>



#define pr pair<long,long>

#define prr pair<pair<long,long>,pair<long,long>>

#define ff first

#define ss second

#define mp make_pair

#define pb push_back

#define MOD 1000000007



#define pi 2*acos(0.0)

#define eps 1e-9

#define mem(x,v) memset(x,v,sizeof(x))



using namespace std;



int main()

{

    ios_base::sync_with_stdio(0);



    long i,k,n,x,p,l;

    string s;

    while(cin>>s)

    {

        x=0;

       l=s.size();

       for(i=l-1;i>=0;i--)

       {

           if(s[i]=='e')

           {

               p=i;

               break;

           }

       }

       for(i=p+1;i<l;i++)

        x=x*10+s[i]-48;

       //cout<<x<<endl;

       l=p;

       for(i=0;i<l;i++)

       {

           if(s[i]=='.')

            break;

           cout<<s[i];

       }

       //cout<<endl;

       for(k=i+1;k<=i+x;k++)

       {

           if(k<l)

            cout<<s[k];

           else

            cout<<"0";

       }

      // cout<<endl;

       if(k<l)

       {

           if(s[k]=='0'&&k+1>=l)

           {

               cout<<endl;

               break;

           }



           cout<<".";

           for(i=k;i<l;i++)

            cout<<s[i];

       }

       cout<<endl;

    }

	return 0;

}