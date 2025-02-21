#include<bits/stdc++.h>

using namespace std;

vector< vector<int> > m;
vector<int> a;

void solve(){
	int n; cin>>n;
	m.resize(n);
	for (int i=0; i<n; i++){
		m[i].resize(n);
		for(int j=0; j<n; j++){
			cin>>m[i][j];
		}
	}
	a.resize(n);
	for (int i=0; i<n; i++){
		a[i]=(1<<30) - 1;
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (i==j) continue;
			a[i]&=m[i][j];
			a[j]&=m[i][j];
		}
	}
	bool f=1;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (i==j) continue;
			if (m[i][j] != (a[i]|a[j])){
				f=0;
				break;
			}
		}
	}
	if (f){
		cout<<"YES"<<endl;
		for(int i=0; i<n; i++){
			cout<<a[i]<<" ";
		}
	} else cout<<"NO";
	
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
}
