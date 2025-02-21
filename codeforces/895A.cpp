#include <bits/stdc++.h>

using namespace std;

int f(int n){
	return n<0?-n:n;
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	int ans=360;
	int v=0, p=360;
	for (int i=0; i<n; i++){
		int p=0;
		for (int j=i; j<n; j++){
			p+=a[j];
			ans=min(ans, f(2*p-360));
		}
	}
	cout << ans << endl;
	return 0;
	
}
