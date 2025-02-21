#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct node{
	int b; int w;
};

void dfs(int u, vector<node> &p, vector<vector<int> > &g, vector<node> &ans){
	ans[u].b += p[u].b==1;
	ans[u].w += p[u].w==1;
 	for (int i=0; i<g[u].size(); i++){
		dfs(g[u][i], p, g,ans);
		ans[u].b += ans[g[u][i]].b;
		ans[u].w += ans[g[u][i]].w;
	}
}

int solve(){
	int n; cin>>n;
	vector<vector<int> > g(n);
	for(int i=1; i<n; i++){
		int x; cin>>x; x--;
		g[x].push_back(i);
	}
	string s; cin>>s;
	vector<node> p(n), ans(n);
	for (int i=0; i<n; i++){
		p[i].b = s[i]=='B';
		p[i].w = s[i]=='W';
	}
	dfs(0,p,g,ans);
	int res=0;
	for (int i=0; i<n; i++){
		res += ans[i].b==ans[i].w;
	}
	return res;
}

int main(){
	FAST;
	int t; cin>>t;
	while(t--){
		cout<<solve()<<'\n';
	}
	return 0;
}

