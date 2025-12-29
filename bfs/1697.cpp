#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200000;
bool visited[MAX+1];

void bfs(int start, int dest){
    queue<pair<int,int>> q;
    q.push({start,0}); visited[start] = true;

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        int cur_num = cur.first;
        int cur_cnt = cur.second;
        
        if(cur_num==dest){
            cout<<cur_cnt;
            return;
        }

        if(cur_num-1>=0 && visited[cur_num-1]==false){
            visited[cur_num-1] = true; q.push({cur_num-1, cur_cnt+1});
        }
        if(cur_num+1<=MAX && visited[cur_num+1]==false){
            visited[cur_num+1] = true; q.push({cur_num+1, cur_cnt+1});
        }
        if(cur_num*2<=MAX && visited[cur_num*2]==false){
            visited[cur_num*2] = true; q.push({cur_num*2, cur_cnt+1});
        }
    }

}

int main(){
    int s,d;
    cin>>s>>d;
    bfs(s,d);
    return 0;
}