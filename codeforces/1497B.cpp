#include <bits/stdc++.h>
#define ll long long
#define taskwithtestcase int t; cin>>t; while(t--){ cout<<solve()<<'\n';}
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

bool f(map<int, int> &mp, int n){
	map<int, int>::iterator it = mp.find(n);
	return it==mp.end();
}

int solve(){
	int n,m; cin>>n>>m;
	map<int, int> mp;
	int ans=0;
	bool h=0;
	for (int i=0; i<n; i++){
		int x; cin>>x;
		h=h||(x%m==0);
		if (x%m == 0) continue;
		if (!f(mp, x%m)) mp[x%m]++;
		mp.insert(make_pair(x%m, 1));
	}
	
	if (m%2==0 && !f(mp, m/2)){
		ans++;
		mp.erase(m/2);
	}
	
	for (pair<int, int> p:mp){
		int x=p.first, y=p.second;
		if (y==0) continue;
		if (!f(mp, m-x)){
			ans++;
			int tmp = abs(mp[m-x] - y);
			if (tmp>1) ans+=tmp-1;
			mp[m-x]=0;
		} else ans += y;
		mp[x]=0;
	}
	return h ? ans+1:ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    taskwithtestcase
}
