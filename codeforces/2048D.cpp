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

bool op(int a, int b){
	return a>b;
}

int solve(){
	int n,m; cin>>n>>m;
	vector<int> a(1), b(m), c(m);
	cin>>a[0];
	int kel=a[0], kelR;
	for (int i=1; i<n; i++) {
		int x; cin>>x; 
		if (x<=a[0]) continue;
		a.push_back(x);
	}
	int kS=a[0], kR;
	sort(a.begin(), a.end(), op);
	for (int i=0; i<m; i++) cin>>b[i];
	
	auto bs = [&](auto self, int t) -> int{
		int l=0, r=a.size()-1, res=-1;
		while (l<=r){
			int mid=(l+r)/2;
			if (a[mid]>=t){
				l=mid+1;
				res=mid;
			} else r=mid-1;
		}
		return res;
	};
	
	auto bs2 = [&](auto self, int t) -> int{
		int l=0, r=a.size()-1, res=0;
		while (l<=r){
			int mid = (l+r)/2;
			if (a[mid]<=t){
				res=mid;
				r=mid-1;
			} else l=mid+1;
		}
		return res;
	};
	
	kR = bs2(bs2,kS)+1;
	for (int i=0; i<m; i++){
		int p=bs(bs, b[i]);
		c[i]= p==-1 || p>=kR-1?0:p+1;
	}
	sort(c.begin(), c.end());

	for (int k=1; k<=m; k++){
		ll s=0;
		for (int ki=k-1; ki<m; ki+=k) s += (ll)c[ki]+1LL;
		cout<<s<<" ";
	}
	cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	taskwithtestcase
}
