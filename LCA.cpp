#include <bits/stdc++.h>
using namespace std;

void bfs(int source, vector<vector<int>> &g, vector<int> &vis, vector<int> &level, vector<int> &parent){
    queue<int> q;
    q.push(source); 
    vis[source] = 1;
    parent[source] = -1;
    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        for(auto &child: g[cur_v]){
            parent[child] = cur_v;
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    } 
}
int getKthAncestor(int node, int k, vector<vector<int>> &par){
    int var = 0;
    while(k){
        if(k&1){
            if(node==-1){
                return node;
            }
            node = par[node][var];
        }
        var++;
        k >>= 1;
    }
    return node;
}

int main(){
    int t;
    cin>>t;
    for(int c=1; c<=t; c++){
        int n;
        cin>>n;
        vector<vector<int>> g(n+1);
        vector<int> vis(n+1, 0), level(n+1, 0), parent(n+1);
        for(int i=1; i<=n; i++){
            int m;
            cin>>m;
            for(int j=1; j<=m; j++){
                int child;
                cin>>child;
                g[i].push_back(child);
            }
        }
        vector<int> temp_vis(n+1, 0);
        for(int i=1; i<=n; i++){
            for(int j=0; j<g[i].size(); j++){
                if(temp_vis[g[i][j]]==0){
                    temp_vis[g[i][j]] = 1;
                }
            }
        }
        int source;
        for(int i=1; i<=n; i++){
            if(temp_vis[i]==0){
                source = i;
                break;
            }
        }
        bfs(source, g, vis, level, parent);
        vector<vector<int>> par(n+1, vector<int>(22, -1));
        for(int i=1; i<=n; i++){
            par[i][0] = parent[i];
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<22; j++){
                if(par[i][j-1]!=-1){
                    par[i][j] = par[par[i][j-1]][j-1];
                }
            }
        }
        cout<<"Case "<<c<<":"<<"\n";
        int q;
        cin>>q;
        while(q--){
            int u, v;
            cin>>u>>v;
            if(level[u]!=level[v]){
                if(level[v]>level[u]){
                    swap(u, v);
                }
                int diff = level[u] - level[v];
                u = getKthAncestor(u, diff, par);
            }
            if(u==v){
                cout<<u<<"\n";
            }
            else{
                for(int i=21; i>=0; i--){
                    if(par[u][i]!=par[v][i]){
                        u = par[u][i];
                        v = par[v][i];
                    }
                }
                cout<<par[u][0]<<"\n";
            }
        }
    }
    return 0;
}