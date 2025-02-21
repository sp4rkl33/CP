#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string solve(){
	string s; cin>>s;
	int sum=0, cnt2=0, cnt3;
	for (int i=0; i<s.length(); i++){
		cnt2 = s[i]=='2' ? cnt2+1:cnt2;
		cnt3 = s[i]=='3' ? cnt3+1:cnt3;
		sum+=(int)(s[i]-48);
	}
	cnt2 = min(cnt2, 8);
	cnt3 = min(cnt3, 8);
	for (int i=0; i<=cnt2; i++){
		for (int j=0; j<=cnt3; j++){
			if ((sum + i*2 + j*6) % 9 == 0) return "YES\n";
		}
	}
	return "NO\n";
}

int main(){
	FAST
	int t; cin>>t;
	while(t--){
		cout<<solve();
	}
	return 0;
}
