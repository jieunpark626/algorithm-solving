#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct ret{
    queue<pair<int,int>> new_q;
    bool possible;
};

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,m;
char board[1001][1001];

bool fire_visited[1001][1001];
bool visited[1001][1001];
queue<pair<int,int>> fire;
queue<pair<int,int>> me;

void init(){
    while(!fire.empty()){ fire.pop();}
    while(!me.empty()){ me.pop();}
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = false; 
            fire_visited[i][j] = false;
        }
    }
}

bool in_range(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

ret bfs(queue<pair<int,int>> q, char c, bool (&cur_visited)[1001][1001]){
    queue<pair<int,int>> ret_q;

    bool poss = false;

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        cur_visited[cur.first][cur.second] = true;
        for(int i=0; i<4; i++){
            int nx = cur.first+dx[i]; int ny = cur.second+dy[i];
            if(!in_range(nx,ny)){ // 탈출 성공
                if(c=='@'){ 
                    poss=true; break;
                }
            }

            if(cur_visited[nx][ny] == false){
                cur_visited[nx][ny] = true;
                if(board[nx][ny]=='.' || board[nx][ny]=='@'){
                    board[nx][ny] = c;
                    ret_q.push({nx,ny});
                }
            }
        }
    }

    return ret{ret_q,poss};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);  
    int tc;
    cin>>tc;

    for(int T=0; T<tc; T++){
        // input
        cin>>m>>n;
        init();
        string line;
        for(int i=0; i<n; i++){
            cin>>line;
            for(int j=0; j<m; j++){
                char c = line[j];
                board[i][j]=c;
                if(c=='@'){ me.push({i,j}); }
                else if(c=='*'){ fire.push({i,j}); }
            }
        }

        int cnt = 0;
        while(true){
            cnt++;
            //불 퍼뜨리기
            ret result = bfs(fire, '*', fire_visited);
            fire = result.new_q;

            //이동하기
            result = bfs(me, '@', visited);
            if(result.possible == true){
                cout<<cnt<<"\n"; break;
            }else if(result.new_q.empty()){
                cout<<"IMPOSSIBLE\n"; break;
            }
            me = result.new_q;
        }
        
    }
    return 0;
}