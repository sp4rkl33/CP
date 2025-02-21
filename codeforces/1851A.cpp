#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> a;

bool check(double x){
	return (double)(int)x - x == 0;
}

int solve(){
	int n,m,k,h; cin>>n>>m>>k>>h;
	a.resize(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	int cnt=0;
	for (int i=0; i<n; i++){
		double x = (double)(a[i]-h)/k;
		if (check(x)) x=(double)(int)x;
		else continue;	
		cnt = (h-a[i] + k*x)==0 && (abs(x)<m && x!=0) ? ++cnt:cnt;
	}
	return cnt;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}

