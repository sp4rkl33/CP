#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll solve(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if (a[i]>=a[j]) ans++;
		}
	}
	return ans;
}

int main(){
	FAST;
	int t; cin>>t;
	while(t--){
		cout<<solve()<<'\n';
	}
	return 0;
}

