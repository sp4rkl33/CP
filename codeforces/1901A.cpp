#include<bits/stdc++.h>
#define ll long long

using namespace std;

int solve(){
	int n,x; cin>>n>>x;
	vector<int> a(n+1);	
	a[0]=0;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	int ans=0;
	for (int i=1; i<=n; i++){
		ans=max(ans, a[i]-a[i-1]);
	}
	return max(ans, (x-a[n])*2);
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
