#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

bool inn(int x,  int y){
	return x>=0 && x<y;
}

void dfs(int x, int y, vector<string> &g, vector<vector<bool> > &v, int n, int p){
	v[x][y]=1;
	if (p==0){
		for(int i=0; i<4; i++){
			int xx=x+dx[i], yy=y+dy[i];
			if (inn(xx, 2) && inn(yy,n) && !v[xx][yy]) dfs(xx,yy,g,v,n,1-p);
		}
	} else {
		if (g[x][y]=='>' && !v[x][y+1]) dfs(x,y+1,g,v,n,1-p);
		else if (g[x][y]=='<' && !v[x][y-1]) dfs(x,y-1,g,v,n,1-p);
	}	
}

string solve(){
	int n; cin>>n;
	vector<string> g(2); vector<vector<bool> > v(2);
	for(int i=0; i<2; i++){
		cin>>g[i]; 
		v[i].resize(n);
	}
	dfs(0,0,g,v,n,0);
	return v[1][n-1]? "YES\n":"NO\n";
}

int main(){
	FAST;
	int t; cin>>t;
	while(t--){
		cout<<solve();
	}
	return 0;
}

