#include<bits/stdc++.h>

using namespace std;

int solve(){
	int n; string s;
	cin>>n>>s;
	int t=0, p=0, k=0, ans=0;
	bool f=0;
	for (int i=0; i<n; i++){
		if (s[i]=='.'){
			p++;
		} else {
			f = f || (p>=3);			
			if (!f) ans+=p;
			p=0;
		}
	}
	return f || p>=3 ? 2:ans+p;
}

int main(){
	int t;cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
