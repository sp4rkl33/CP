#include<bits/stdc++.h>

using namespace std;

vector<string> s;

bool cnt(vector<string> &s, int i, int j){
	int ans[2]={0,0};
	ans[s[i][j]-48]++; ans[s[i][j+1]-48]++; ans[s[i+1][j]-48]++; ans[s[i+1][j+1]-48]++;
	return ans[1]==3;
}

bool solve(){
	int n,m; cin>>n>>m;
	s.resize(n);
	for (int i=0; i<n; i++){
		cin>>s[i];
	}
	for (int i=0; i<n-1; i++){
		for (int j=0; j<m-1; j++){
			if (cnt(s,i,j)) return 1==0;
		}
	}
	return 1==1;
}

int main(){
	int t; cin>>t;
	while(t--){
		puts(solve() ? "YES":"NO");
	}
	return 0;
}
