#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <long long> s,s1,s2,s3;
long long n;
long long sum (long long l,long long r)
{
    if (l==r) return 0;
    if (l>r) return 0;
    if (l==0) return s1[r-1];
    return (s1[r-1]-s1[l-1]);
}
int main()
{
    cin>>n;
    s.resize(n);
    for (long long i=0;i<n;i++) cin>>s[i];
    s1.resize(n);
    s1[0]=s[0];
    for (long long i=1;i<n;i++) s1[i]=s1[i-1]+s[i];
    s2.resize(n+1);
    s3.resize(n+1);
    s2[0]=0;
    for (long long i=1;i<=n;i++) if (sum(0,i)>sum(0,s2[i-1])) s2[i]=i; else s2[i]=s2[i-1];
    s3[n]=n;
    for (long long i=n-1;i>=0;i--) if (sum(0,i)>sum(0,s3[i+1])) s3[i]=i; else s3[i]=s3[i+1];
    long long a,b,c,smx=-1;
    for (long long i=0;i<=n;i++)
    {
        if (sum(0,s2[i])-sum(s2[i],i)+sum(i,s3[i])-sum(s3[i],n)>smx) {smx=sum(0,s2[i])-sum(s2[i],i)+sum(i,s3[i])-sum(s3[i],n); a=s2[i]; b=i;c=s3[i];}

    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}