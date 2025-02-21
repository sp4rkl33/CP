#include <bits/stdc++.h>

using namespace std;

int solve(){
	int n;
	string s;
	cin>>n>>s;
	int res=0, ans=n+1;
	for (char x='a'; x<='z'; x++){
		int l=0, r=n-1;
		res=0;
		while (l<r){
			if (s[l]==s[r]){
				l++, r--;
			} else if (s[l]==x){
				res++, l++;
			} else if (s[r]==x){
				res++, r--;
			} else {
				res=n+1;
				break;
			}
		}
		ans=min(ans,res);
	}
	return ans==n+1 ? -1:ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
