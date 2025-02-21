#include <algorithm> 
#include <iostream> 
#include <vector> 

using namespace std;

class ram{
	public:
		int u, a;
	bool operator<(const ram& obj) const{
		return u<obj.u;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,r;
		cin>>n>>r;
		vector<ram> a(n);
		for (int i=0; i<n; i++){
			cin>>a[i].u;
		}
		for (int i=0; i<n; i++){
			cin>>a[i].a;
		}
		sort(a.begin(), a.end());
		for (int i=0; i<n; i++){
			if (r>=a[i].u) r+=a[i].a;
		}
		cout<<r<<endl;
	}
	return 0;
}
