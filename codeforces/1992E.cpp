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

vector<vector<pair<int ,int>>> f(107);
vector<map<int, int>> save;

void init(){
    for (int i = 1; i <= 100; i++){
        string s = to_string(i);
        map<int, int> mp;
        string b = to_string(i), cur = "";
        for (int i = 0; i <= 6; i++){
            cur += b[i % b.length()];
            mp[stoi(cur)]++;
        }
        save.emplace_back(mp);
    }
    auto it = save[9];
    for (int n = 1; n <= 100; n++){
        int le = n < 10 ? 1 : n < 100 ? 2 : 3;
        map<int, int> mp = save[n-1];
        for (int a = 1; a <= 10000; a++){
            int mx = le * a;
            int l = mx - 1, r = mx - 6 <= 0 ? 1 : mx - 6;
            // cout << a << " " << mx << " " << l << '\n';
            for (int b = l; b >= r; b--){
                int tans = n * a - b;  
                int c = to_string(tans).length();
                // cout << "tans, b: " << tans << ", " << b << " spe: " << c << '\n';
                if (mp[tans] == 1 && c == mx - b) f[n].emplace_back(make_pair(a, b));
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    cout << (int)f[n].size() << '\n';
    for (auto it:f[n]) cout << it.ff << " " << it.ss << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    voidsolve
}

