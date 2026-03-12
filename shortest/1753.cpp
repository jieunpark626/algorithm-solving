#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare{
    bool operator()(pair<int,int> &p1, pair<int,int> &p2 ){
        return p1.second > p2.second;
    }
};

int v,e,s;
vector<pair<int,int>> adj[20000+3];
int dist[20000+3];
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>v>>e>>s;

    int u,v2,w;
    for(int i=0; i<e; i++){
        cin>>u>>v2>>w;
        adj[u].push_back({v2,w});
    }

    for(int i=0; i<=v; i++){
        dist[i]=987654321;
    }

    dist[s]=0;
    pq.push({s,0});


    while(!pq.empty()){
        pair<int,int> cur=pq.top(); pq.pop();

        for(pair<int,int> item: adj[cur.first]){
            int node=item.first;
            int cost=item.second;

            if(dist[node]>cur.second+cost){
                dist[node]=cur.second+cost;
                pq.push({node, dist[node]});
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(dist[i]==987654321) cout<<"INF"<<'\n';
        else cout<<dist[i]<<'\n';
    }
    return 0;
}