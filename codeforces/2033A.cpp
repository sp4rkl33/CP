#include<bits/stdc++.h>

using namespace std;

int solve(int n){
	int x=0;
	int i=1;
	while (x>=-n && x<=n){
		x = i%2!=0 ? x-(2*i-1):x+(2*i-1); 
		i++;
	}
	return (i)%2;
}

int main(){
	int f[101];
	for (int i=1; i<101; i++){
		f[i] = solve(i);
	}
	int t; cin>>t;
	string ans[2] = {"Sakurako", "Kosuke"};
	while(t--){
		int n; cin>>n;
		cout<<ans[f[n]]<<endl;
	}
}
