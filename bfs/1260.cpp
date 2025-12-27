#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,v;
vector<int> adj[1000+2];
bool visited[1001];

void dfs(int cur){
    cout<<cur<<" ";
    visited[cur] = true;

    for(int i=0; i<adj[cur].size(); i++){
        if(visited[adj[cur][i]]==false){
            dfs(adj[cur][i]);
        }
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start); 
    visited[start] = true;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout<<cur<<" ";
        for(int i=0; i<adj[cur].size(); i++){
            if(visited[adj[cur][i]]==false){
                visited[adj[cur][i]] = true;
                q.push(adj[cur][i]);
            }
        }
    }
}

int main(){
    cin>>n>>m>>v;
    
    int n1, n2;
    for(int i=0; i<m; i++){
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    
    for(int i=0; i<=n; i++){ sort(adj[i].begin(), adj[i].end()); }

    dfs(v);
    
    cout<<'\n';
    for(int i=0; i<=n; i++){ visited[i] = false; }
    
    bfs(v);
    return 0;
}