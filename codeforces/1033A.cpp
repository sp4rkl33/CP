#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<vector<int> > g;

int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

//visited = 2, cantmove = -1, win = 1

bool inn(int x, int y){
	return x>0 && x<=y;
}

void queen(int x, int y, int n){
	for (int i=0; i<8; i++){
		int xx=x, yy=y;
		while (inn(xx, n) && inn(yy, n)){
			g[xx][yy]=-1;
			xx+=dx[i]; yy+=dy[i];
		}
	}
}

bool ans=0;

void dfs(int x, int y, int n){
	ans = ans || (g[x][y]==1);
	g[x][y]=2;
	for (int i=0; i<8; i++){
		int xx=x+dx[i], yy=y+dy[i];
		if (inn(xx, n) && inn(yy,n) && (g[xx][yy]==0 || g[xx][yy]==1)) dfs(xx,yy,n);
	}
}

string solve(){
	int n; cin>>n;
	g.resize(n+1);
	for(int i=1; i<=n; i++){
		g[i].resize(n+1);
	}
	int a,b;
	for(int i=-1; i<=1; i++){
		int x,y; cin>>x>>y;
		g[x][y]=i;
		if (i==-1) queen(x,y,n);
		else if(i==0){
			a=x, b=y;
		}
	}
	dfs(a,b,n);
	return ans ? "YES" : "NO";
}

int main(){
	FAST;
	cout<<solve()<<'\n';
	return 0;
}

