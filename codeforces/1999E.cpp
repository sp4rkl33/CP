#include <bits/stdc++.h>
#define ll long long
#define retsolve int t; cin>>t; while(t--){cout<<solve()<<'\n';}
#define voidsolve int t; cin>>t; while(t--){solve();}
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

vector<ll> pre(200005), sum(200005);

void init(){
	for (int i=1; i<=2e5+3; i++){
		pre[i]=pre[i/3]+1;
		sum[i]=pre[i]+sum[i-1];
	}
}

ll solve(){
	int l,r; cin>>l>>r;
	return 2LL*pre[l] + sum[r]-sum[l+1-1];
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
	retsolve
}
