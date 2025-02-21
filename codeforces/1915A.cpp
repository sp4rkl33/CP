#include<bits/stdc++.h>

using namespace std;

int solve(){
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a, a+3);
	return a[0]==a[1] ? a[2]:a[0];
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
