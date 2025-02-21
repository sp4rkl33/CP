#include <bits/stdc++.h>

typedef unsigned long long ull;
using namespace std;

vector<ull> a(30);

int f(int n){
	int k=0;
	while (n>0){
		n>>=1;
		k++;
	}
	return k;
}

void solve(){
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		int t;
		cin>>t;
		a[f(t)-1]++;
	}
	ull res=0;
	for (int i=0; i<30; i++){
		res+=(a[i]*(a[i]-1))/2;
		a[i]=0;
	}
	cout << res << endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
