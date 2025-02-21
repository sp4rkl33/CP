#include<bits/stdc++.h>

using namespace std;

int solve(){
	int n; string s; cin>>n>>s;
	vector<int> a(26);
	for (int i=0; i<n; i++){
		a[s[i]-'a']++;
	}
	sort(a.begin(), a.end());
	int p=n-a[25];
	int ans=max(0,a[25]-p);
	return ans==0 && n%2!=0 ? ans+1:ans;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}


