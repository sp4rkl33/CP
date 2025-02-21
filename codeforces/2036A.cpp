#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(nullptr);

using namespace std;

bool f(int s){
	return s==5 || s==7;
}

bool solve(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for (int i=1; i<n; i++){
		if (!f(abs(a[i]-a[i-1]))) return 0;
	}
	return 1;
	
}

int main(){
	FAST
	int t; cin>>t;
	string ans[2]={"NO", "YES"};
	while(t--){
		cout<<ans[solve()]<<"\n";
	}	
	return 0;
}
