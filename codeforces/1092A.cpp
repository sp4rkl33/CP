#include<bits/stdc++.h>

using namespace std;

bool solve(){
	string s;
	int n;
	cin>>n>>s;
	for (int i=0; i<n; i++){
		if (s[i]=='0') return 1;
	}
	return 0;
}

int main(){
	int t; cin>>t;
	while (t--){
		puts(solve() ? "YES":"NO");
	}
	return 0;
}
