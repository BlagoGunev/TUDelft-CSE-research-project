#include <bits/stdc++.h>

using namespace std;

int main()

{

    int l,m,k,n1,n2,i,count=0;

    string a,b,c;

    int e[2101][2];

    cin>>a>>c;

    b=a;

    reverse(b.begin(),b.end());

    for(i=0;i<c.length();)

    {

        l=0;

        int j=a.length();

        int d=0;

        while(d<j)

        {

            if(a[d]==c[i])

            {

                //cout<<"first\n";

                int k=d+1,m=i+1;

                while(a[k]==c[m]&&k<a.length()&&m<c.length()){m++;k++;}

                if(m-i>l)

                {l=m-i;n1=d,n2=k-1;}

            }

            d++;

        }

        //cout<<l<<n1<<n2<<"\n";

        d=0;

        while(d<j)

        {

            //cout<<b[d]<<c[i]<<" reverse\n";

            if(b[d]==c[i])

            {

                //cout<<"reverse\n";

                //cout<<"yes";

                int k=d+1,m=i+1;

                while(b[k]==c[m]&&k<b.length()&&m<c.length()){m++;k++;}

                if(m-i>l)

                {l=m-i;n1=b.length()-d-1,n2=b.length()-k;}

            }

            d++;

        }

        if(l==0)

        {cout<<"-1";goto l;}

        //cout<<"ehy"<<l<<n1<<n2<<"\n";

        e[count][0]=n1;

        e[count][1]=n2;

        count++;

        i+=l;

        //cout<<n1<<n2<<"\n";

    }

    cout<<count<<"\n";

    for(i=0;i<count;i++)

        cout<<e[i][0]+1<<" "<<e[i][1]+1<<"\n";

    l:

    return 0;

}