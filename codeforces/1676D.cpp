#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dx[4]={-1, -1, 1, 1};
int dy[4]={-1, 1, 1, -1};

bool inn(int x, int y){
	return x>=0 && x<y;
}

ll f(int x, int y, int n, int m, vector<vector<ll> >&a){
	ll sum=a[x][y];
	for (int i=0; i<4; i++){
		int xx=x, yy=y;
		while(inn(xx+dx[i],n) && inn(yy+dy[i],m)){
			xx+=dx[i]; yy+=dy[i];
			sum+=a[xx][yy];
		}
	}
	return sum;
}

ll solve(){
	int n,m; cin>>n>>m;
	vector<vector<ll> > a(n);
	for(int i=0; i<n; i++){
		a[i].resize(m);
		for (int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	ll ans=0;
	for(int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			ans = max(ans, (ll)f(i,j,n,m,a));
		}
	}
	return ans;
}

int main(){
	FAST;
	int t; cin>>t;
	while(t--){
		cout<<solve()<<'\n';
	}
	return 0;
}

