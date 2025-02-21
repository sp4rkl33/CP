#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(nullptr);

using namespace std;

void solve(){
	int n; cin>>n;
	int t=n-2;
	vector<int> a(n+1);
	for (int i=0; i<n; i++){
		int x; cin>>x;
		a[x]++;
	}
	for (int i=1; i<=t/2; i++){
		if (a[i]>0 && t%i==0 && a[t/i]>0){
			cout<<i<<" "<<(int)t/i;
			return;
		}
	}
	cout<<"1 1";
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
		cout<<'\n';
	}	
	return 0;
}
