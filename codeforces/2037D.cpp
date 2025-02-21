#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct hur{
	int l; int r;
	int f(){
		return r-l+1;
	}
};

struct po{
	int x; int v;
};

int solve(){
	int n,m,L; cin>>n>>m>>L;
	vector<hur> h(n); 
	vector<po> p(m);
	priority_queue<int> pq;
	for (int i=0; i<n; i++) cin>>h[i].l>>h[i].r;
	for (int i=0; i<m; i++) cin>>p[i].x>>p[i].v;
	int j=0, ans=0;
	ll jum=0;
	for (int i=0; i<n; i++){
		while (p[j].x<=h[i].l && j<m){
			pq.push(p[j].v);
			j++;
		}
		int d=h[i].f();
		while (jum<d && !pq.empty()){
			jum+=pq.top();
			pq.pop();
			ans++;
		}
		if (jum<d) return -1;
	}
	return ans;
}

int main(){
	FAST
	int t; cin>>t;
	while(t--){
		cout<<solve()<<'\n';
	}
	return 0;
}
