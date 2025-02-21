#include<bits/stdc++.h>

using namespace std;

vector<int> b,ans;

void solve(){
	int n; cin>>n;
	b.resize(n); ans.resize(2*n-1);
	for (int i=0; i<n; i++){
		cin>>b[i];
	}
	int k=0;
	ans[0]=b[0];
	for (int i=1; i<n; i++){
		if (b[i]>=ans[k]){
			k++;
			ans[k]=b[i];
		} else {
			k++;
			ans[k]=b[i];
			k++;
			ans[k]=b[i];
		}
	}
	cout<<k+1<<endl;
	for (int i=0; i<=k; i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
}
