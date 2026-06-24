#include <bits/stdc++.h>

#include <fstream>



typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;



using namespace std;



double Fib(double x,double z);

string BinDec(ull x);

string StringInt(ll x);

ull StringInt(string x);

ull BinDec (string x);

ull POWMOD (ull x,ull y,ull mod);

ull POWE(long long , long long);





struct trie

{

    trie *child[2];

    int one,zero,is;

    trie()

    {

        memset(child,0,sizeof(child));

        one=zero=is=0;

    }

    void insert (char *str)

    {

        if(*str==0)is=1 ;

        else{

               // cout<<*str;

        int in=(*str)-'0';

        if(in==0)zero++;

        else if(in==1)one++;

        if(child[in]==0)

            child[in]=new trie();

        child[in]->insert(str+1);

        }

    }

    void remove(char *str)

    {

        if(*str==0)is=0;

        else{

        int in=*str-'0';

        if(in==0)zero--;

        if(in==1)one--;

        if(child[in]==0)

            child[in]=new trie();

        child[in]->remove(str+1);



        }

    }

    void get(char *str,ll & a,ll b)

    {

      //  cout<<a<<' '<<b<<endl;

        if(*str==0);

        else{

        int in=*str-'0';

        if(in==0&&one>=1)

        {

            a+=b;

            child[1]->get(str+1,a,b/2);

        }

        else if(in==1&&zero>=1)

        {

            a+=b;

            child[0]->get(str+1,a,b/2);

        }

        else

        child[in]->get(str+1,a,b/2);

        }

    }



};





int main()

{



    ios::sync_with_stdio(false);

    cin.tie(0);



    int a,b,c,x,y,z,aa,bb,cc,i,j,k,t,tt,ttt,at,de,tim,ans=1e7;

    cin>>a>>b>>c;

    cin>>x>>y>>z;

    cin>>aa>>bb>>cc;

    for(i=0;i<200;i++)

    {

        for(j=max(0,z-b+1);j<200;j++)

        {

            t=max((b+j)-z,0);

            tt=c+i;

            at=x/t;

            if(x%t!=0)at++;

            de=max(y-tt,0);

            de*=at;

            if(de<a)

                k=0;

            else

            {

                k=de-a+1;

            }

            ans=min(ans,(k*aa)+(j*bb)+(i*cc));

          //  cout<<ans<<' '<<k<<' '<<de<<' '<<at<<' '<<t<<' '<<tt<<endl;



        }

    }

    cout<<ans;







    return 0;

}



double Fib(double x,double z){

    int i=0;

    double f=x,r=x,t;

    for(i=2;i<z;i++)

    {

        t=f;

        f+=r;

        r=t;

    }

    return f;



}

string BinDec( ull x){

    string z;

    while(1)

    {

        z+=((x%3)+'0');

        x/=3;

        if(x==0)

            break;

    }

    while(1)

    {

        if(z.size()==30)

            break;

        z+='0';

    }

    reverse(z.begin(),z.end());

    return z;

}

ull BinDec(string x){

    long long i;

    unsigned long long z=1,a=0;

    for(i=x.size()-1;i>=0;i--)

    {

        if(x[i]=='1')

            a+=z;

        if(x[i]=='2')

            a+=(2*z);

        z*=3;

    }

    return a;

}

ull StringInt(string x){

   ull z=0,i;

   for(i=0;i<x.size();i++)

   {

       z*=10;

       z+=(x[i]-'0');

   }

   return z;

}

string StringInt(ll x){

    string z;

    while(x!=0)

    {

        z+=(x%10+'0');

        x/=10;

    }

    reverse(z.begin(),z.end());

    return z;

}

ull POWMOD (ull base,ull exp,ull mod){

    ull res=1;

    while(exp>0){

        if(exp%2==1)

            res=(res*base);

            res%=mod;

        exp/=2;

        base=(base*base);

        base%=mod;

    }

return res%mod;

}

ull POWE(long long base,long long exp){

    ull res=1;

    while(exp>0){

        if(exp%2==1)

            res=(res*base);

        exp/=2;

        base=(base*base);

    }

return res;



}



/*

int s=0,c[1553][1553]={},z;

char a[1550][1550]={};

void lol(char m,int i,int j,int & s)

{



    if(c[i][j+1]==0&&a[i][j+1]==m)

    {

        s++;

        c[i][j+1]=1;

        lol(m,i,j+1,s);

    }

    if(c[i][j-1]==0&&a[i][j-1]==m)

    {

        s++;

        c[i][j-1]=1;

        lol(m,i,j-1,s);

    }

    if(c[i-1][j]==0&&a[i-1][j]==m)

    {

        s++;

        c[i-1][j]=1;

        lol(m,i-1,j,s);

    }

    if(c[i+1][j]==0&&a[i+1][j]==m)

    {

        s++;

        c[i+1][j]=1;

        lol(m,i+1,j,s);

    }

    if(z!=0)

    {

        z--;

        a[i][j]='X';

    }

    return;

}*/