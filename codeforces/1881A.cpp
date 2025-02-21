#include <bits/stdc++.h>

using namespace std;

bool f(string a, string b){
	int c=0;
	for (int i=0; i<a.length(); i++){
		if (a[i]==b[c]) c++;
		else{
			c=0;
			if (a[i]==b[c]) c++;
		};
		if (c==b.length()) return 1;
	}
	return c==b.length() ? 1:0;
}

int solve(){
	int n,m;
	cin>>n>>m;
	string x,a;
	cin>>x>>a;
	int op=5;
	while (op!=-1){
		if (x.find(a) != string::npos) return 5-op;
		x+=x;
		op--;
	}
	return -1;
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}
