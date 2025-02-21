#include <bits/stdc++.h>
#define ll long long
#define taskwithtestcase int t; cin>>t; while(t--){ cout<<solve();}
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

int dx[4]={0, 0, 1, -1};
int dy[4]={-1, 1, 0, 0};

int maxN=1e8+7;
//bool v[1000][1000][4][4];

struct p{
	public:
		int x; int y; int r; int t; int dist;
		void set(int a, int b, int c, int tt, int d){
			x=a; y=b; r=c; t=tt; dist=d;
		}
		bool operator>(const p &_) const{
			return this->dist == _.dist ? this->t > _.t:this->dist > _.dist;
		}
};

int solve(){
	int n,m; cin>>n>>m;
	int sx, sy, ex, ey;
	vector<vector<char>> g(n); vector<vector<vector<vector<int>>>> d(n);
	for(int i=0; i<n; i++){
		g[i].resize(m);
		d[i].resize(m);
		for (int j=0; j<m; j++){
			cin>>g[i][j];
			d[i][j].resize(4);
			for(int z=0; z<4; z++) d[i][j][z].resize(4, maxN);
			if (g[i][j]=='S'){
				sx=i; sy=j;
			}
			if (g[i][j]=='T'){
				ex=i; ey=j;
			}
		}
	}
	int ans=maxN;
	
	auto inn = [&](int x, int y) -> bool{
		return x>=0 && x<y;
	};
	auto dijkstra = [&]{
		priority_queue<p, vector<p>, greater<>> q;  q; p o; o.set(sx,sy,0,0,0);
		q.push(o);
		while (!q.empty()){
			auto [x,y,r,t,dd] = q.top(); q.pop();
			if (dd>=d[x][y][r][t]) continue;
			d[x][y][r][t]=dd;
			if (x==ex && y==ey){
				ans=min(ans, dd);
				continue;
			}
			for (int i=0; i<4; i++){
				int xx=x+dx[i], yy=y+dy[i];
				if (inn(xx,n) && inn(yy,m) && g[xx][yy]!='#') {
					p o; o.set(-99,0,0,0,0);
					if (i!=r && d[xx][yy][i][1] > dd+1) o.set(xx,yy,i,1,dd+1);
					else if (i==r && t<3 && d[xx][yy][i][t+1] > dd+1) o.set(xx,yy,i,t+1,dd+1);
					else if (i==r && t==3 && d[xx][yy][i][2] > dd+3) o.set(xx,yy,i,2,dd+3);
					if (o.x!=-99) q.push(o);
				}
			}
		}
	};
	dijkstra();
	return ans==maxN ? -1:ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<solve();
}
