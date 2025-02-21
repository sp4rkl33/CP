#include <bits/stdc++.h>

using namespace std;

int f(int n){
	return n<0?-n:n;
}

int main(){
	int a[11]={1, 6, 28, 120, 496, 2016, 8128, 32640, 130816, 523776, 2096128};
	int n,res=1;
	cin>>n;
	for (int i=1; i<11; i++){
		res = n%a[i]==0?a[i]:res;
	}
	cout << res << endl;
	return 0;
}
