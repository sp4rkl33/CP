#include <bits/stdc++.h>

using namespace std;

int solve(){
	string s;
	cin>>s;
	if (s.find('1') < s.find('7')) return 17;
	return 71;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}
