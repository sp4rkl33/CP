#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	FAST;
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		int sum=0;
		for(int i=0; i<3; i++){
			sum+=s[i]-48;
		}
		for(int i=3; i<6; i++){
			sum-=s[i]-48;
		}
		cout<<(sum==0 ? "yes":"no")<<'\n';
	}
	return 0;
}

