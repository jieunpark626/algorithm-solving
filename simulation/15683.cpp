#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = {-1,0,1,0}; //상 우 하 좌
int dy[] = {0,1,0,-1};
vector<vector<int>> cctv_dirs[7] =
{{{}},
 {{0},{1},{2},{3}}, // 1번 cctv
 {{0,2},{1,3}}, // 2번
 {{0,1},{1,2},{2,3},{3,0}}, // 3번
 {{0,1,2},{1,2,3},{2,3,0},{3,0,1}}, // 4번
 {{0,1,2,3}} // 5번
};

int N,M;
int board[9][9];
int cctv_cnt;
vector<int> cctv_nums;
vector<pair<int,int>> cctv_locs;
int answer = 10000;

bool in_range(int x, int y){
    return x>=0 && x<N && y>=0 && y<M;
}

int check(vector<vector<int>>& combi){
    int tmp_board[9][9]; 
    memcpy(tmp_board, board, sizeof(board));

    for(int i=0; i<combi.size(); i++){
        const vector<int>& dirs = combi[i];
        int cx = cctv_locs[i].first; int cy = cctv_locs[i].second;
        for(int dir: dirs){
            int nx = cx, ny = cy;
            while(true){
                nx += dx[dir]; ny += dy[dir];
                if(!in_range(nx,ny) || tmp_board[nx][ny] == 6) break;
                if(tmp_board[nx][ny] == 0) tmp_board[nx][ny] = 7;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tmp_board[i][j]==0) cnt++;
        }
    }
    return cnt;
}

void dfs(vector<vector<int>> combi, int idx){
    if(combi.size()==cctv_cnt){
        int cnt = check(combi);
        if(cnt<answer) answer = cnt;
        return;
    }
    for(const vector<int>& dir : cctv_dirs[cctv_nums[idx]]){
        combi.push_back(dir);
        dfs(combi, idx + 1); // 다음 CCTV로 이동
        combi.pop_back();
    }
}

int main(){


    // 입력
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j]>0 && board[i][j]<6){ 
                cctv_locs.push_back({i,j}); 
                cctv_nums.push_back(board[i][j]);
            }
        }
    }
    cctv_cnt=cctv_nums.size();
    vector<vector<int>> v;
    dfs(v,0);
    cout<<answer;
    return 0;
}