#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

map< string, int > mp;
int ptr = 0;

int getId( string s ){
	if( mp.count( s ) == 0 )
		mp[s] = ptr++;
	return mp[s];
}

int n, m;
int arr[20000];
int  cnt[200000];

int main(){
	cin >> n >> m;
	for( int i = 0;i < n; i++ )
		cin >> arr[i];
	for( int i = 0;i < m; i++ ){
		string s;
		cin >> s;
		//cout << getId( s ) << endl;
		cnt[getId( s )]++;
	}
	sort( arr, arr + n );
	sort( cnt, cnt + m );
	int p1 = 0, p2 = 0;
	int po1 = 0, po2 = n - 1;
	for( int i = m - 1; i >= 0; i-- ){
		//cout << cnt[i] << ' ' << arr[i - m + 1] << endl;
		p1 += cnt[i] * arr[po1++];
		p2 += cnt[i] * arr[po2--];
	}
	cout << p1 << ' ' << p2 << endl;
}