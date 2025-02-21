#include<bits/stdc++.h>

using namespace std;

vector<int> a;

int solve(){
	int n,k; cin>>n>>k;
	a.resize(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	int ans=1 ,tans=1;
	for (int i=1; i<n; i++){
		if (a[i]-a[i-1] > k){
			ans=max(ans,tans);
			tans=1;
		} else tans++;
	}
	ans = max(ans,tans);
	return n-ans;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}
