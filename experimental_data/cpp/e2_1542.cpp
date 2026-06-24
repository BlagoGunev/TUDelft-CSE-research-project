#include<bits/stdc++.h>

int i,j,n,nxd,m=150000;

long long res[505],f[300500],g[300500],M;

int main(){

    std::cin>>n>>M;

    f[m]=1;

    for(i=1;i<n;i++){

        nxd+=i;

        for(j=m-nxd-i-1;j<=m+nxd+i+1;j++)g[j]=(g[j-1]+f[j])%M;

        for(j=m-nxd-1;j<m+nxd;j++){

            f[j+1]=(f[j]+g[j+i+1]-g[j]*2+g[j-i-1])%M;

            if(j>m&&j<=m+i)(res[i+1]+=(g[nxd+m]-g[j])*(i+1+m-j))%=M;

        }

    }

    for(i=1;i<=n-1;i++)(res[i+1]+=res[i]*(i+1))%=M;

    std::cout<<(res[n]+M)%M<<'\n';

}