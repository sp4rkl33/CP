#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(){
	int n; cin>>n;
	ll s=0;
	for (int i=0; i<n; i++){
		int t; cin >>t;
		s+=t;
	}
	ll ans = sqrt(s);
	return ans*ans == s;
}

int main(){
	int t; cin>>t;
	while(t--){
		puts(solve() ? "YES":"NO");
	}
}
