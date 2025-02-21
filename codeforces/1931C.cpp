#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int max(int a,int b){
	return a>b?a:b;
}

int solve(){
	int n;
	cin>>n;
	a.resize(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	int k1=0,k2=0;
	for (int i=0; i<n; i++){
		if (a[i]==a[0]) k1++;
		else break;
	}
	if (k1==n) return 0;
	for (int i=n-1; i>=0; i--){
		if (a[i]==a[n-1]) k2++;
		else break;
	}
	if (a[0]==a[n-1]) return n-(k1+k2);
	else return n-max(k1,k2);
}
int main(){
	int t;
	cin >> t;
	while (t--){
		cout << solve() << endl;
	}
}
