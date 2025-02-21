#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int solve(){
	int n; cin>>n;
	vector<int> a(21);
	for (int i=0; i<n; i++){
		int x; cin>>x;
		a[x]++;
	}
	int ans=0;
	for (int i=0; i<21; i++){
		if (a[i]>1)	ans+=t/2;
	}
	return ans;
}

int main(){
	FAST
	int t; cin>>t;
	while(t--){
		cout<<solve()<<'\n';
	}
	return 0;
}
