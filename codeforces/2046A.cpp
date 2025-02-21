#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool op(int a, int b){
	return a>=b;
}

ll solve(){
	int n; cin>>n;
	vector<ll> a(2*n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	for (int i=n; i<2*n; i++){
		cin>>a[i];
	}
	sort(a.begin(), a.end());

	ll ans=0;
	for (int i=n; i>=0; i--){
		ans+=a[i];
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}
