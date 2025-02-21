#include <bits/stdc++.h>

using namespace std;

int p[8]={2,3,4,7,8,15,16,20};

bool solve(){
	int n; cin>>n;
	vector<int> a(n);
	
	for (int i=0; i<n; i++){
		cin>>a[i];
	}	
	
	for (int i=0; i<=8; i+=2){
		for (int c=p[i]; c<p[i+1]; c++){
			if (c>=n-1) break;
			if (a[c]>a[c+1]) return 0;
		}
	}
	
	return 1;	
}

int main(){
	int t; cin>>t;
	while (t--){
		puts(solve() ? "YES":"NO");
	}
}
