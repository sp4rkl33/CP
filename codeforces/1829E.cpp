#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, -1, 1};

ll sum;

bool inn(int x, int y){
	return x>=0 && x<y;
}

void dfs(int x, int y, int n, int m, vector<vector<int> > &g, vector<vector<bool> > &v){
	v[x][y]=1;
	sum+=g[x][y];
	for(int i=0; i<4; i++){
		int xx=x+dx[i], yy=y+dy[i];
		if (inn(xx,n) && inn(yy,m) && g[xx][yy]>0 && !v[xx][yy]) dfs(xx,yy,n,m,g,v);
	}
}

ll solve(){
	int n,m; cin>>n>>m;
	vector<vector<int> > g(n);
	vector<vector<bool> > v(n);
	for(int i=0; i<n; i++){
		g[i].resize(m); v[i].resize(m);
		for(int j=0; j<m; j++){
			cin>>g[i][j];
		}
	}
	
	ll ans=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if (g[i][j]>0 && !v[i][j]){
				sum=0;
				dfs(i,j,n,m,g,v);
				ans=max(ans,sum);
			}
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

