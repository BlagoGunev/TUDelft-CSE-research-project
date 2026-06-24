#include<bits/stdc++.h>

using namespace std;

vector<int> strongly_connected_components(const vector<vector<int>> &ad){
	int n=ad.size(),time=0;
	vector<int> scc(n),ord(n,-1);
	vector<bool> inS(n);
	stack<int> st, dst, low;
	int ver=0;
	for(int i=0;i<n;i++){
		if(ord[i]!=-1) continue;
		dst.push(i);
		while(dst.size()){
			int cur=dst.top();
			if(ord[cur]==-1){
				st.push(cur);
				inS[cur]=true;
				ord[cur]=time++;
				low.push(ord[cur]);
			}else{
				dst.pop();
				if(low.top()==ord[cur]){
					while(true){
						int ch=st.top();
						st.pop();
						inS[ch]=false;
						scc[ch]=ver;
						if(ch==cur) break;
					}
					ver++;
					low.pop();
				}
				continue;
			}
			for(int ch:ad[cur]){
				if(ord[ch]==-1){
					dst.push(ch);
				}else if(inS[ch]){
					while(low.top()>ord[ch]){
						low.pop();
					}
				}
			}
		}
	}
	return scc;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	cin >> n >> m;
	vector<vector<int>> ad(n);
	vector<pair<int,int>> ed(m);
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		a--,b--;
		ed[i]=make_pair(a,b);
		ad[a].push_back(b);
	}
	vector<int> scc=strongly_connected_components(ad);
	int sx=0;
	for(int i=0;i<scc.size();i++) sx=max(sx,scc[i]);
	if(sx==(n-1)){
		cout << 1 << "\n";
		for(int i=0;i<m;i++){
			cout << 1 << " ";
		}
		cout << "\n";
		return 0;
	}
	cout << 2 << "\n";
	for(int i=0;i<m;i++){
		if(ed[i].first>ed[i].second) cout << 1 << " ";
		else cout << 2 << " ";
	}
	cout << "\n";
	return 0;
}