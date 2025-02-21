#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool op(int x, int y){
	return x>y;
}

void solve(){
	int n,q; cin>>n>>q;
	vector<ll> a(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end(),op); 
	for (int i=1; i<n; i++) a[i]+=a[i-1]; 
	for (int i=0; i<q; i++){
		ll x; cin>>x;
		int lo=0, hi=n-1;
		int ans=-1;
		while (lo<=hi){
			int mid = (lo+hi)/2;
			if (a[mid]>=x){
				ans = mid+1;
				hi=mid-1;
			} else lo=mid+1;
		}
		cout<<ans<<'\n';
	}
}

int main(){
	FAST;
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

