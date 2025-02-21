#include<bits/stdc++.h>
#define ll long long

using namespace std;

int solve(){
	int n,k=0;
	cin>>n;
	vector<int> a(n), p(101);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	for (int c=0; c<=n; c++){
		int ans=0;
		for (int i=0; i<n; i++){
			ans+=c<a[i];
		}
		if (ans==c) return ans;
	}
	return -1;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}
