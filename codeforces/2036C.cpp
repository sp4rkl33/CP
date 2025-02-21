#include<bits/stdc++.h>
#define ll long long
//#define FAST ios_base::sync_with_stdio(0); cin.tie(nullptr);

using namespace std;

int f[4]={1, 2, 4, 8};

int solve(string &s){
	int cnt=0;
	if (s.length()<4) return 0;
	int p=s.length()-1, cur=0;
	for (int i=0; i<4; i++){
		if (s[p]=='1') cur+=f[i];
		p--;
	}
	while (p>=0){
		cnt += cur==12;
		//cout<<"cur: "<<cur<<"\n";
		cur = cur>>1;
		//cout<<"cur>>1: "<<cur<<"\n";
		if (s[p]=='1') cur += 8;
		p--;
	}
	return cur == 12 ? cnt+1:cnt;
}

string tr(string &s, int k, int n){
	string tmp="";
	for(int i=max(0, k-3); i<=min(k+3, n-1); i++){
		tmp +=s[i];
	}
	return tmp;
}

int main(){
	//FAST
	int t; cin>>t;
	while(t--){
		string s; int q; cin>>s>>q;
		int count = solve(s);
		//cout<<"init: "<<count<<endl;
		while(q--){
			int i,v; cin>>i>>v;
			i--;
			string tmp = tr(s, i, s.length());
			//cout<<"bstring: "<<tmp<<"\n";
			int b = solve(tmp);
			s[i] = '0' + v;
			tmp = tr(s, i, s.length());
			//cout<<"astring: "<<tmp<<"\n";
			int a = solve(tmp);
			count += a - b;
			puts(count > 0 ? "YES":"NO");
		}
	}
	return 0;
}
