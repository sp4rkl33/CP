#include<bits/stdc++.h>
#define ll long long

using namespace std;

int solve(){
	int n; cin>>n;
	vector<ll> a(n), f(n+1);
	for(int i=1; i<=n; i++){
		cin>>a[i-1];
		f[i]=f[i-1]+a[i-1];
	}
	int l=0, ans=0;
	while (l<=n){
		if (l-1>0 && a[l-1]==0){
			l++;
			ans++;
			continue;
		}
		for (int r=l+1; r<=n; r++){
			if (f[r]==f[l] || f[r]==0){
				l=r;
				ans++;
				break;
			}
		}
		l++;
	}
	return ans;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}	
	return 0;
}
