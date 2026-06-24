#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,h,m;
    cin>>n>>h>>m;
    vector<int> l,r,x,random;
    for(int i = 0;i<n+1;i++){
        random.push_back(-1);
    }
    for(int i = 0;i<m;i++){
        int l1,r1,x1;
        cin>>l1>>r1>>x1;
        for(int j = l1-1;j<r1;j++){
           if(random[j]!=-1 && (x1 * x1)<random[j]){
               random[j] = x1*x1;
           }
           else if(random[j]==-1){
               random[j] = x1 * x1;
           }
           
        }
        
    
    }
    int sum = 0;
    for(int i = 0;i<n;i++){
     if(random[i]==-1){
         sum+= h*h;
     }
     else{
         sum+= random[i];
     }
    }
    cout<<sum;
    
}