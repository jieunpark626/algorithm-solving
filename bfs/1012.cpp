#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,m,k;
int board[51][51];
bool visited[51][51];

bool in_range(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs(queue<pair<int,int>>& q){
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx=cur.first+dx[i]; int ny=cur.second+dy[i];
            if(in_range(nx,ny)&&visited[nx][ny]==false){
                visited[nx][ny] = true;
                if(board[nx][ny]==1) q.push({nx,ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        cin>>m>>n>>k;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                board[i][j] = 0; visited[i][j] = false;
            }
        }
        int r,c;
        while(k--){
            cin>>c>>r;
            board[r][c] = 1;
        }

        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                if(visited[i][j]==false){
                    visited[i][j] = true;
                    if(board[i][j]==1){
                        cnt++;
                        q.push({i,j}); bfs(q);
                    }
                }
            }
        }

        cout<<cnt<<"\n";
    }
    return 0;
}