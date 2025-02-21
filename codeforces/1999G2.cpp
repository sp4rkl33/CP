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

int ask(int l, int r){
	cout<<"? "<<l<<" "<<r<<'\n';
	int s; cin>>s;
	return s;
}

void solve(){
	int l=2, r=999;
	while (r-l>2){
		int a = (2*l + r)/3, b = (2*r + l)/3;
		int res = ask(a, b);
		if (res == (a+1)*(b+1)) r=a;
		else if (res == a*b) l=b;
		else {
			l=a, r=b;
		}
	}
	if (r-l==2) r--;
	int res = ask(l,r), ans;
	if (res == (l+1)*(r+1)) ans=l;
	else if (res == l*r) ans=r+1;
	else ans=r;
	cout<<"! "<<ans<<'\n';
}

int main(){
	voidsolve
}
