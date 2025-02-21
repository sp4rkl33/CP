#include <bits/stdc++.h>

using namespace std;

bool f(int a, int b, int c){
	return (b>a && b>c) || (b<a && b<c);
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	int ans=0;
	for (int i=1; i<n-1; i++){
		ans+=f(a[i-1], a[i], a[i+1]);
	}
	cout<<ans<<endl;
	return 0;
	
}
