#include<bits/stdc++.h>

using namespace std;

vector<int> a,b,c,ans;

int solve(){
	int n; cin>>n;
	a.resize(n); b.resize(n); c.resize(n); ans.resize(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	for (int i=0; i<n; i++){
		cin>>b[i];
	}
	for (int i=0; i<n; i++){
		cin>>c[i];
	}
	for (int i=0; i<n; i++){
		ans[i]=max(max(a[i],b[i]), max(b[i],c[i]));
	}
	sort(ans.begin(), ans.end());
	return ans[n-1]+ans[n-2]+ans[n-3];
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
