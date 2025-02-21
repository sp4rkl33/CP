#include<bits/stdc++.h>

using namespace std;

void solve(){
	string s[3];
	for (int i=0; i<3; i++){
		cin>>s[i];
	}
	if ((s[0][0] == s[1][1] && s[1][1] == s[2][2] || s[0][2]==s[1][1] && s[1][1]==s[2][0]) && s[1][1]!='.'){
		cout<<s[1][1]<<endl;
		return;
	}
	for (int i=0; i<3; i++){
		if (s[0][i]==s[1][i] && s[1][i]==s[2][i] && s[0][i]!='.') {
			cout<<s[0][i]<<endl;
			return;
		} 
		if (s[i][0]==s[i][1] && s[i][1]==s[i][2] && s[i][1]!='.'){
			cout<<s[i][0]<<endl;
			return;
		}
	}
	cout<<"DRAW"<<endl;
}

int main(){
	int t; cin>>t;
	while (t--){
		solve();
	}
	
	return 0;
}
