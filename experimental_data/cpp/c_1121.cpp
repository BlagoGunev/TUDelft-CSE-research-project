#include <bits/stdc++.h>
using namespace std;

int curr[1000+50];
int pro[1000+50];
bool intere[1000+50];
int total[1000+50];
bool found[1000+50];
int a[1000+1];
int main()
{
    // cout << "Hello World!" << endl;
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    if(k>n){
        k=n;
    }
    int bc=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(bc==k){
            
        }
        else{
            total[bc++]=a[i];
            pro[bc-1]=i;
        }
    }
    int nextprocess=k;
    int m=0;
    int ans=0;
    int cnt=0;
    while(1){
        bool done=true;
        int extram=0;
        // cout<<"Loop count = "<<++cnt<<"::::::\n";
        for(int i=0;i<k;i++){
            
            if(total[i]==-1){
                continue;
            }
            if(curr[i]<total[i]){
                
                done=false;
                curr[i]++;
                // cout<<curr[i]<<" : : "<<total[i]<<"@@@@\n";
                // if(1){
                //     cout<<curr[i]<<" , "<<(int)(100.0*(double(m)/double(n))+0.5)<<"\n";
                // }
                
                if(curr[i]==(int)((100.0*(double(m)/double(n)))+0.5)){
                    
                    intere[pro[i]]=true;
                    
                    ans++;
                }
                
                
                
                if(curr[i]==total[i]){
                    extram++;
                    
                    if(nextprocess<n){
                        curr[i]=0;
                        total[i]=a[nextprocess];
                        pro[i]=nextprocess;
                        nextprocess++;
                    }
                    else{
                        total[i]=-1;
                    }
                }
            }
        }
        
        
        if(done){
            break;
        }
        else{
            m+=extram;
        }
    }
    // cout<<ans;
    ans=0;
    for(int i=0;i<n;i++){
        if(intere[i]==true){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}