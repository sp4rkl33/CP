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

void solve(){
	int n; cin>>n;
	vector<int> a(n); vector<bool> v(n,0);
	for (int i=0; i<n; i++) cin>>a[i];
	
	int l=0, r=n-1, ali=0, bob=0, mov=0, resa=0, resb=0;
	
	if (n==1){
		cout<<1<<" "<<a[0]<<" "<<0<<'\n';
		return;
	}
	
	auto fali=[&](int &l) -> int{
		int sum=0;
		while (sum<=bob && !v[l]){
			sum+=a[l];
			v[l]=1;
			l++;
		}
		resa+=sum;
		return sum;
	};
	
	auto fbob=[&](int &r) -> int{
		int sum=0;
		while (sum<=ali && !v[r]){
			sum+=a[r];
			v[r]=1;
			r--;
		}
		resb+=sum;
		return sum;
	};
	
	while (!v[l] || !v[r]){
		if (mov%2==0) ali=fali(l);
		else bob=fbob(r);
		mov++;
	}
	
	cout<<mov<<" "<<resa<<" "<<resb<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	voidsolve
}
