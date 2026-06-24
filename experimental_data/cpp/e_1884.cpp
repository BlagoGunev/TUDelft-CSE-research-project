#include <bits/stdc++.h>
/*
 Cyclic
 Each "interval" contributes a multiple of a sum of squares or a square
 x^2+(k-x)^2=2(x^2-kx)+k^2
 Express this as prefix sum prefix sum
 x^2+(k-x)^2-(x-1)^2-(k-x+1)^2=(2x-1)-(2*(k-x+1)-1)=2x-1-2k+2x-2+1=4x-2-2k
 Example: 16 10 8 10 16
         [0] -6 -2 2 6 [0]
 
 
 */
int t,n;
int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin>>t;
    for(;t--;){
        std::cin>>n;
        std::vector<int> inums,nums(n);
        int maxnum=0,mxi;
        for(int i=0;i<n;i++){
            int x;
            std::cin>>x;
            inums.push_back(x);
            if(x>maxnum)mxi=i;
            maxnum=std::max(maxnum,x);
        }
        for(int i=0;i<n;i++){
            nums[i]=maxnum-inums[(i+mxi)%n];
        }
        nums.push_back(0);
        std::vector<int> mld(n),mrd(n);
        std::vector<int> lefts;
        lefts.push_back(0);
        for(int i=1;i<n;i++){
            while(nums[i]<nums[lefts.back()]){
                mrd[lefts.back()]=i;
                lefts.pop_back();
            }
            if(lefts.empty())break;
            if(nums[i]>=nums[lefts.back()]){
                mld[i]=lefts.back();
                lefts.push_back(i);
            }
        }
        while(!lefts.empty()){
            mrd[lefts.back()]=n;
            lefts.pop_back();
        }
        std::vector<long long> dprefsums(n+2);
        std::vector<long long> prefsums(n+2);
        std::vector<long long> results(n+2);
        std::vector<long long> numints(n+2);
        for(int i=1;i<n;i++){
            //std::cout<<i<<" l "<<mld[i]<<" r "<<mrd[i]<<'\n';
            long long ntimes=nums[i]-std::max(nums[mld[i]],nums[mrd[i]]);
            long long kvalue=mrd[i]-mld[i]-1;
            dprefsums[mld[i]+2]+=(4ll)*ntimes;
            dprefsums[mrd[i]+1]+=(-4ll)*ntimes;
            prefsums[mld[i]+2]+=(-2ll-2*kvalue)*ntimes;
            prefsums[mrd[i]+1]+=(2ll-2*kvalue)*ntimes;
            results[0]+=kvalue*kvalue%1000000007*ntimes%1000000007;
            numints[mld[i]+2]+=ntimes;
            numints[mrd[i]]-=ntimes;
            numints[0]+=ntimes;
        }
        results[0]%=1000000007;
        std::vector<std::pair<long long,int>> eresults(n);
        for(int i=0;i<n;i++){
            if(i){
                dprefsums[i]+=dprefsums[i-1];
                dprefsums[i]%=1000000007;
                prefsums[i]+=prefsums[i-1]+dprefsums[i];
                prefsums[i]%=1000000007;
                results[i]+=results[i-1]+prefsums[i];
                results[i]%=1000000007;
                numints[i]+=numints[i-1];
            }
            eresults[i]={numints[i],results[i]};
        }
        for(int i=0;i<n;i++)std::cout<<numints[(i-mxi+n)%n]<<' '<<(results[(i-mxi+n)%n]+1000000007)%1000000007<<'\n';
    }
}