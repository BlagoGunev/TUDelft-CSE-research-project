#include <bits/stdc++.h>



using namespace std;

#define int long long

const int sz=250;

double h[100000];

vector<double> expv(vector<double> v)

{

    vector<double> res(sz);for(int i=0;i<sz;++i) res[i]=0;

    double fa=1;

    vector<double> cur1(sz),cur2(sz);

    fill(cur1.begin(),cur1.end(),0);cur1[0]=1;

    int j=0;

    while(*max_element(cur1.begin(),cur1.end())*1e15>fa) 

    {

    ++j;

    fill(cur2.begin(),cur2.end(),0);

    for(int i=0;i<sz;++i)

    {

        for(int j=0;i+j<sz;++j)

        {

            cur2[i+j]+=cur1[i]*v[j];

        }

    }

    for(int i=0;i<sz;++i) {res[i]+=(cur1[i]/fa);}

    fa*=j;

    fa=min(fa,1e300);

    cur1=cur2;

    }

    return res;

}

const double lambda=0.5772156649015328606065120900824024310421;

vector<double> get(int n)

{

    vector<double> v(sz);fill(v.begin(),v.end(),0);

    if(n==1) {v[0]=1;return v;}

    for(int j=1;j<=20000;++j) h[j]=1;

    for(int i=0;i<sz;++i)

    {

        double sum=0;

        int bn=min(((int) (20000)),n);

        if(i>=50) sum=1;

        else {

        for(int j=1;j<bn;++j)

        {

            sum+=h[j];

            h[j]/=j;

        }}

        if(i==0)

        {

            sum+=(n-bn);

        }

        else if(i==1)

        {

            if(n>bn) {sum=log((n-1))+lambda+1/(2*1.0*(n-1))+(1/(6*2*1.0*(n-1)*(n-1)));}

        }

        else if(i==2)

        {

            sum+=(1.0/(bn-0.5)-1.0/(n-0.5));

        }

        if(i==0) continue;

        sum/=i;if(i%2==0) sum*=(-1);

        v[i]=sum;

    }

    vector<double> res=expv(v);

    for(int i=0;i<sz;++i) {res[i]/=n;}

    return res;

}

int32_t main()

{

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,m;cin>>n>>m;

    int a[m];for(int i=0;i<m;++i) cin>>a[i];

    vector<vector<double> > v;

    for(int i=0;i<m;++i)

    {

        v.push_back(get(n-a[i]));

    }

    double ans[m]={0};

    double sums[m]={0};

    for(int i=0;i<sz;++i)

    {

        for(int j=0;j<m;++j)

        {

            double pro=v[j][i];

            for(int k=0;k<m;++k)

            {

                if(k!=j)

                {

                    pro*=(1-sums[k]);

                }

            }

            ans[j]+=pro;

        }

        for(int j=0;j<m;++j)

        {

            sums[j]+=v[j][i];

        }

    }

    for(int i=0;i<m;++i)

    {

        cout<<fixed<<setprecision(25)<<ans[i]<<' ';

    }

    return 0;

}