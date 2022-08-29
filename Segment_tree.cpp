#include <bits/stdc++.h>
using namespace std;

void createSegmentTree(vector<int> &a, vector<int> &segT, int low, int high, int posi){
	if(low==high){
		segT[posi] = a[low];
		return; 
	}
	int mid = (low+high)/2;
	createSegmentTree(a, segT, low, mid, 2*posi+1);
	createSegmentTree(a, segT, mid+1, high, 2*posi+2);
	segT[posi] += (segT[2*posi+1] + segT[2*posi+2]);
}

void changeValue(vector<int> &segT, vector<int> &a, int index, int value, int low, int high, int posi){
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

int rangeSumQuery(vector<int> &segT, int qlow, int qhigh, int low, int high, int posi){
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
	int n; cin>>n;
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
	vector<int> segT(sz, 0);
	createSegmentTree(a, segT, 0, n-1, 0);
	for(int i=0; i<sz; i++){
		cout<<segT[i]<<" ";
	}
	cout<<"\n";
	int q; cin>>q;
	while(q--){
		int idx, val, low, high;
		cin>>idx>>val>>low>>high;
		if(idx>=low && idx<=high){
			changeValue(segT, a, idx, val, 0, n-1, 0);
		}
		cout<<rangeSumQuery(segT, low, high, 0, n-1, 0)<<"\n";
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}