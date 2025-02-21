#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n; cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	vector<int> ans;
	sort(a.begin(), a.end());
	int f=0;
	for (int i=0; i<n; i++){
		if (f==4) break;
		if (a[i]==a[i+1]){
			f++; i++;
			ans.push_back(a[i-1]);
			ans.push_back(a[i]);
		}
	}
	if (f<4){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	cout<<ans[0]<<" "<<ans[2]<<" "<<ans[1]<<" "<<ans[4]<<" "<<ans[6]<<" "<<ans[3]<<" "<<ans[7]<<" "<<ans[5]<<"\n";
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
