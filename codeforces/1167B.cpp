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

int ask(int x, int y){
	cout<<"? "<<x+1<<" "<<y+1<<'\n';
	int p; cin>>p;
	return p;
}

int p[6]={4, 8, 15, 16, 23, 42};

void swap(int &x, int &y){
	int z=x;
	x=y;
	y=z;
}

bool f(int x){
	for(int i:p) if (x==i) return 1;
	return 0;
}

int solve(){
	int n=6; vector<int> ans(6);
	auto dos=[&](int k){
		int s=ask(k,k+1);
		int x,y;
		for (int i:p) if (s%i==0 && f(s/i)){
			x=i; y=s/i;
			break;
		}
		s=ask(k, k+2);
		if (s%x!=0 || !f(s/x) || s/x==x) swap(x,y);
		int z=s/x;
		ans[k]=x; ans[k+1]=y; ans[k+2]=z;
	};
	dos(0); dos(3);
	cout<<"! ";
	for (int i:ans) cout<<i<<" "; 
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}
