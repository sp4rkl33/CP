#include <bits/stdc++.h>
#define ul usigned int
#define ll long long
#define ull usigned long long

using namespace std;

int cnt(int n){
	int t=0;
	while (n%2==0) {
		t++;
		n=n>>1;	
	}
	return t;
}

int solve(){
	int n; cin>>n;
	int p=30, cnt0=0;
	for (int i=0; i<n; i++){
		int t; cin >> t;
		int c=cnt(t);
		p=min(c,p);
		cnt0 = c==0 ? cnt0+1:cnt0;
	}
	
	return p==0 ? abs(n-cnt0):p+n-1;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout << solve()<<endl;
	}
	return 0;
}
