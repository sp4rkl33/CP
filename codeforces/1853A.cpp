#include <bits/stdc++.h>

using namespace std;

int a[505], p[505];

int solve(){
	int n;
	int ans=1e9 + 5; 
	cin>>n;
	cin>>a[0];
	p[0]=0;
	for (int i=1; i<n; i++){
		cin>>a[i];
		p[i]=a[i]-a[i-1];
		if (p[i]<0) ans=0;
		ans=min(ans, abs(p[i]/2 + 1));
	}
	return ans;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout << solve() << endl;
	}
	return 0;
}
