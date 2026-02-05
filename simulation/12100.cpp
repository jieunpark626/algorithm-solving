#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int N;
int board[21][21];
vector<vector<int>> combi;

int cnt = 0;
void dfs(vector<int> dirs){
    if(dirs.size()==5){
        cnt++;
        combi.push_back(dirs);
        return;
    }

    for(int i=0; i<4; i++){
        dirs.push_back(i);
        dfs(dirs);
        dirs.pop_back();
    }
}

bool in_range(int x, int y){
    return x>=0 && x<N && y>=0 &&y<N;
}

//배열은 기본적으로 주소 값이 전달됨
void movefunc(int dir, int b[21][21]){

    for(int i=0; i<N; i++){
        vector<int> numbers;
        for(int j=0; j<N; j++){
            int r,c;
            if(dir==0) { r=j; c=i; }
            else if(dir==1) { r=i; c=N-1-j; }
            else if(dir==2) { r=N-1-j; c=i; }
            else if(dir==3) { r=i; c=j; }

            // 현재 체크하는 줄에서 0 빼고 숫자 가져오기
            if(b[r][c]!=0){
                numbers.push_back(b[r][c]);
                b[r][c] =0;
            }
        }

        vector<int> merged;
        for(int idx=0; idx<numbers.size(); idx++){
            if(idx+1<numbers.size() && numbers[idx] == numbers[idx+1]){
                merged.push_back(numbers[idx]*2);
                idx++;
            }else{
                merged.push_back(numbers[idx]);
            }
        }

        for(int j=0; j<merged.size(); j++){
            int r,c;

            if(dir==0) { r=j; c=i; }
            else if(dir==1) { r=i; c=N-1-j; }
            else if(dir==2) { r=N-1-j; c=i; }
            else if(dir==3) { r=i; c=j; }

            b[r][c] = merged[j];
        }
    }
}

int game(vector<int> dirs){
    int cur_board[21][21];
    memcpy(cur_board, board, sizeof(board));
    
    for(int dir: dirs){
        movefunc(dir, cur_board);
    }

    int max_num=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(max_num<cur_board[i][j]){ max_num = cur_board[i][j];}
        }
    }

    return max_num;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    int answer = 0;
    dfs({});
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
        }
    }
    
    for(vector<int> dirs: combi){
        int ret = game(dirs);
        if(answer<ret) answer = ret;
    }

    cout<<answer;
}
    
