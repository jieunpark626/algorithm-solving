#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;


int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,m;
char board[51][51];
bool visited[51][51];


void debug(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool in_range(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

int bfs(pair<int,int> start){
    queue<vector<int>> q;
    q.push({start.first, start.second, 0}); 
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = false;
        }
    }

    visited[start.first][start.second]=true;

    int ans=0;
    while(!q.empty()){
        vector<int> cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = cur[0]+dx[i]; int ny = cur[1]+dy[i];
            if(in_range(nx,ny)&&visited[nx][ny]==false){
                visited[nx][ny] = true;
                if(board[nx][ny] == 'L'){
                    q.push({nx,ny,cur[2]+1});
                    if(ans<cur[2]+1) ans = cur[2]+1;
                }
            }
        }
    }
    return ans;
}
int main(){
    cin>>n>>m;
    string line;
    for(int i=0; i<n; i++){
        cin>>line;
        for(int j=0; j<m; j++){
            board[i][j] = line[j];
        }
    }

    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='L'){
                int ret = bfs({i,j});
                if(ret>answer) answer = ret;
            }
        }
    }
    cout<<answer;
    return 0;
}