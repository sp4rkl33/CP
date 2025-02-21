#include <bits/stdc++.h>

using namespace std;

int solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int res=s.length()-1;
	for (int i=0; i<s.length()-2; i++){
		if (s[i]==s[i+2]) res--;
 	}
 	return res;
}

int main(){
	int t,r,n;
	string s;
	cin>>t;
	while (t--){
		cout << solve() << endl;
	}
}
