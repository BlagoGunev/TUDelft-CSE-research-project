#include <bits/stdc++.h>
using namespace std;

#define MAX 200005

int nums[MAX], fs[MAX];

void clear (int n){
    for(int i =0; i<min(n+5, MAX); i++){
        nums[i]=fs[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q,n,x,act,rta,f, fallos, fi, se;
    cin>>q;
    while(q--){
        cin>>n;
        priority_queue<pair<int, int> > cola;
        act = MAX;
        rta=fallos=0;
        for(int i =0; i<n; i++){
            cin>>x>>f;
            nums[x]++;
            fs[x]+=f;
        }
        for(int i =1; i<=n; i++){
            if(nums[i]){
                cola.push({nums[i],fs[i]} );
            }
        }
        
        while(!cola.empty() && act){
            fi = cola.top().first, se = cola.top().second;
            if(fi<act){
                rta+=fi;
                act = fi;
                fallos+=se;
                cola.pop();
            }
            else{
                cola.pop();
                cola.push({fi-1,min(se,fi-1)});
            }
            
        }
        cout<<rta<<" "<<fallos<<"\n";
        
        clear(n);
    }
}