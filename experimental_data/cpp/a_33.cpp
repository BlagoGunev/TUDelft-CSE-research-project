// IN THE NAME OF GOD



#include <iostream>



// #include <algorithm>



using namespace std;



int main()

{

    int n;

    cin>>n;

    int m;

    cin>>m;

    int k;

    cin>>k;

    int *a;

    a=new int [m+1];

    a[0]=0;

    for(int i=1;i<=m;i++)

    {

        a[i]=1000001;

    }

    int r;

    int v;

    for(int i=1;i<=n;i++)

    {

        cin>>r;

        cin>>v;

        if(a[r]>v)

        {

            a[r]=v;

        }

    }

    //for(int i=m;i>0;i--)

    //{

        //cout<<a[i]<<endl;

    //}

    int i;

    i=m;

    int sum;

    sum=0;

    while(i>0&&sum!=k)

    {

        if(sum+a[i]<=k)

        {

            sum=sum+a[i];

            i--;

            //cout<<sum<<endl;

        }

        else

        {

            while(a[i]>0&&sum!=k)

            {

                sum++;

                a[i]--;

            }

        }

    }

    cout<<sum;

    return 0;

}