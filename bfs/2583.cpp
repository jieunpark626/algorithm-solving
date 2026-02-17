#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int m,n,k;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<int> sizes;

bool in_range(int x, int y){
    return x>=0 && x<m && y>=0 && y<n;
}

void bfs(queue<pair<int,int>>& q){
    int sz = 0;
    while (!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        sz++;
        for(int i=0; i<4; i++){
            int nx=cur.first+dx[i]; int ny=cur.second+dy[i];
            if(in_range(nx,ny)&&visited[nx][ny]==false){
                visited[nx][ny] = true;
                if(board[nx][ny]==0) q.push({nx,ny});
            }
        }
    }
    sizes.push_back(sz);
}

int main(){
    cin>>m>>n>>k;
    board.assign(m, vector<int>(n,0));
    visited.assign(m, vector<bool>(n,false));
    int lx, ly, rx, ry;
    for(int i=0; i<k; i++){
        cin>>lx>>ly>>rx>>ry;
        for(int r=ly; r<ry; r++){
            for(int c=lx; c<rx; c++){
                board[r][c] = 1;
            }
        }
    }

    queue<pair<int,int>> q;

    int cnt = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]==false){
                visited[i][j] = true;
                if(board[i][j]==0){
                    q.push({i,j});
                    bfs(q);
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<"\n";
    sort(sizes.begin(), sizes.end());
    for(int sz: sizes){
        cout<<sz<<" ";
    }
    return 0;
}