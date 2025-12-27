#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct element{
    pair<int, int> loc;
    bool breaked;
    int time;
};

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,m;
int board[1001][1001];
bool visited[1001][1001][2];
bool in_range(int x, int y){ 
    return x>=0 && x<n && y>=0 && y<m; 
}

void bfs(){
    queue<element> q;
    
    q.push({{0,0},false,1});
    visited[0][0][0] = true;
    while(!q.empty()){
        element cur = q.front(); q.pop();
        int cx = cur.loc.first; int cy = cur.loc.second;

        if(cx==n-1&&cy==m-1){
            cout<<cur.time;
            return;
        }

        for(int i=0; i<4; i++){
            int nx=cx+dx[i]; int ny=cy+dy[i];
            if(!in_range(nx,ny)) continue;
            if(board[nx][ny]==0 && !visited[nx][ny][cur.breaked]){
                visited[nx][ny][cur.breaked] = true;
                q.push({{nx,ny},cur.breaked, cur.time+1});
            }

            if (board[nx][ny] == 1 && cur.breaked == 0 && !visited[nx][ny][1]) {
                visited[nx][ny][1] = true;
                q.push({{nx, ny}, 1, cur.time + 1});
            }
        }
    }
    cout<<"-1";
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string line;
        cin>>line;
        for(int j=0; j<m; j++){
            board[i][j] = line[j]-'0';
        }
    }
    bfs();

    return 0;
}