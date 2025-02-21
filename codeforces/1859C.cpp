#include <bits/stdc++.h>

using namespace std;

int dp[250];

int solve(int n){
	int s, ans=0;
	s=((n-1)*(n)*(2*(n-1)+1))/6;
	for (int i=n-1; i>=1; i--){
		s-=i*i;
		int m=(i-1)*(i-1), k=n, t=s;
		for (int j=i; j<=n; j++){
			t+=k*j;
			m=max(m,k*j);
			k--;
		}
		t-=m;
		ans=max(t,ans);
	}
	return ans;
}

int main(){
	for (int i=2; i<=250; i++){
		dp[i]=solve(i);
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout << dp[n] << endl; 
	}
	return 0;
}
