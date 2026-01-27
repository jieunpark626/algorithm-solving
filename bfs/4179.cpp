#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int r,c;
char board[1002][1002];
bool visited[1002][1002];
bool fire_visited[1002][1002];
queue<pair<int,int>> q;
queue<pair<int,int>> fire_q;

bool in_range(int x, int y){
    return x>=0 && x<r && y>=0 && y<c;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>r>>c;
    string line;
    for(int i=0; i<r; i++){
        cin>>line;
        for(int j=0; j<c; j++){
            board[i][j] = line[j];
            if(board[i][j]=='J') {
                q.push({i,j});
                visited[i][j] = true;
            }
            else if(board[i][j]=='F') {
                fire_q.push({i,j});
                fire_visited[i][j] = true;
            }
        }
    }

    int cnt = 1;
    while(!q.empty()){
        // 1. 불 퍼뜨리기
        queue<pair<int,int>> tmp_fire_q;
        while(!fire_q.empty()){
            pair<int,int> fire_cur = fire_q.front(); fire_q.pop();
            int fx=fire_cur.first; int fy=fire_cur.second;
            
            for(int dir=0; dir<4; dir++){
                int fnx = fx+dx[dir]; int fny = fy+dy[dir];
                if(in_range(fnx,fny)&&fire_visited[fnx][fny]==false&&board[fnx][fny]!='#'){
                    board[fnx][fny] = 'F';
                    fire_visited[fnx][fny] = true;
                    tmp_fire_q.push({fnx,fny});
                }
            }
        }
        fire_q.swap(tmp_fire_q);
        
        queue<pair<int,int>> tmp_q;
        while(!q.empty()){
            pair<int,int> cur_loc = q.front(); q.pop();
            int cx = cur_loc.first; int cy = cur_loc.second;
            
            for(int dir=0; dir<4; dir++){
                int nx = cx+dx[dir]; int ny=cy+dy[dir];
                
                if(!in_range(nx,ny)){
                    cout<<cnt;
                    return 0;
                }else if(visited[nx][ny]==false&&board[nx][ny]=='.'){
                    visited[nx][ny] = true;
                    tmp_q.push({nx,ny});
                }
            }
        }
        q.swap(tmp_q);

        cnt++;
    }

    cout<<"IMPOSSIBLE";


    return 0;
}