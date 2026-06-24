#include<bits/stdc++.h>
using namespace std;
namespace whatever{
	int readu(){
		char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		int value=ch-'0';
		ch=getchar();
		while(isdigit(ch)){
			value=value*10+ch-'0';
			ch=getchar();
		}
		return value;
	}
	void writeu(int n){
		if(n<10)
			putchar(n+'0');
		else{
			writeu(n/10);
			putchar(n%10+'0');
		}
	}
	vector<int> manacher(const vector<int> &str){
		int len=int(str.size());
		vector<int> radius;
		int cur=0;
		int cur_radius=0;
		while(cur<len){
			while(cur-cur_radius-1>=0&&cur+cur_radius+1<len&&str.at(cur-cur_radius-1)==str.at(cur+cur_radius+1))
				++cur_radius;
			radius.push_back(cur_radius);
			int center=cur;
			while(true){
				++cur;
				int prev=center-(cur-center);
				if(prev<0||cur+radius.at(prev)>=center+cur_radius)
					break;
				radius.push_back(radius.at(prev));
			}
			cur_radius=center+cur_radius-cur;
		}
		assert(radius.size()==str.size());
		return radius;
	}
	void run(){
		int n=readu();
		int m=readu();
		vector<int> a;
		for(int i=0; i<n; ++i)
			a.push_back(readu());
		vector<int> str;
		str.push_back(0);
		for(int i=0; i<n; ++i){
			str.push_back((a.at((i+1)%n)-a.at(i%n)+m)%m);
			str.push_back(0);
		}
		for(int i=0; i<n; ++i){
			str.push_back((a.at((i+1)%n)-a.at(i%n)+m)%m);
			str.push_back(0);
		}
		vector<int> radius=manacher(str);
		vector<int> result;
		for(int i=0; i<n*4+1; ++i)
			if(i%2==0){
				if(radius.at(i)>=n/2*2-1)
					result.push_back(a.at(i/2%n)*2%m);
			}
			else{
				if(radius.at(i)>=(n+1)/2*2-2)
					result.push_back((a.at((i-1)/2%n)+a.at((i+1)/2%n))%m);
			}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		writeu(result.size());
		putchar('\n');
		for(auto cur: result){
			writeu(cur);
			putchar(' ');
		}
		putchar('\n');
	}
}
int main(){
	whatever::run();
}