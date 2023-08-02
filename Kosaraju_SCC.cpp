#include <bits/stdc++.h>
using namespace std;
int N = 5e5+1;
vector<vector<int>> adj(N), rev_adj(N), res;
vector<int> temp;
int n, m;
stack<int> st;
vector<bool> vis(N, false);

void dfs(int node){
	vis[node] = true;
	for(auto &child: adj[node]){
		if(!vis[child]) dfs(child);
	}
	st.push(node);
}
void dfs2(int node){
	vis[node] = true;
	temp.push_back(node);
	for(auto &child : rev_adj[node]){
		if(!vis[child]) dfs2(child);
	}
}
void transpose(){
	for(int i=0; i<n; i++){
		for(auto &child : adj[i]){
			rev_adj[child].push_back(i);
		}
	}
}
void solve(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
    	int u, v; cin>>u>>v;
    	adj[u].push_back(v);
    }
    for(int i=0; i<n; i++){
    	if(!vis[i]){
    		dfs(i);
    	}
    }
    transpose();
    for(int i=0; i<n; i++){
    	vis[i] = false;
    }
    while(!st.empty()){
    	int vertex = st.top();
    	st.pop();
    	if(!vis[vertex]){
    		temp.clear();
    		dfs2(vertex);
    		res.push_back(temp);
    	}
    }
    cout<<res.size()<<"\n";
    for(auto &x : res){
    	cout<<x.size()<<" ";
    	for(auto &y : x){
    		cout<<y<<" ";
    	}
    	cout<<"\n";
    }
}
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms\n";
    return 0;
}
