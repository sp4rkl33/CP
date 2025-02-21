#include <bits/stdc++.h>
#define ll long long
#define taskwithtestcase int t; cin>>t; while(t--){ cout<<(solve() ? "YES\n":"NO\n");}
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

class p{
	public:
		int l; int r;
		void s(int x, int y){
			l=x; r=y;
		}
		bool operator<(const p &o){
			return this->l==o.l ? (this->r<o.r):this->l<o.l;
		}
	
};

bool solve(){
	int n,ans=0; cin>>n;
	string s; cin>>s;
	vector<p> a(n);
	for(int i=0; i<n; i++){
		if (s[i]=='.') a[i].s(1,n);
		else if (s[i]=='p') a[i].s(1,i+1);
		else a[i].s(n-i, n);
	}
	for (int i=0; i<n; i++){
		cout<<a[i].l<<" "<<a[i].r<<'\n';
	}
	return ans==n;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    taskwithtestcase
}
