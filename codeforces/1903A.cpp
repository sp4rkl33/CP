#include<bits/stdc++.h>

using namespace std;

vector<int> a;
bool solve(){
	int n,k; cin>>n>>k;
	a.resize(n);
	bool ans=1;
	for (int i=0; i<n; i++){
		cin>>a[i];
		ans = (i==0 || (a[i]>=a[i-1])) && ans? 1:0;
	}
	return ans || k>1;
}

int main(){
	int t; cin>>t;
	while(t--){
		puts(solve() ? "YES":"NO");
	}
}
