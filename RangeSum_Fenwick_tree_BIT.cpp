#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void update(int idx, int val, vector<ll> &bit){
	for(int i=idx; i<=bit.size(); i += (i&-i)){
		bit[i] += val;
	}
}
ll rangeSum(int idx, vector<ll> &bit){
	ll ans = 0;
	for(int i=idx; i>0; i -= (i&-i)){
		ans += bit[i];
	}
	return ans;
}
void solve(){
	int n, q; cin>>n>>q;
	vector<int> a(n);
	vector<ll> bit(n+10);
	for(int i=0; i<n; i++){
		cin>>a[i];
		update(i+1, a[i], bit);
	}
	while(q--){
		int type; cin>>type;
		if(type==1){
			int k, u;
			cin>>k>>u;
			update(k, u-a[k-1], bit);
			a[k-1] = u;
		}
		else{
			int a, b; cin>>a>>b;
			cout<<rangeSum(b, bit)-rangeSum(a-1, bit)<<"\n";
		}
	}
}
int main(){
	solve();
	/*int t; cin>>t;
	while(t--){
		solve();
	}*/
	return 0;
}
