#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> a;

void solve(){
	int n,l,r; cin>>n>>l>>r;
	a.resize(n);
	for (int i=1; i<=n; i++){
		ll t = ((l-1)/i + 1)*i;
		if (t>r){
			cout<<"NO\n";
			return;
		}
		a[i-1]=t;
	}
	cout<<"YES\n";
	for (int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
