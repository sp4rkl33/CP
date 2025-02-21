#include<bits/stdc++.h>

using namespace std;

int solve(){
	int n; string s;
	cin>>n>>s;
	int cnt=0;
	vector<int> dp(n);
	dp[0]=1;
//	for (int i=0; i<n; i++){
//		cnt = a[s[i]-'a'] == 0 ? cnt+1:cnt;
//		a[s[i]-'a']++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
//	}
	for (int i=1; i<n; i++){
		dp[i] = s[i]!=s[i-1] ? dp[i-1]+i+1:dp[i-1]+1; 
	}
	int ans=(cnt*(cnt+1))/2;
	return dp[n-1];
}

int main(){
	int t; cin>>t;	
	while(t--){
		cout<<solve()<<endl;
	}
}
