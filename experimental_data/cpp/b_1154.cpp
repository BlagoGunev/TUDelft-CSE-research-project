#include <bits/stdc++.h>

using namespace std;


int main()
{
    int o=0;
    long long b,n,count;
    float m;
    vector<long long>a,f;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    b=*max_element(a.begin(),a.end());
    long long i;
    for(i=0;i<b;i++){
        count=0;
        long long c1=a[0]+i,c2=a[0]-i;
        // for(long long j=1;j<n;j++){
        //     if((a[j]+i)==c1 || (a[j]-i)==c1 || (a[j]+i)==c2 || (a[j]-i)==c2 || (a[j]+i)==a[0] || (a[j]-i)==a[0] ) 
        //      count++;
        //     else break;
        // }
        for(long long j=1;j<n;j++){
            if((a[j]+i)==c1 || (a[j]-i)==c1 || a[j]==c1)
             count++;
            else break;
        }
        if(count==n-1) {
            o++;
            break;
        }
        count=0;
            for(long long j=1;j<n;j++){
            if((a[j]+i)==c2|| (a[j]-i)==c2 || a[j]==c2)
             count++;
            else break;
        }
          if(count==n-1) {
            o++;
            break;
        }
        

        count=0;
            for(long long j=1;j<n;j++){
            if((a[j]+i)==a[0]|| (a[j]-i)==a[0]|| a[j]==a[0])
             count++;
            else break;
        }
          if(count==n-1) {
            o++;
            break;
        }
        
    }
    if(o==0) cout<<-1<<"\n";
    else cout<<i<<"\n";
return 0;
}