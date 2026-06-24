#include<bits/stdc++.h>
using namespace std;
#define show(x) cerr<<"#x is: "<<x<<endl;
string a,b;
int dp[202][202][1002];
int solve(int posa,int posb,int sum)
{
    if(posa>=a.size() && posb>=b.size() && sum==0)
        return 0;
    if(sum>=900) return 1000000000;
    //cout<<posa<<" "<<posb<<" "<<sum<<endl;
    //getchar();
    if(dp[posa][posb][sum]!=-1) return dp[posa][posb][sum];
    int op = 1000000000;
//    op = min(op,solve(posa+(posa<a.size() && a[posa]=='('),posb,sum+1));
//    op = min(op,solve(posa, posb+(posb<b.size() && b[posb]=='('),sum+1));
    if(posa<a.size() || posb<b.size() )op = min(op,solve(posa+(posa<a.size() && a[posa]=='('), posb+(posb<b.size() && b[posb]=='('),sum+1));
    if(sum) op = min(op,solve(posa+(posa<a.size() && a[posa]==')'), posb+(posb<b.size() && b[posb]==')'),sum-1));
    return dp[posa][posb][sum] = 1 + op;
}

void print(int posa,int posb,int sum)
{
    if(posa>=a.size() && posb>=b.size() && sum==0) return;
    if(sum>=900) return;
    //cout<<posa<<" "<<posb<<" "<<sum<<endl;
    //getchar();
    int op1 = 1000000000 , op2 = 1000000000;
    if(posa<a.size() || posb<b.size() )op1 = solve(posa+(posa<a.size() && a[posa]=='('), posb+(posb<b.size() && b[posb]=='('),sum+1);
    if(sum) op2 = solve(posa+(posa<a.size() && a[posa]==')'), posb+(posb<b.size() && b[posb]==')'),sum-1);
    if(op1<op2)
    {
        putchar('(');
        print(posa+(posa<a.size() && a[posa]=='('), posb+(posb<b.size() && b[posb]=='('),sum+1);
    }
    else
    {
        putchar(')');
        print(posa+(posa<a.size() && a[posa]==')'), posb+(posb<b.size() && b[posb]==')'),sum-1);
    }
}
int main()
{
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    int v = solve(0,0,0);
   // cout<<v<<endl;
    print(0,0,0);
    puts("");
}