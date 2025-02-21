#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct p{
	int x; int v;
};

bool op(p x, p y){
	return x.x<y.x;
}

void f(int &al, int &ar, int l, int r){
	al = l;
	ar = r;
}

void solve(){
	int n,k; cin>>n>>k;
	vector<int> a(n);
	map<int, int> m;
	for(int i=0; i<n; i++){
		int x; cin>>x;
		if (m.find(x) == m.end()) m.insert(make_pair(x,1));
		else m[x]++;
	}
	vector<p> g;
	for (map<int, int>::iterator it=m.begin(); it!=m.end(); it++){
		p e; e.x=(*it).first; e.v=(*it).second;
		g.push_back(e);
	}
	sort(g.begin(), g.end(), op);
	n=g.size();
	int ansL=-1, ansR=-1, l=0;
	while(l<n){
		int r=l+1;
		if (g[l].v>=k){
			if (ansL==-1) f(ansL,ansR,g[l].x,g[l].x);
			for (; r<n; r++){
				if (g[r].x-g[r-1].x>1 || g[r].v<k) break;
				if (g[r].x-g[l].x>ansR-ansL) f(ansL,ansR,g[l].x,g[r].x);
			}
		}
		l=r;
	}
	if (ansL==-1) cout<<-1<<'\n';
	else cout<<ansL<<" "<<ansR<<'\n';
}

int main(){
	FAST;
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

