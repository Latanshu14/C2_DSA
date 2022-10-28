#include <bits/stdc++.h>
using namespace std;
 
void createSegmentTree(vector<int> &a, vector<long long int> &segT, int low, int high, int posi){
	if(low==high){
		segT[posi] = a[low];
		return; 
	}
	int mid = (low+high)/2;
	createSegmentTree(a, segT, low, mid, 2*posi+1);
	createSegmentTree(a, segT, mid+1, high, 2*posi+2);
	segT[posi] += (segT[2*posi+1] + segT[2*posi+2]);
}
 
void changeValue(vector<long long int> &segT, vector<int> &a, int index, int value, int low, int high, int posi){
	if(index>=low && index<=high){
		segT[posi] += (value - a[index]);
		if(low==high && low==index){
			return;
		}
	}
	else return;
	int mid = (low+high)/2;
	changeValue(segT, a, index, value, low, mid, 2*posi+1);
	changeValue(segT, a, index, value, mid+1, high, 2*posi+2);
}
 
long long int rangeSumQuery(vector<long long int> &segT, int qlow, int qhigh, int low, int high, int posi){
	// TOTAL OVERLAP
	if(low>=qlow && high<=qhigh){
		return segT[posi];
	}
	// NO OVERLAP
	if(qlow>high || qhigh<low){
		return 0;
	}
	int mid = (low+high)/2;
	return (rangeSumQuery(segT, qlow, qhigh, low, mid, 2*posi+1) + rangeSumQuery(segT, qlow, qhigh, mid+1, high, 2*posi+2));
}
 
void solve(){
	int n, q; cin>>n>>q;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int sz;
	if(n&1){
		sz = 1;
		while(sz<n) sz <<= 1;
		sz *= 2;
		sz--;
	}
	else{
		sz = 4*n-1;
	}
	vector<long long int> segT(sz, 0);
	createSegmentTree(a, segT, 0, n-1, 0);
	while(q--){
		int type; cin>>type;
		if(type==1){
			int k, u; cin>>k>>u;
			changeValue(segT, a, k-1, u, 0, n-1, 0);
			a[k-1] = u;
		}
		else{
			int low, high;
			cin>>low>>high;
			cout<<rangeSumQuery(segT, low-1, high-1, 0, n-1, 0)<<"\n";
		}
	}
}
 
int main(){
	solve();
	/*int t; cin>>t;
	while(t--){
		solve();
	}
*/	return 0;
}
