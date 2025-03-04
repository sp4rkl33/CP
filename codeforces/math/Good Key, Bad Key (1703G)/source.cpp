#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define retsolve int t; cin>>t; while(t--){cout<<solve()<<'\n';}
#define voidsolve int t; cin>>t; while(t--){solve();}
#define ff first
#define ss second
using namespace std;
using namespace __gnu_pbds;

template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
template <class type1>
using ordered_set = tree <type1, null_type, less <type1>, rb_tree_tag, tree_order_statistics_node_update>;

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

ll f[31];

void init(){
	f[0]=1;
	for (int i=1; i<31; i++) f[i] = f[i-1] * 2;
}

ll solve(){
    int n; ll k; cin >> n >> k;
    vector<ll> sum(n), a(n); 
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum[i] = i > 0 ? sum[i - 1] + a[i] : a[i]; //conduct a prefix sum for used good keys calculatiom
    }

    //build suffix table
    vector<vector<ll>> bad(n, vector<ll>(30));
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < 30; j++){
            bad[i][j] = a[i] / f[j + 1];
            if (i == n - 1) continue;
            bad[i][j] += bad[i + 1][min(29, j + 1)];
        }
    }

    ll ans = bad[0][0]; //if use all bad keys
    for (int i = 0; i < n - 1; i++)
        ans = max(ans, sum[i] - (i + 1) * k + bad[i + 1][0]);
    
    return max(ans, sum[n - 1] - (k * n)); //remember to check if we use all good keys
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	retsolve;
}
