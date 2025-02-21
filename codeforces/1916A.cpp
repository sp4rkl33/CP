#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> a;

void solve(){
	bool cnt=1;
	int n,k; cin>>n>>k;
	ll s=1;
	a.resize(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
		if (2023%a[i]!=0) cnt=0;
		s*=a[i];
	}
	if (!cnt || 2023%s!=0){
		cout<<"NO\n"; return;
	}
	cout<<"YES\n";
	for (;k>0; k--){
		if (k==1) cout<<(int)2023/s<<endl;
		else cout<<1<<" ";
	}
}

int main(){
	int t; cin>>t;
	while (t--){
		solve();
	}
	return 0;
}
