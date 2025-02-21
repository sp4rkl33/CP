#include<bits/stdc++.h>

using namespace std;

string solve(){
	int n; cin>>n;
	if (n==1 || n==3) return "-1";
	if (n==2) return "66";
	if (n==5) return "36366";
	if (n%2==0){
		string ans = "66";
		for(int i=0; i<n-2; i++){
			ans = '3' + ans;
		}
		return ans;
	} else {
		string ans = "36366";
		for (int i=0; i<n-5; i++){
			ans = '3' + ans;
		}
		return ans;
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
