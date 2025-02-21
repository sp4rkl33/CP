#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> a;

ll solve(){
	int n; cin>>n;
	a.resize(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	ll ans=a[0]-1;
	for (int i=1; i<n; i++){
		ans+=max(0,a[i]-a[i-1]);
	}
	return ans;
}
int main(){
	int t; cin>>t;
	while (t--){
		cout<<solve()<<endl;
	}
	
}
