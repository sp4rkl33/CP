#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int solve(){
	int m,k,z,t;
	cin>>m>>k>>t>>z;
	int x=(int)m/k, y=m-(x*k), ny=(int)y/k;
	y-=min(ny,z)*k;
	z-=ny;
	int a=min(y,t);
	t-=a;
	y-=a;
	if (z>0){
		a=min(x,z);
		x-=a;
		z-=a;
	}
	if (t>0){
		a=min(int(t/k),x);
		t-=a*k;
		x-=a;
	}
	
	return (x+y);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cout << solve() << endl;
	}
	return 0;
}
