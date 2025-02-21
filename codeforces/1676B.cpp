#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll solve(){
	int n; cin>>n;
	vector<ll> a(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	ll sum=0;
	sort(a.begin(), a.end());
	for (int i=1; i<n; i++){
		sum += a[i]-a[0];
	}
	return sum;
}

int main(){
	FAST;
	int t; cin>>t;
	while(t--){
		cout<<solve()<<'\n';
	}
	return 0;
}

