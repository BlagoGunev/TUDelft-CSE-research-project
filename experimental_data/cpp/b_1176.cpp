/*
                                    _________
                                   /         /.
            .-------------.       /_________/ |
           /             / |      |         | |
          /+============+\ |      | |====|  | |
          ||�ҥ륦������|| |      |         | |
          ||����һ�ɐ�  || |      | |====|  | |
          ||  ���Ǥ�    || |      |   ___   | |
          ||   !!!      || |      |  |233|  | |
          ||            ||/@@@    |   ---   | |
          \+============+/    @   |_________|./.
                             @          ..  ....'
          ..................@     __.'.'  ''
         /oooooooooooooooo//     ///
        /................//     /_/
        ------------------
*/
/******************(*'��'*)*************/
/********�ҥ륦������˽���ޤǤ�*********/
/**(>��<)��Ů�ϱ����ˤ��襤�����ޤ�!!!**/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<stack> 
#include<queue>
#include<map>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=1e6+5;
const ll mod=1e9+7;
int read()
{
	int res=0,ch,flag=0;
	if((ch=getchar())=='-') flag=1;
	else if(ch>='0'&&ch<='9') res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') res=res*10+ch-'0';
	return flag?-res:res;
}
int n,t;
ll data;
void solve(int i,ll data)
{

}
int main()
{
	t=read();
	while(t--)
	{
		n=read();
		int a=0,b=0,c=0,data;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			data=read();data%=3;
			if(data==0) a++;
			else if(data==1) b++;
			else if(data==2) c++; 
		}
		if(b>=c) {ans+=c;b-=c;ans+=b/3;}
		else {ans+=b;c-=b;ans+=c/3;}
		ans+=a;
		printf("%d\n",ans);
	}
	return 0;
}