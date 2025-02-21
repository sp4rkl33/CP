#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string solve(){
	int n; cin>>n;
	vector<ll> a(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	ll sod=0, sev=0;
	for(int i=0; i<n; i++){
		if (i%2) sod+=a[i];
		else sev += a[i];
	}
	
	ll od = n/2, ev = n/2 + n%2;
	bool no = sod % od || sev % ev || (sod/od != sev/ev);
	return no ? "NO\n":"YES\n";
}

int main(){
	FAST
	int t; cin>>t;
	while(t--){
		cout<<solve();
	}
	return 0;
}
