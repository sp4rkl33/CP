#include<bits/stdc++.h>

using namespace std;

vector<int> a;

int solve(){
	int n; cin>>n;
	a.resize(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	
	sort(a.begin(), a.end());
	int i=a[0];
	int j=a[1];
	int k=a[n-1];
	int l=a[n-2];
	return abs(i-l) + abs(i-k) + abs(j-k) + abs(j-l);
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
