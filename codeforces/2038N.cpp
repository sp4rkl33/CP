#include<bits/stdc++.h>
#define ll long long
//#define FAST ios_base::sync_with_stdio(0); cin.tie(nullptr);

using namespace std;

int f(char &a){
	return a-48;
}

void solve(){
	char a,b,c; cin>>a>>b>>c;
	if (f(a) > f(c)) cout<<a<<'>'<<c<<'\n';
	else if (f(a) < f(c)) cout<<a<<'<'<<c<<'\n';
	else cout<<a<<'='<<c<<'\n';
}

int main(){
	//FAST
	int n; cin>>n;
	while(n--){
		solve();
	}	
	return 0;
}
