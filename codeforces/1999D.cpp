#include<bits/stdc++.h>
 
using namespace std;
 
void solve(){
	string s,t; cin>>s>>t;
	int c=0;
	for (int i=0; i<s.length(); i++){
		if (s[i]=='?'){
			s[i] = c<t.length() ? t[c]:'a';
			c++;
		} else if (s[i]==t[c]) {
			c++; continue;
		}
	}
	if (c>=t.length()) cout<<"YES"<<endl<<s<<endl;
	else cout<<"NO"<<endl;
}
 
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
