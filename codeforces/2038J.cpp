#include<bits/stdc++.h>
#define ll long long
//#define FAST ios_base::sync_with_stdio(0); cin.tie(nullptr);

using namespace std;

ll cur = 0;

void solve(){
	char p; int i; cin>>p>>i;
	if (p=='P') cur+=i;
	else{
		if (i>cur) cout<<"YES\n";
		else cout<<"NO\n";
		cur = max(0LL, cur-i);
	}
}

int main(){
	//FAST
	int n; cin>>n;
	while(n--){
		solve();
	}
	return 0;
}
