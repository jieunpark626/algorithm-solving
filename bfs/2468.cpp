#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n;
int board[101][101];
int max_height=0;
bool visited[101][101];

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
}

bool in_range(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void bfs(pair<int,int> start, int rain){
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.first+dx[i]; int ny = cur.second+dy[i];
            if(in_range(nx,ny)&&visited[nx][ny]==false){
                visited[nx][ny]=true;
                if(board[nx][ny]>rain){
                    q.push({nx,ny});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;

    //input
    int input;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>input;
            board[i][j] = input;
            if(max_height<input) max_height=input;
        }
    }

    int answer = 0;
    for(int rain=0; rain<=max_height; rain++){
        init();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]>rain && visited[i][j]==false){
                    bfs({i,j},rain);
                    cnt++;
                }
            }
        }
        if(answer<cnt) answer = cnt;
    }

    cout<<answer;
    return 0;
}