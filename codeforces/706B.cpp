#include <bits/stdc++.h>

using namespace std;

int maxn=(int)1e6 + 5;
vector<int> dp(maxn), a;


int main(){
	int n,q;
	cin>>n;
	a.resize(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	int d=0;
	for (int i=0; i<maxn; i++){
		while (i>=a[d] && d<n) d++;
		dp[i]=d;
	}
	cin>>q;
	
	while (q--){
		int t; cin>>t;
		if (t>=maxn) cout<<n<<endl; else cout<<dp[t]<<endl;
	}
}
