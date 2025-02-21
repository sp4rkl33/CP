#include <bits/stdc++.h>

using namespace std;

int f(int n){
	return n<0 ? -n:n;
}

int solve(){
	int a,b;
	int res=0;
	float c;
	cin>>a>>b>>c;
	while (a!=b){
		float t=f(a-b);
		if (t/2<=c) return res+1;
		res++;
		if (a>b) b+=c, a-=c;
		else a+=c, b-=c;
	}
	return res;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
