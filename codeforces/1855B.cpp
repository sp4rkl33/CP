#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
	int t; cin>>t;
	while (t--){
		ull a;
		cin>>a;
		int ans=1;
		while (a%(ans+1)==0) ans++;
		cout << ans << endl;
	}
	return 0;
}
