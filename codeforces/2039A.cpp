#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	FAST;
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		for (int i=1; i<=n; i++){
			cout<<(2*i-1)<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
