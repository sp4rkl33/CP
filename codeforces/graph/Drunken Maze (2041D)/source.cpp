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

struct node{
    public:
        int x; int y; int cnt; int dir; int dis;
        node(int x, int y, int cnt, int dir, int dis) : x(x), y(y), cnt(cnt), dir(dir), dis(dis) {}
        bool operator>(const node &_){
            return this -> dis == _.dis ? this -> cnt > _.cnt : this -> dis > _.dis;
        }
};

int maxN = 1e9 + 8;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
            if (g[i][j] == 'S'){
                sx = i;
                sy = j;
            }
            if (g[i][j] == 'T'){
                ex = i;
                ey = j;
            }
        }
    }

    //distance array d[x][y][dir] mean shortest distance from S to position 
    vector<vector<vector<int>>> d(n + 1, vector<vector<int>>(m + 1, vector<int>(4, maxN)));

    //Modify dijkstra algorithm.	
    priority_queue<node, vector<node>, greater<>> pq;
    pq.emplace(sx, sy, 0, -1, 0);
    while (!pq.empty()){
        auto [x, y, cnt, dir, dis] = pq.top(); pq.pop();
        if (dir != -1 && dis >= d[x][y][dir]) continue;
        if (dir != -1) d[x][y][dir] = dis;
        for (int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if (g[xx][yy] == '#') continue;
            if (i == dir){
                if (cnt == 3) pq.emplace(xx, yy, 2, i, dis + 3);
                else pq.emplace(xx, yy, cnt + 1, i, dis + 1);
            } else pq.emplace(xx, yy, 1, i, dis + 1);
        }
    }
        
    int ans = maxN;
    for (int it:d[ex][ey]) ans = min(ans, it);
    return ans == maxN ? -1 : ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	  cout << solve();
}
