#include <iostream>
#include <queue>

using namespace std;

struct compare{
    bool operator()(pair<int,int> &p1, pair<int,int> &p2){
        return p1.second > p2.second;
    }
};

int n,k;

priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
bool visited[100000*2+1];

int main(){
    cin>>n>>k;

    pq.push({n,0}); // 위치, cnt

    while(!pq.empty()){
        pair<int,int> cur=pq.top(); pq.pop();

        if(cur.first==k){
            cout<<cur.second; return 0;
        }
        visited[cur.first]=true;
        
        if(cur.first+1<=k && visited[cur.first+1]!=true) {
            pq.push({cur.first+1, cur.second+1});
        }
        if(cur.first-1>=0 && visited[cur.first-1]!=true){
            pq.push({cur.first-1, cur.second+1});
        }
        if(cur.first*2<k*2 && visited[cur.first*2]!=true){
            pq.push({cur.first*2, cur.second});
        }
    }

    return 0;

}