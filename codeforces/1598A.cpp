#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dx[5] = {0, 1, 1, -1, -1};
int dy[5] = {1, 1, 0, 1, 0};

int inn(int x, int y){
	return x>=0 && x<y;
}

void dfs(vector<string> &g, vector<vector<bool> > &v, int x, int y, int n){
	v[x][y]=1;
	for (int i=0; i<5; i++){
		int xx = x+dx[i], yy = y+dy[i];
		if (inn(xx, 2) && inn(yy, n) && g[xx][yy]=='0' && !v[xx][yy]) dfs(g,v,xx,yy,n);
	}
}

string solve(){
	bool ans=0;
	int n; cin>>n;
	vector<string> g(2);
	vector<vector<bool> > v(2);
	v[0].resize(n);
	v[1].resize(n);
	cin>>g[0]>>g[1];
	dfs(g,v,0,0,n);
	return v[1][n-1] ? "YES":"NO";
}

int main(){
	FAST;
	int t; cin>>t;
	while(t--){
		cout<<solve()<<'\n';
	}
	return 0;
}
