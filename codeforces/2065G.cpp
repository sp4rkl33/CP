#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}" << "\n";}
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

vector<bool> f(200007);
vector<int> g;
map<int, bool> pans;
void init(){
    int cnt = 0;
    for (int i = 2; i <= 200000; i++){
        if (f[i] == 0){
            g.emplace_back(i);
            for (int j = i*2; j <= 200000; j += i) f[j] = 1;
            cnt++;
        }
    }
    int n = g.size();
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            ll t = (ll)((ll)g[i] * (ll)g[j]);
            if (t > 200000LL) break;
            pans[g[i] * g[j]] = 1;
        }
    }
}

ll solve(){
    int n; cin >> n;
    map<int, int> mp;
    vector<int> a;
    ll ans = 0;
    for (; n > 0; n--){
        int x; cin >> x; 
        mp[x]++;
        if (f[x] == 0) a.emplace_back(x);
        if (pans[x]) ans++; 
    }
    n = a.size();
    for (int i = 0; i < n; i++){
        ans += (ll)((ll)(n - i - 1) * (ll)(n - i - 1 - mp[a[i]])); 
    }
    return ans;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init(); cout<<"done\n";
    retsolve
}

