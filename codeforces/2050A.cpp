#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	FAST
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		int ans=0;
		for (int i=0; i<n; i++){
			string s; cin>>s;
			ans+=m>=(int)s.length();
			m-=(int)s.length();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
