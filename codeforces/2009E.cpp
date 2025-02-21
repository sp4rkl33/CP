#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define taskwithtestcase int t; cin>>t; while(t--){cout<<solve()<<'\n';}
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

ll solve(){
	ll n,s,k,sK; cin>>n>>k;
	s=(n)*(n-1LL)/2LL + k*n; 
	ll l=1, r=n, p=(1LL+n)/2LL;
	
	auto f=[&](ll n) -> ll{
		return (n*(n-1LL))/2LL + k*n;
	};
	
	while (l<=r){
		ll mid = (l+r)/2;
		ll sL = f(mid), sR = s-sL;
		if (sL<=sR){
			p=mid;
			l=mid+1;
		} else r=mid-1;
	}
	
	ll a=f(p), b=f(p+1), ans=(ll)min(abs(a-(s-a)), abs(b-(s-b)));
	//cout<<"f "<<f(n)<<", a: "<<a<<", b: "<<b<<", p: "<<p<<'\n';
	return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	taskwithtestcase
}
