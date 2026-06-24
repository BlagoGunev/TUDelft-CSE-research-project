#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector <long> steck;	
vector <long> drug;
string s;
long long mod=1000000007;

vector <long long> rec(long beg,long fin)
{
	vector <long long> ress(10,0);
	if(fin-beg==1)
	{
		ress[3]=1;
		ress[6]=1;
		ress[7]=1;
		ress[8]=1;
		return ress;
	}

	if(drug[beg]==fin)
	{
		vector <long long> temp=rec(beg+1,fin-1);
		ress[3]=(temp[4]+temp[5]+temp[6]+temp[7]+temp[8]+temp[9])%mod;
		ress[6]=(temp[1]+temp[2]+temp[3]+temp[7]+temp[8]+temp[9])%mod;
		ress[7]=(temp[2]+temp[5]+temp[8]+temp[3]+temp[6]+temp[9])%mod;
		ress[8]=(temp[1]+temp[4]+temp[7]+temp[3]+temp[6]+temp[9])%mod;
		return ress;
	}
	else
	{
		vector <long long> temp1;
		vector <long long> temp2;
		temp1=rec(beg,drug[beg]);
		temp2=rec(drug[beg]+1,fin);
		ress[1]=(temp1[3]*((temp2[1]+temp2[4]+temp2[7])%mod))%mod;
		ress[2]=(temp1[3]*((temp2[2]+temp2[5]+temp2[8])%mod))%mod; 		
		ress[3]=(temp1[3]*((temp2[3]+temp2[6]+temp2[9])%mod))%mod; 

		ress[4]=(temp1[6]*((temp2[1]+temp2[4]+temp2[7])%mod))%mod;
		ress[5]=(temp1[6]*((temp2[2]+temp2[5]+temp2[8])%mod))%mod; 		
		ress[6]=(temp1[6]*((temp2[3]+temp2[6]+temp2[9])%mod))%mod;	
	
		ress[8]=(temp1[7]*((temp2[8]+temp2[5])%mod))%mod+(temp1[8]*((temp2[8]+temp2[2])%mod))%mod;
		ress[7]=(temp1[7]*((temp2[8]+temp2[2])%mod))%mod+(temp1[8]*((temp2[8]+temp2[5])%mod))%mod; 		
		ress[9]=(temp1[7]*((temp2[6]+temp2[9])%mod))%mod+(temp1[8]*((temp2[3]+temp2[9])%mod))%mod;	
		return ress;
	}
}

int main()
{
	//ifstream cin("input.txt");
	//ofstream out("output.txt");
	cin>>s;

	drug.assign(s.size(),0);
	steck.reserve(s.size());
	for(long i=0;i<s.size();i++)
	{
		if(s[i]=='(')
			steck.push_back(i);
		else
		{
			drug[i]=steck.back();
			drug[steck.back()]=i;
			steck.pop_back();
		}
	}

	vector <long long> res=rec(0,s.size()-1);
	long long ress=0;
	for(long i=0;i<10;i++)
	{
		ress+=res[i];
		ress%=mod;
	}
	cout<<ress;
}