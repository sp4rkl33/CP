#include <bits/stdc++.h>
using namespace std;


int solve(){
	int n;
	int m = 0;
	cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
		m=max(a[i],m);
	}
	for (int i=0; i<n; i++){
		if (a[i]==m){
			if (i==0 && a[i+1]!=m) return i+1;
			else if (i==n-1 && a[i-1]!=m) return i+1;
			else if ((i!=0 && i<n-1) && (a[i-1]!=m || a[i+1]!=m)) return i+1;
		}
	}
	return -1;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		cout << solve() << endl;	
	}
}
