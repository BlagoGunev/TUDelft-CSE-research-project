#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
vector<int> v(100000);
int bb(int a,int b,int x){
    int m=(a+b)/2;
    if(a>b)
        return a;
    if(v.at(m)==x)
        return m;
    if(v.at(m)<x) return bb(a,m-1,x);
    return bb(m+1,b,x);
}
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++) {scanf("%d",&v.at(i));}
    if(n==1){
        if(v.at(0)<0)
            printf("%d\n",v.at(0)*(-1)-1);
        else
            printf("%d\n",v.at(0));
    }
    else{
        for(i=0;i<n;i++) if(v.at(i)>=0) v.at(i)=v.at(i)*(-1)-1;
        j=0; k=v.at(0);
        for(i=0;i<n;i++) if(v.at(j)>v.at(i)) { j=i; }
        if(n%2==1)
            v.at(j)=v.at(j)*(-1)-1;
        for(i=0;i<n;i++) printf("%d ",v.at(i)); printf("\n");

//        sort(v.begin(),v.begin()+n);
////        for(i=0;i<n;i++) printf("%d ",v.at(i)); printf("\n");
//        k=bb(0,n-1,0);
////        cout<<k<<endl;
//        for(i=k;i<n;i++) if(v.at(i).first==0) v.at(i).first=v.at(i).first*(-1)-1; else break;
//        for(i=k-1;i>=0;i--) if(v.at(i).first==0) v.at(i).first=v.at(i).first*(-1)-1; else break;
//        sort(v.begin(),v.begin()+n);
//        k=bb(0,n-1,0);
//
//        if(n%2==0)
//            for(i=n-1;i>=0;i--) if(v.at(i).first>0) v.at(i).first=v.at(i).first*(-1)-1; else break;
//        else{
//            if(k<n)
//                for(i=k;i<n;i++) v.at(i).first=v.at(i).first*(-1)-1;
//            if(k==n){
//                sort(v.begin(),v.begin()+n);
//                k=bb(0,n-1,-2);
//                for(i=k;i>=0;i--) if(v.at(i).first!=-1){ v.at(i).first=v.at(i).first*(-1)-1; break; }
//            }
//        }
//        vector<int> res(100000);
//        for(i=0;i<n;i++) res.at(v.at(i).second)=v.at(i).first;
//        for(i=0;i<n;i++) printf("%d ",v.at(i)); printf("\n");
    }
return 0;
}