#include<bits/stdc++.h>

using namespace std;

vector<int> a;

void solve(){
	int x,y,n; cin>>x>>y>>n;
	a.resize(n);
	a[0]=x;
	a[n-1]=y;
	int k=1;
	for (int i=n-2; i>0; i--){
		y-=k;
		if (y<=x) {
			cout<<-1<<endl;
			return;
		}
		a[i]=y;
		k++;
	}
	if (a[1]-a[0] <= a[2]-a[1]) {
		cout<<-1<<endl;
		return;
	}
	for (int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();	
	}
}
