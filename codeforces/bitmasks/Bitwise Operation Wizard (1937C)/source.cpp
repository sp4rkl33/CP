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

char ask(int a, int b, int c, int d){
    char ans;
    cout << "? " << a << " " << b << " " << c << " " << d << '\n';
    cin >> ans;
    cout.flush();
    return ans;
}

void solve(){
    int n; cin >> n;

    //if n == 2 we only have to number so just output the answer.
    if (n == 2) {
        cout << "! 0 1" << '\n';
        return;
    }

    //finding the position of the largest number.
    int ki = 0; 
    for (int i = 1; i < n; i++){
        char resp = ask(ki, ki, i, i);
        if (resp == '<') ki = i;
    }

    //find every position that OR with a[ki] is maximize.
    vector<int> vt;
    int mx = 0;
    for (int i = 0; i < n; i++){
       char resp = ask(ki, mx, ki, i);
       if (resp == '<') {
           vt.clear();
           vt.emplace_back(i);
           mx = i;
       } else if (resp == '=') vt.emplace_back(i);
    }

    //find the minimum number among all the index in array vt.
    int kj = vt[0];
    for (int i = 1; i < (int)vt.size(); i++){
        char resp = ask(kj, kj, vt[i], vt[i]);
        if (resp == '>') kj = vt[i];
    }

    cout << "! " << ki << " " << kj << '\n';
}
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	voidsolve
}
