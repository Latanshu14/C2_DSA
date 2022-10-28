// constraints:
// n → 1e5
// a[i] → 1e9

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
	int n; cin>>n;
	vector<int> a(n);
	map<int, int> mp;
	for(int i=0; i<n; i++){
		cin>>a[i];
		mp[a[i]];
	}
	int cnt = 1;
	for(auto &x : mp){
		x.second = cnt;
		cnt++;
	}
	for(int i=0; i<n; i++){
		a[i] = mp[a[i]];
	}
	int inversion_cnt = 0;
	vector<ll> bit(mp.size()+1);
	for(int i=0; i<n; i++){
		inversion_cnt += (rangeSum(mp.size(), bit)-rangeSum(a[i], bit));
		update(a[i], 1, bit);
	}
	cout<<inversion_cnt<<"\n";
}
int main(){
	solve();
	/*int t; cin>>t;
	while(t--){
		solve();
	}*/
	return 0;
}
