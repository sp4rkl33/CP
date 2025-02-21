#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int calc(string &x, string &y, int m){
	int dif=0;
	for (int i=0; i<m; i++){
		dif += abs(x[i]-y[i]);
	}
	return dif;
}

int solve(){
	int n,m; cin>>n>>m;
	vector<string> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int ans = 1e9+8;
	for(int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			ans=min(calc(a[i],a[j],m), ans);
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

