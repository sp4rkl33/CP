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

string solve(){
    int n, m; cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    vector<int> b(m);
    for (auto &it:b) cin >> it;
    sort(b.begin(), b.end());
    for (int it:b){
        if (mp[it] > 0){
            mp[it]--;
            n--;
            continue;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(it / 2); pq.push(it / 2 + it % 2);
        int k = 2;
        while (!pq.empty() && k <= n){
            int p = pq.top(); pq.pop();
            if (mp[p] > 0){
                mp[p]--;
                k--;
                n--;
            } else {
                pq.push(p / 2); pq.push(p / 2 + p % 2);
                k++;
            }
        }
        if (k > 0) return "NO";
    }
    return n == 0 ? "YES":"NO";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	retsolve
}

