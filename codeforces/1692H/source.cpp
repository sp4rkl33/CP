#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define retsolve int t; cin>>t; while(t--){cout<<solve()<<'\n';}
#define voidsolve int t; cin>>t; while(t--){solve();}
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ss second
using namespace std;
using namespace __gnu_pbds;

template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;

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
    int n; cin >> n;
    map<int, vector<int>> mp;
    int t; cin >> t;
    mp[t].push_back(1);
    int cnt = 1, ansn = t, ansl = 1, ansr = 1;

    for (int i = 2; i <= n; i++){
        int x; cin >> x;
        mp[x].push_back(i);
    }

    for (auto it:mp){
        int tcnt = 1, tl = it.ss[0], tr = tl;
        for (int i = 1; i < (int)it.ss.size(); i++){
            tcnt += 2 - it.ss[i] + it.ss[i - 1]; 
            tr = it.ss[i];
            if (tcnt < 1){
                tcnt = 1;
                tl = tr;
            }
            if (tcnt > cnt){
                cnt = tcnt; ansn = it.ff; ansl = tl; ansr = tr; 
            }
        }
    }

    cout << ansn << ' ' << ansl << ' ' << ansr << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	  voidsolve
}
