#include<bits/stdc++.h>

using namespace std;

char solve(){
	string s,p;
	int a[3]={0,0,0};
	for (int i=0; i<9; i++){
		char c;
		cin>>c;
		if (c=='?') continue;
		a[c-65]++;
	}
	for (int i=0; i<3; i++){
		if (a[i]==2) return i+65;
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}

