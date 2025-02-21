#include <bits/stdc++.h>
#define ll long long
#define taskwithtestcase int t; cin>>t; while(t--){solve();}
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
	int x; cin>>x;
	return x;
}

void solve(){
	int n; cin>>n;
	int p=ask(1,2);
	string ans(n,'0');
	ans[1]='1';
	if (p==0) {
		cout<<"! IMPOSSIBLE\n";
		return;
	} else {
		int l=1;
		for (int i=3; i<=n; i++){
			int rn = ask(l,i);
			if (rn>p) ans[i-1]='1';
			else {
				l=i;
				ans[i-1]='0';
			}
		}
		cout<<"! "<<ans<<'\n';
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	taskwithtestcase
}
