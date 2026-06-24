/*
problem's name:
statue:
writer:Patrick_y
*/
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#include <cctype>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define mp make_pair
typedef long long ll;
using namespace std;
const int INF=20050226;
/*------------main part------------*/
struct Sentence
{
	string input;
	int at;
	char nex()
	{
		return input[at];
	}
	void reset(const string&s)
	{
		input=s+"@";
		at=0;
		token="";
	}
	char space()
	{
		while(nex()==' ')
			fi();
		return nex();
	}
	void fi()
	{
		++at;
	}
	string token;
	string nextt()
	{
		if(!token.empty())
			return token;
		char ch=space();
		if(isdigit(ch))
		{
			while(isdigit(nex()))
			{
				token+=nex();
				fi();
			}
		}
		else if(isalpha(ch))
		{
			while(isalpha(nex()))
			{
				token+=nex();
				fi();
			}
		}
		else
		{
			token=nex();
			fi();
		}
		return token;
	}
	void skt()
	{
		token="";
	}
	bool hasMoreTokens()
	{
		return at<input.size();
	}
};
Sentence sent;
vector<string> tokens;
string input;
int what;
int n;
void CIN()
{
	cin>>what;
	string line;
	input="";
	while(getline(cin,line))
		input+=line;
}
void tokenizeInput()
{
	sent.reset(input);
	while(sent.hasMoreTokens())
	{
		tokens.push_back(sent.nextt());
		sent.skt();
	}
}
int	result[32768];
int at;
string nextt()
{
	return tokens[at];
}
void skt()
{
	++at;
}
int fun(int);
int opsent();
int op();
int logic();
int expres();
int sum();
int prod();
int mulp();
void eat(string s)
{
	skt();
}
int fun()
{
	eat("int");eat("f");eat("(");eat("int");eat("n");eat(")");
	eat("{");
	int e=opsent();
	return e;
}
int opsent()
{
	while(nextt()!="}")
	{
		int e=op();
		if(e!=-1)
			return e;
	}
	return -1;
}
int op()
{
	if(nextt()=="return")
	{
		skt();
		return expres();
	}
	else
	{
		eat("if");
		eat("(");
		int ok=logic();
		eat(")");
		eat("return");
		int res=expres();
		eat(";");
		if(ok)
			return res;
		else
			return -1;
	}
}
int logic()
{
	int a=expres();
	string token=nextt();
	if(token==">")
	{
		eat(">");
		int b=expres();
		return a>b;
	}
	else if(token=="<")
	{
		eat("<");
		int b=expres();
		return a<b;
	}
	else
	{
		eat("=");eat("=");
		int b=expres();
		return a==b;
	}
}
inline int add(int a,int b)
{
	return (a+b)%32768;
}
inline int mine(int a,int b)
{
	a-=b;if(a<0)a+=32768;
	return a;
}
inline int mul(int a,int b)
{
	return (a*b)%32768;
}
inline int dive(int a,int b)
{
	if(!b)return -1;
	return a/b;
}
int expres()
{
	return sum();
}
int sum()
{
	int e=prod();
	while(nextt()=="+" or nextt()=="-")
	{
		string token=nextt();
		skt();
		if(token=="+")
			e=add(e,prod());
		else
			e=mine(e,prod());
	}
	return e;
}
int prod()
{
	int e=mulp();
	while(nextt()=="*" or nextt()=="/")
	{
		string token=nextt();
		skt();
		if(token=="*")
			e=mul(e,mulp());
		else
			e=dive(e,mulp());
	}
	return e;
}
int mulp()
{
	if(nextt()=="n")
	{
		skt();
		return n;
	}
	else if(nextt()=="f")
	{
		eat("f");eat("(");
		int arg=expres();
		eat(")");
		return result[arg];
	}
	else
	{
		istringstream iss(nextt());
		skt();
		int num;iss>>num;
		return num;
	}
}
int main()
{
	CIN();
	tokenizeInput();
	int ans=-1;
	for(int i=0;i<32768;i++)
	{
		at=0;n=i;
		result[i]=fun();
		if(result[i]==what)
			ans=i;
	}
	cout<<ans;
	return 0;
}