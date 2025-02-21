#include<bits/stdc++.h>

using namespace std;

int solve(){
	int n,k,x; cin>>n>>k>>x;
	if (n<k || x<k-1) return -1;
	if (n==k) return ((n-1)*n)/2;
	x = x==k ? x-1:x;
	return (k*(k-1))/2 + (n-k)*x;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}
