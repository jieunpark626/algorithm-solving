#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,m;
int board[1000+3][1000+3];
queue<pair<int,int>> blanks;
bool visited[1000+3][1000+3];


void bfs(queue<pair<int,int>> q){
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        int cx = cur.first; int cy = cur.second;

        for(int i=0; i<4; i++){
            int nx=cx+dx[i]; int ny=cy+dy[i];
            if(nx<0) {nx=n+nx;} 
            if(ny<0) {ny=m+ny;}
            nx=(nx)%n; ny=(ny)%m;
            if(visited[nx][ny]==false && board[nx][ny]==0){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    int input;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>input;
            board[i][j]=input;
            if(input==0) blanks.push({i,j});
        }
    }
    int ans = 0;
    while(!blanks.empty()){
        pair<int,int> cur = blanks.front(); blanks.pop();
        if(visited[cur.first][cur.second]==true) continue;
        visited[cur.first][cur.second] = true;

        queue<pair<int,int>> tmp; tmp.push({cur.first,cur.second});
        ans++;
        //cout<<"cur "<<cur.first<<" "<<cur.second<<endl;
        bfs(tmp);
    }

    cout<<ans;

    return 0;
}