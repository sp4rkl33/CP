#include <bits/stdc++.h>

using namespace std;

bool solve(int *a, int *b, int k){
	if (k==6){
		int f=0, s=0, fn=0 ,sn=0;
		for (int i=0; i<6; i++){
			if (b[i]==1){
				s+=a[i];
				sn++;	
			}
			else{
				f+=a[i];
				fn++;	
			}
		}
		return fn==sn && f==s;
	} else {
		for (int i=0; i<=1; i++){
			b[k]=i;
			bool flag=solve(a, b, k+1);
			if (flag) return true;
		}
	}
	return false;
}

int main(){
	int a[6], bit[6]={0,0,0,0,0,0};
	for (int i=0; i<6; i++){
		cin>>a[i];
	}
	puts(solve(a,bit,0) ? "YES\n":"NO\n");
	return 0;
}
