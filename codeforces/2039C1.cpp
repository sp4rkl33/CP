#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int solve(){
	ll x; ll m; cin>>x>>m;
	int ans=0;
	for (int y=1; y<=min(2LL*x,m); y++){
		ll c = x^y;
		if (c==0) continue;
		ans += x%c==0 + y%c==0;
	}
	return ans;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<'\n';
	}
	return 0;
}
