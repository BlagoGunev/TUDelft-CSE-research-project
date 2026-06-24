#include <iostream>



using namespace std;

long long p,q,r,j,x,y,l,sol,i,smen[2016],a[60],b[60],c[60],d[60];

int main()

{

    cin>>p>>q>>l>>r;

    for(i=1;i<=p;i++)

        cin>>a[i]>>b[i];

    for(i=1;i<=q;i++)

        cin>>c[i]>>d[i];

    for(i=1;i<=p;i++)

        for(j=1;j<=q;j++)

        {

            x=max(a[i]-d[j],l);

            y=min(b[i]-c[j],r);

            if(x<=y)

                smen[x]++,smen[y+1]--;

        }

    for(i=l;i<=r;i++)

    {

        smen[i]+=smen[i-1];

        if(smen[i])sol++;

    }

    cout<<sol;

    return 0;

}