#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <queue>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

vector<deque<char>> board;
bool visited[6][12];

void debug(){
    for(int i=0; i<6; i++){
        for(int j=0; j<12; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool in_range(int x, int y){
    return x>=0 && x<6 && y>=0 && y<12;
}

vector<pair<int,int>> bfs(queue<pair<int,int>>& q, char c){
    vector<pair<int,int>> ret;
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        ret.push_back(cur);
        
        for(int i=0; i<4; i++){
            int nx=cur.first+dx[i]; int ny=cur.second+dy[i];
            if(in_range(nx,ny)&&board[nx][ny]==c&&visited[nx][ny]==false){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    return ret;
}

int main(){
    board.assign(6,deque<char>(12,'.'));
    string line;
    for(int i=0; i<12; i++){
        cin>>line;
        for(int j=0; j<6; j++){
            board[j][11-i] = line[j];
        }
    }

    int ans = 0;
    while(true){
        bool change=false;
        for(int i=0; i<6; i++){
            for(int j=0; j<12; j++){
                visited[i][j] = false;
            }
        }

        for(int i=0; i<6; i++){
            for(int j=0; j<12; j++){
                if(!visited[i][j] && board[i][j]!='.'){
                    visited[i][j] = true;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vector<pair<int,int>> result = bfs(q,board[i][j]);
                    if(result.size()>=4){
                        change=true;
                        for(pair<int,int> loc: result){
                            board[loc.first][loc.second]='.';
                        }
                    }
                }
            }
        }

        if(change){
            for(int i=0; i<6; i++){
                deque<char> dq;
                int cnt = 0;
                for(int j=0; j<12; j++){
                    if(board[i][j]!='.') dq.push_back(board[i][j]);
                    else cnt++;
                }

                while(cnt--){
                    dq.push_back('.');
                }
                board[i] = dq;
                
            }
        }else{
            break;
        }
        ans++;
    }
    

    cout<<ans;
    return 0;
}