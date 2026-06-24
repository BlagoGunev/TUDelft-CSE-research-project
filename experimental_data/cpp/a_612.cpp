#include<bits/stdc++.h>



using namespace std;



int main()

{

    string s ;

    int n,p,q ,mn,i,j;



    cin>>n>>p>>q>>s;



    mn = min(p,q);

    int mx = max(p,q);



    for(i=0 ; mx*i<=n ; i++)

    {

        for(j=0 ; j*mn+i*mx <=n ; j++)

        {



            if(j*mn+i*mx == n)

            {

                p = mn;

                q = mx ;

                n = 0 ;

                break ;

            }

        }

        if(!n)break;

    }

    //cout<<i<<" "<<j<<endl;

    if(n)

    {

        cout<<"-1";

        return 0 ;

    }



    int k=0 ;

    //cout<<i<<" "<<j<<endl;

    swap(i,j);

    mx += i*mn ;

    cout<<i+j<<endl;

    for( ; i; i-- ,mn+=p , cout<<endl)

    {

        for(; k<mn && s[k] ; k++)cout<<s[k];

    }



    for( ; j; j-- , cout<<endl, mx+=q)

    {



        for(; k<mx && s[k] ; k++)cout<<s[k];



    }







    return 0 ;

}