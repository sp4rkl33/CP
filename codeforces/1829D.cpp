#include<bits/stdc++.h>

using namespace std;

bool r(int n, int m){
	if (n==m){
		return 1;
	} else if (n%3!=0) return 0; 
	else {
		int t=n/3;
		bool l=r(t,m), p=r(t*2,m);
		return l||p;
	}
}

void solve(){
	int n,m; cin>>n>>m;
	puts(r(n,m)? "YES":"NO");
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
}
